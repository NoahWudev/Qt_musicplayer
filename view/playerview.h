#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>

class PlayerView : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerView(QWidget *parent = nullptr);

signals:
    void playClicked();
    void pauseClicked();
    void stopClicked();
    void fileSelected(const QString &filePath);

private slots:
    void onOpenFileClicked();

private:
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *openFileButton;
};

#endif // PLAYERVIEW_H
