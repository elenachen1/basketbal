#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QResizeEvent>
#include <QtCore/qmap.h>


float iw ;
float ih ;
float ik ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/img/img/pole_0.png");
    ui->pole->setPixmap(pixmap);

    ui->centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->pole->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->pole->setScaledContents(true); // Включаем масштабирование содержимого
    iw = ui->pole->pixmap()->width();
    ih = ui->pole->pixmap()->height();
    ik = float(iw) / float(ih);





}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    // Получаем новый размер окна
    QSize newSize = event->size();

    ik = float(iw) / float(ih);

    float ww = newSize.width();
    float wh = newSize.height();
    float wk = float(ww) / float(wh);



    if (wk >= ik)
    {
        ih = wh;
        iw = float(ik * ih);
    }
    else if(wk < ik)
    {
        iw = ww;
        ih = float(iw / ik);
    }




    ui->pole->setScaledContents(true);
    ui->pole->setGeometry(150, 20, int(iw),int(ih));
}







void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        QWindowStateChangeEvent *stateChangeEvent = static_cast<QWindowStateChangeEvent*>(event);
        if (stateChangeEvent->oldState() & Qt::WindowMaximized && windowState() & Qt::WindowFullScreen)
        {
            QSize newSize = size();

            QResizeEvent resizeEvent(newSize, newSize);
            QMainWindow::resizeEvent(&resizeEvent);

        }
    }
    event->ignore();
}

MainWindow::~MainWindow()
{
    delete ui;
}





