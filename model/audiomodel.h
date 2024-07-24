#ifndef AUDIOMODEL_H
#define AUDIOMODEL_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>

class AudioModel : public QObject
{
    Q_OBJECT
public:
    explicit AudioModel(QObject *parent = nullptr);

    void checkAvailableBackends();
    void setSource(const QString &source);
    void play();
    void pause();
    void stop();

    qint64 position() const;
    qint64 duration() const;

    void setPosition(qint64 position);

signals:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // AUDIOMODEL_H
