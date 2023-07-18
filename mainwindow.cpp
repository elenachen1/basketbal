#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QResizeEvent>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pole->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->pole->setPixmap(QPixmap(":/img/img/pole_0.png"));
    ui->pole->setScaledContents(true); // Включаем масштабирование содержимого


}




//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    QMainWindow::resizeEvent(event);

//    // Получаем новый размер окна
//    QSize newSize = event->size();

//    // Масштабируем текущую картинку в QLabel
//    QPixmap scaledPixmap = ui->pole->pixmap()->scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

//    // Устанавливаем масштабированную картинку в QLabel
//    ui->pole->setPixmap(scaledPixmap);
//}


void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event); // Вызвать базовую реализацию resizeEvent

    // Обновить размеры и положение QLabel
    int labelWidth = width() / 2; // Пример: установить ширину QLabel в половину ширины виджета
    int labelHeight = height() / 2; // Пример: установить высоту QLabel в половину высоты виджета
    int labelX = (width() - labelWidth) / 2; // Пример: установить положение QLabel по центру по горизонтали
    int labelY = (height() - labelHeight) / 2; // Пример: установить положение QLabel по центру по вертикали

    ui->pole->setGeometry(labelX, labelY, labelWidth, labelHeight);
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
        QMainWindow::changeEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}




