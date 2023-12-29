#include "frame.h"

cv::Mat Frame::getRawFrame() const
{
    return rawFrame;
}

void Frame::setRawFrame(const cv::Mat &newRawFrame)
{
    rawFrame = newRawFrame;
}

QImage Frame::getFrame() const
{
    return frame;
}

void Frame::setFrame(const QImage &newFrame)
{
    frame = newFrame;
}

/**
 * @brief Converts the raw frame from RGB to BGR color space and updates the 'frame' property.
 *
 * This function performs the following steps:
 * 1. Converts the rawFrame from RGB to BGR using OpenCV.
 * 2. Creates a QImage from the resulting OpenCV Mat.
 * 3. Assigns the QImage to the 'frame' property of the Frame class.
 * 4. Detaches the QImage to ensure it has its own copy of pixel data.
 * 5. Triggers an update for repainting the Frame.
 * 6. Emits the frameChanged signal to notify external components about the change.
 */
void Frame::convert2QImage()
{
    cv::Mat tempMat;
        //This function changes input image from one color space to another (RGB to BGR in this case)
    cv::cvtColor(rawFrame, tempMat, cv::COLOR_RGB2BGR);
        //This object takes data from cv Mat, and stores insidte the QImage
    QImage tempImage((uchar*)tempMat.data, tempMat.cols, tempMat.rows, tempMat.step, QImage::Format_RGB888);

    frame = tempImage;
        //Detach the QImage from the shared data, ensuring it has its own deep copy of the pixel data
    frame.detach();
    frame.detach();
    Frame::update();
    emit(frameChanged());
}


Frame::Frame(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

void Frame::paint(QPainter *parent)
{

}
