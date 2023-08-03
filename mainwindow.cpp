#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>



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

    // Получаем исходный размер изображения
    int originalWidth = pixmap.width();
    int originalHeight = pixmap.height();

    // Устанавливаем начальные значения ширины и высоты
    int newWidth = originalWidth;
    int newHeight = originalHeight;

    // Вычисляем коэффициенты масштабирования
    float widthScaleFactor = float(width()) / originalWidth;
    float heightScaleFactor = float(height()) / originalHeight;

    // Выбираем минимальный коэффициент масштабирования
    float scaleFactor = qMin(widthScaleFactor, heightScaleFactor);

    // Масштабируем размеры изображения
    newWidth *= scaleFactor;
    newHeight *= scaleFactor;

    // Устанавливаем новый размер изображения
    ui->pole->setGeometry((width() - newWidth) / 2, (height() - newHeight) / 2, newWidth, newHeight);

    setMouseTracking(true); // Включение отслеживания движения мыши



}

//масштабирование картинки относительно экрана
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    // Получаем новый размер окна
    QSize newSize = event->size();

    // Получаем текущий размер изображения
    int currentWidth = ui->pole->width();
    int currentHeight = ui->pole->height();

    // Вычисляем коэффициенты масштабирования
    float widthScaleFactor = float(newSize.width()) / currentWidth;
    float heightScaleFactor = float(newSize.height()) / currentHeight;

    // Выбираем минимальный коэффициент масштабирования
    float scaleFactor = qMin(widthScaleFactor, heightScaleFactor);

    // Масштабируем размеры изображения
    int newWidth = int(currentWidth * scaleFactor/float(1.5));
    int newHeight = int(currentHeight * scaleFactor/float(1.5));

    // Устанавливаем новый размер изображения
    ui->pole->setGeometry((newSize.width() - newWidth) / 2, (newSize.height() - newHeight) / 2, newWidth, newHeight);
}


// проверка на изменение размера экрана
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
QRect MainWindow::getPoleGeometry()
{
    return ui->pole->geometry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLabel *MainWindow::getLabel()
{
    return pole;
}
