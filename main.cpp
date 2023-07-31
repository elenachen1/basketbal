#include "mainwindow.h"
#include "mylabel.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;




    QPoint position = QPoint(w.width()/2, w.height()/2);
    MyLabel label(&w);
    label.setGeometry(w.x(), w.y(), w.width(), w.height());
    label.setCirclePosition(QPoint(label.width()/2, label.height()/2));
    label.setCircleRadius(10);
    label.setStartPosition(position);





    w.show();
    label.show();



    return a.exec();
}
