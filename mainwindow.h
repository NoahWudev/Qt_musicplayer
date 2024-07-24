#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <model/audiomodel.h>
#include <view/playerview.h>
#include <controller/playercontroller.h>

/*QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    AudioModel *model;
    PlayerView *view;
    PlayerController *controller;
};

#endif // MAINWINDOW_H
