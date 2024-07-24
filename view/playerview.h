#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <QSlider>

class PlayerView : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerView(QWidget *parent = nullptr);
    void updateFileName(const QString &fileName);

    void updateProgress(qint64 position, qint64 duration);
    void setDuration(qint64 duration);

signals:
    void playClicked();
    void pauseClicked();
    void stopClicked();
    void fileSelected(const QString &filePath);

    void progressChanged(int position);

private slots:
    void onOpenFileClicked();

    void onSliderMoved(int position);

private:
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *openFileButton;
    QLabel *fileNameLabel;

    // slider
    QSlider *progressSlider;
    QLabel *timeLabel;
};

#endif // PLAYERVIEW_H
