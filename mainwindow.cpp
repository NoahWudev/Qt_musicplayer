#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    model = new AudioModel(this);
    view = new PlayerView(this);
    controller = new PlayerController(model, view, this);

    setWindowTitle("Mp3 player");
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}
