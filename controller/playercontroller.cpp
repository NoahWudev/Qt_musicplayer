#include "playercontroller.h"

PlayerController::PlayerController(AudioModel *model, PlayerView *view, QObject *parent)
    : QObject(parent), model(model), view(view)
{
    connect(view, &PlayerView::playClicked, this, &PlayerController::onPlayClicked);
    connect(view, &PlayerView::pauseClicked, this, &PlayerController::onPauseClicked);
    connect(view, &PlayerView::stopClicked, this, &PlayerController::onStopClicked);
    connect(view, &PlayerView::fileSelected, this, &PlayerController::onFileSelected);
}

void PlayerController::onPlayClicked()
{
    model->play();
}

void PlayerController::onPauseClicked()
{
    model->pause();
}

void PlayerController::onStopClicked()
{
    model->stop();
}

void PlayerController::onFileSelected(const QString &filePath)
{
    model->setSource(filePath);
}
