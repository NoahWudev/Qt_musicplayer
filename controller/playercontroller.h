#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include "../model/audiomodel.h"
#include "../view/playerview.h"

class PlayerController : public QObject
{
    Q_OBJECT
public:
    explicit PlayerController(AudioModel *model, PlayerView *view, QObject *parent = nullptr);

public slots:
    void onPlayClicked();
    void onPauseClicked();
    void onStopClicked();
    void onFileSelected(const QString &filePath);

private:
    AudioModel *model;
    PlayerView *view;
};

#endif // PLAYERCONTROLLER_H
