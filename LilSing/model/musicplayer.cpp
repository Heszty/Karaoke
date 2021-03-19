#include "musicplayer.h"

#include <QMediaPlaylist>
#include <QDebug>

MusicPlayer::MusicPlayer()
{
    _player = new QMediaPlayer(this);
    volume = 2;
    _player->setVolume(6);
    playMusic();
}

void MusicPlayer::playMusic()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile("songs/song1.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("songs/song2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("songs/song3.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("songs/song4.mp3"));
    playlist->shuffle();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    _player->setPlaylist(playlist);
    _player->play();
}

