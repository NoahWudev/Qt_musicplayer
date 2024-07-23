#include "audiomodel.h"

AudioModel::AudioModel(QObject *parent)
    : QObject(parent)
{
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
}

void AudioModel::setSource(const QString &source)
{
    player->setSource(QUrl::fromLocalFile(source));
}

void AudioModel::play()
{
    player->play();
}

void AudioModel::pause()
{
    player->pause();
}

void AudioModel::stop()
{
    player->stop();
}
