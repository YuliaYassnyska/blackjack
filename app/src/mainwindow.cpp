#include "mainwindow.h"
#include "gameScene/gamescene.h"
#include "items/cards/digitCard/digitcard.h"
#include "mainView/mainview.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _view{ new MainView(this) }, _scene{ new GameScene(this) }
{
    initWindow();
    auto item{ new DigitCard("2", ":/images/suit/resources/spades.svg",
                             ":/images/backSide/resources/black_back_side.jpg") };
    _scene->addItem(item);
    item->moveBy(_scene->width() / 3, _scene->height() / 3);
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
