#include "videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QDialog(parent)
{
    _player = new QMediaPlayer;
    _videoWidget = new QVideoWidget;

    _player->setVideoOutput(_videoWidget);
    // _player->setMedia(QUrl("https://people.inf.elte.hu/wb9alh/videos/video1.mp4"));
    _player->setMedia(QUrl("https://people.inf.elte.hu/wb9alh/videos/video2.avi"));

    _videoWidget->setGeometry(100, 100, 400, 400);
    _videoWidget->show();

    _player->play();

    qDebug() << "State: " << _player->state();
}

VideoPlayer::~VideoPlayer()
{
    delete _player;
    delete _playList;
}

