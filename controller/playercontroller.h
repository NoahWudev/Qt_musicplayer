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

    void onProgressChanged(int percentage);
    void updateViewProgress(qint64 position);
    void updateViewDuration(qint64 duration);

private:
    AudioModel *model;
    PlayerView *view;
    qint64 currentDuration;
};

#endif // PLAYERCONTROLLER_H
