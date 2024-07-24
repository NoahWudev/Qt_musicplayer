#include "audiomodel.h"

AudioModel::AudioModel(QObject *parent)
    : QObject(parent)
{
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    connect(player, &QMediaPlayer::positionChanged, this, &AudioModel::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &AudioModel::durationChanged);
}

void AudioModel::setSource(const QString &source)
{
    player->setSource(QUrl::fromLocalFile(source));
    // durationChanged sinals
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

qint64 AudioModel::position() const
{
    return player->position();
}

qint64 AudioModel::duration() const
{
    return player->duration();
}

void AudioModel::setPosition(qint64 position)
{
    player->setPosition(position);
}
