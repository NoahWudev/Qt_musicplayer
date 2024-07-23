#ifndef AUDIOMODEL_H
#define AUDIOMODEL_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class AudioModel : public QObject
{
    Q_OBJECT
public:
    explicit AudioModel(QObject *parent = nullptr);

    void setSource(const QString &source);
    void play();
    void pause();
    void stop();

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // AUDIOMODEL_H
