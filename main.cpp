#include "mainwindow.h"
#include "mylabel.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect poleGeom;



    poleGeom = w.getPoleGeometry();
    QPoint position = QPoint(poleGeom.width()/2, poleGeom.height()/2);
    MyLabel label(&w);

    label.setGeometry(poleGeom.x(), poleGeom.y(), poleGeom.width(), poleGeom.height());
    label.setCirclePosition(QPoint(label.width()/2, label.height()/2));
    label.setCircleRadius(10);
    label.setStartPosition(position);





    w.show();
    label.show();



    return a.exec();
}
