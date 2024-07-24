#include "playercontroller.h"

PlayerController::PlayerController(AudioModel *model, PlayerView *view, QObject *parent)
    : QObject(parent), model(model), view(view), currentDuration(0)
{
    connect(view, &PlayerView::playClicked, this, &PlayerController::onPlayClicked);
    connect(view, &PlayerView::pauseClicked, this, &PlayerController::onPauseClicked);
    connect(view, &PlayerView::stopClicked, this, &PlayerController::onStopClicked);
    connect(view, &PlayerView::fileSelected, this, &PlayerController::onFileSelected);

    connect(view, &PlayerView::progressChanged, this, &PlayerController::onProgressChanged);
    connect(model, &AudioModel::positionChanged, this, &PlayerController::updateViewProgress);
    connect(model, &AudioModel::durationChanged, this, &PlayerController::updateViewDuration);
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

    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    view->updateFileName(fileName);
}

void PlayerController::onProgressChanged(int position)
{
    model->setPosition(position);
}

void PlayerController::updateViewProgress(qint64 position)
{
    view->updateProgress(position, currentDuration);
}

void PlayerController::updateViewDuration(qint64 duration)
{
    currentDuration = duration;
    view->setDuration(duration);
    view->updateProgress(model->position(), duration);
}
