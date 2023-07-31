#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;
    void changeEvent(QEvent *event) override;



public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    QLabel *getLabel() const;


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPoint circlePosition;
    int circleRadius;
    bool m_drawing;
    QLabel *pole;


};

#endif // MAINWINDOW_H
