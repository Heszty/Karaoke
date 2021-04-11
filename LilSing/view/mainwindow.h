#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QSlider>

#include <model/musicplayer.h>
#include <model/videoplayer.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MusicPlayer* _musicPlayer;
    VideoPlayer* _videoPlayer;
    QPushButton* _skipSongButton;
    QPushButton* _volumeDown;
    QPushButton* _volumeUp;
    QPushButton* _play_stop;
    QSlider* _slider;

    QWidget* wdg;
    QVBoxLayout *vlay;

public slots:
    void skipSongButtonClicked();
    void volumeDownButtonClicked();
    void volumeUpButtonClicked();
    void playButtonClicked();
    void sliderValueChanged();

};
#endif // MAINWINDOW_H
