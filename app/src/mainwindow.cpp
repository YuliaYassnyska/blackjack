#include "mainwindow.h"
#include "gameScene/gamescene.h"
#include "items/cardItem/carditem.h"
#include "mainView/mainview.h"

#include <QGraphicsPixmapItem>
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
    setMinimumSize(750, 500);
    _view->setScene(_scene);
    setCentralWidget(_view);
    _scene->setSceneRect(rect());
    QPixmap pixmap{ QPixmap{ ":/images/background/resources/grass.jpg" }.scaled(size()) };
    _scene->setBackgroundBrush(pixmap);
}
