#pragma once

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow();

    void initWindow();

private:
    QGraphicsView *_view{ nullptr };
    QGraphicsScene *_scene{ nullptr };
};
