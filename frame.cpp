#include "frame.h"

cv::Mat Frame::getRawFrame() const
{
    return rawFrame;
}

void Frame::setRawFrame(const cv::Mat &newRawFrame)
{
    rawFrame = newRawFrame;
    convert2QImage();
}

QImage Frame::getFrame() const
{
    return frame;
}

void Frame::setFrame(const QImage &newFrame)
{
    frame = newFrame;
    Frame::update();
    emit(frameChanged());
}

void Frame::openImage(QString url)
{
    qDebug() << "Test: Attempting to open image: 1" << url;
    url.remove("file://");
    qDebug() << "Test: Attempting to open image: 2" << url;
    rawFrame = cv::imread(url.toStdString());
    qDebug() << "Test: Attempting to open image: 3" << url;
    convert2QImage();
    qDebug() << "Test: Attempting to open image: 4" << url;
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
    Frame::update();
    emit(frameChanged());
}


Frame::Frame(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

/**
 * @brief Paint the scaled version of the frame onto the provided QPainter.
 *
 * This function performs the following steps:
 * 1. Creates a scaled version of the frame image with a size of 640x480 pixels.
 * 2. Draws the entire scaled image onto the specified QPainter at the top-left corner (0, 0).
 * 3. Uses fast image transformation and automatic color conversion during drawing.
 *
 * @param parent The QPainter to paint on.
 */
void Frame::paint(QPainter *parent)
{
    QImage scaledFrame;
    //scales the frame, with valid image data
    scaledFrame = frame.scaled(640, 480, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    //redraws the new image onto the oainter from (scaledFrame) with automatic color
    parent->drawImage(0,0,scaledFrame, 0, 0, -1, -1, Qt::AutoColor);
}
