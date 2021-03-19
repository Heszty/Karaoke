#include "musicplayer.h"

#include <QMediaPlaylist>

MusicPlayer::MusicPlayer()
{
    _player = new QMediaPlayer(this);
    volume = 5;
    playMusic();
}

void MusicPlayer::playMusic()
{
    QMediaPlaylist* playlist = new QMediaPlaylist();
    //playlist->addMedia();
}
