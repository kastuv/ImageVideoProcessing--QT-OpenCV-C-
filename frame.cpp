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

void Frame::convert2QImage()
{

}

Frame::Frame(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

void Frame::paint(QPainter *parent)
{

}
