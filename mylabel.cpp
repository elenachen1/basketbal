#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

    m_isDrawing = false;
    // Создание кнопок
    m_updateButton = new QPushButton("Обновить", this);


    // Установка позиции кнопок
    m_updateButton->move(10, 10);


    // Связывание кнопок с соответствующими слотами
    connect(m_updateButton, &QPushButton::clicked, this, &MyLabel::updateWindow);



}

void MyLabel::setCirclePosition(QPoint position)
{
    m_circlePosition = position;
}

void MyLabel::setStartPosition(QPoint position)
{
    circlePosition = position;
}

void MyLabel::setCircleRadius(int radius)
{
    m_circleRadius = radius;
}

void MyLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::green);
    painter.drawEllipse(m_circlePosition.x() - m_circleRadius, m_circlePosition.y() - m_circleRadius, m_circleRadius * 2, m_circleRadius * 2);

    painter.setPen(Qt::black);
    if (m_isDrawing && m_linePoints.size() >= 5) {
        painter.drawPolyline(m_linePoints.data(), m_linePoints.size());
    }
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {

            // Проверка, находится ли курсор внутри круга
            if ((event->pos() - m_circlePosition).manhattanLength() <= m_circleRadius) {
                m_circlePosition = event->pos();
                if (m_isDrawing) {
                    m_linePoints.append(event->pos());



                       // Создаем трансформацию, чтобы изменить систему координат
                       QTransform transform;
                       // Сдвигаем начало координат в центр
                       transform.translate(circlePosition.x(), circlePosition.y());
                       // Масштабируем координаты по обоим осям
                       transform.scale(1, -1);

                       qDebug() << "Contents of QVector<QPoint> in transformed coordinates:";

                       for (int i = 0; i < m_linePoints.size(); ++i) {
                           QPoint point = m_linePoints.at(i);
                           // Применяем трансформацию к каждой точке
                           QPoint transformedPoint = transform.map(point);
                           qDebug() << "Transformed Point" << i + 1 << ": (" << transformedPoint.x() << ", " << transformedPoint.y() << ")";
                       }


//                    qDebug() << "Contents of QVector<QPoint>:";

//                       for (int i = 0; i < m_linePoints.size(); ++i) {
//                           QPoint point = m_linePoints.at(i);
//                           qDebug() << "Point" << i + 1 << ": (" << point.x() << ", " << point.y() << ")";
//                       }
                    update(); // Перерисовка окна
                }
                update(); // Перерисовка окна
            }

    }


    if (event->buttons() & Qt::RightButton) {
            // Проверка, находится ли курсор внутри круга
            if ((event->pos() - m_circlePosition).manhattanLength() <= m_circleRadius) {
                m_circlePosition = event->pos();
                update(); // Перерисовка окна
            }

    }

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDrawing = true;
        //m_linePoints.clear();
        m_linePoints.append(event->pos());
        update(); // Перерисовка окна
    }
}

void MyLabel::updateWindow() {
    setCirclePosition(circlePosition);
    m_linePoints.clear(); // Очистка списка точек линии
    update(); // Перерисовка окна
}



