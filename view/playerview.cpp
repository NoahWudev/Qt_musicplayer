#include "playerview.h"

PlayerView::PlayerView(QWidget *parent) : QWidget(parent)
{
    // basic functions
    playButton = new QPushButton("Play", this);
    pauseButton = new QPushButton("Pause", this);
    stopButton = new QPushButton("Stop", this);
    openFileButton = new QPushButton("Open File", this);

    fileNameLabel = new QLabel("No file selected", this);
    // time slider functions
    progressSlider = new QSlider(Qt::Horizontal, this);
    progressSlider->setRange(0, 1000);  // using percentage
    timeLabel = new QLabel("00:00 / 00:00", this);

    QHBoxLayout *progressLayout = new QHBoxLayout();
    progressLayout->addWidget(progressSlider);
    progressLayout->addWidget(timeLabel);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(openFileButton);
    layout->addWidget(fileNameLabel);
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(stopButton);
    layout->addLayout(progressLayout);

    setLayout(layout);

    connect(playButton, &QPushButton::clicked, this, &PlayerView::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &PlayerView::pauseClicked);
    connect(stopButton, &QPushButton::clicked, this, &PlayerView::stopClicked);
    connect(openFileButton, &QPushButton::clicked, this, &PlayerView::onOpenFileClicked);
    connect(progressSlider, &QSlider::sliderMoved, this, &PlayerView::onSliderMoved);
}

void PlayerView::onOpenFileClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Audio File", "", "Audio Files (*.mp3 *.wav)");
    if (!filePath.isEmpty()) {
        emit fileSelected(filePath);
    }
}

void PlayerView::updateFileName(const QString &fileName)
{
    fileNameLabel->setText("Current file: " + fileName);
}

void PlayerView::updateProgress(qint64 position, qint64 duration)
{
    if (duration > 0) {
        int value = static_cast<int>((position * 1000) / duration);
        progressSlider->setValue(value);
    }

    QTime currentTime((position / 3600000) % 60, (position / 60000) % 60, (position / 1000) % 60);
    QTime totalTime((duration / 3600000) % 60, (duration / 60000) % 60, (duration / 1000) % 60);
    QString format = "mm:ss";
    timeLabel->setText(currentTime.toString(format) + " / " + totalTime.toString(format));
}

void PlayerView::onSliderMoved(int position)
{
    emit progressChanged(position);
}
