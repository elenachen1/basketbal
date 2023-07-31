#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>

class MyLabel : public QLabel
{
    Q_OBJECT

public slots:
    void updateWindow();
    void clearWindow();


public:
    explicit MyLabel(QWidget *parent = nullptr);

    void setCirclePosition(QPoint position);
    void setStartPosition(QPoint position);
    void setCircleRadius(int radius);
    QPoint m_circlePosition;
    QPoint circlePosition;


protected:

    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    //void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QLabel *m_label;
    int m_circleRadius;

    bool m_isDrawing;
    QVector<QPoint> m_linePoints;
    QPushButton *m_updateButton; // Кнопка обновления
    QPushButton *m_clearButton; // Кнопка очистки

};

#endif // MYLABEL_H
