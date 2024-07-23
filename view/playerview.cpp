#include "playerview.h"

PlayerView::PlayerView(QWidget *parent) : QWidget(parent)
{
    playButton = new QPushButton("Play", this);
    pauseButton = new QPushButton("Pause", this);
    stopButton = new QPushButton("Stop", this);
    openFileButton = new QPushButton("Open File", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(openFileButton);
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(stopButton);

    setLayout(layout);

    connect(playButton, &QPushButton::clicked, this, &PlayerView::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &PlayerView::pauseClicked);
    connect(stopButton, &QPushButton::clicked, this, &PlayerView::stopClicked);
    connect(openFileButton, &QPushButton::clicked, this, &PlayerView::onOpenFileClicked);
}

void PlayerView::onOpenFileClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Audio File", "", "Audio Files (*.mp3 *.wav)");
    if (!filePath.isEmpty()) {
        emit fileSelected(filePath);
    }
}
