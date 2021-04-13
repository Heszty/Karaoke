#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QDialog>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QVector>
#include <QMediaPlaylist>

class VideoPlayer : public QDialog
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();
    void play_pause();
    void changeSliderValue(int pos);

private:
    QMediaPlayer* _player;
    QVideoWidget* _videoWidget;
    QMediaPlaylist* _playList;
};

#endif // VIDEOPLAYER_H
