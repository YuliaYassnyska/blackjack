#include "mainwindow.h"
#include "gameScene/controller/scenecontroller.h"
#include "gameScene/gamescene.h"
#include "items/cardItem/cardItem.h"
#include "mainView/mainview.h"
#include "model/controller/modelcontroller.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _view{ new MainView(this) },
      _scene{ new GameScene(this) },
      _modelController{ new ModelController() }
{
    initWindow();

    _sceneController = new SceneController(_scene, _modelController, Theme::Light);
}

MainWindow::~MainWindow()
{
    delete _modelController;
    delete _sceneController;
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
