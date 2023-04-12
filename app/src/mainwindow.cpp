#include "mainwindow.h"
#include "gameScene/gamescene.h"
#include "mainView/mainview.h"

#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _view{ new MainView(this) }, _scene{ new GameScene(this) }
{
    initWindow();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initWindow()
{
    setWindowTitle(QStringLiteral("blackjack"));
    setFixedSize(750, 500);
    _view->setScene(_scene);
    setCentralWidget(_view);
}
