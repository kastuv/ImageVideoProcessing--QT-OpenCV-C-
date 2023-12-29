#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

//opencv resources - include in CMakeLists.txt file
#include "opencv2/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

                     //added to make Frame inherit from QQUickPaintedItem class
class Frame : public QQuickPaintedItem //child class Frame
{
    Q_OBJECT

    cv::Mat rawFrame; //raw matrix value in the object variable
    QImage frame;     //processed matrix value "

public:
    Frame(QQuickItem *parent = 0); //Constructor for Frame Class (Where 0 is the default parameter, if no parameter is give it will be nullptr)
            //This is a pointer to a QQuickItem object
    void paint(QPainter *parent);
        //This is a pointer to a QPainter object
    cv::Mat getRawFrame() const;
    void setRawFrame(const cv::Mat &newRawFrame);

    QImage getFrame() const;
    void setFrame(const QImage &newFrame);


signals:
    void frameChanged(); // This signal is emited when line-20 frame is updated
    //you always declare signal but you never define it!
public slots:
    void convert2QImage();

};

#endif // FRAME_H
