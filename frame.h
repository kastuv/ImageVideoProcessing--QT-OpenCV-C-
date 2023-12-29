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
    /*
     * using Q_PROPERTY enhances the integration of your C++ classes with the Qt framework,
     * making it easier to leverage Qt's powerful features. While it's not strictly mandatory,
     * its usage provides a more seamless and integrated development experience
     */
    Q_PROPERTY(QImage Frame READ getFrame WRITE setFrame NOTIFY frameChanged)

    cv::Mat rawFrame; //raw matrix value in the object variable
    QImage frame;     //processed matrix value "

public:
            //This is a pointer to a QQuickItem object
    Frame(QQuickItem *parent = 0); //Constructor for Frame Class (Where 0 is the default parameter, if no parameter is give it will be nullptr)
           //This is a pointer to a QPainter object
    void paint(QPainter *parent);


    cv::Mat getRawFrame() const;
    //Q_INVOKABLE to call it in QML
    Q_INVOKABLE void setRawFrame(const cv::Mat &newRawFrame);

    QImage getFrame() const;
    void setFrame(const QImage &newFrame);

    Q_INVOKABLE void openImage(QString url);
signals:
    void frameChanged(); // This signal is emited when line-20 frame is updated
    //you always declare signal but you never define it!
public slots:
    void convert2QImage();

};

#endif // FRAME_H
