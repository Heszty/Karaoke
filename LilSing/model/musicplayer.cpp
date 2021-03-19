#include "musicplayer.h"

#include <QMediaPlaylist>
#include <QDebug>

MusicPlayer::MusicPlayer()
{
    _player = new QMediaPlayer(this);
    volume = 8;
    _player->setVolume(volume);
    playMusic();
}

void MusicPlayer::playMusic()
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song1.mp3"));
    playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song2.mp3"));
    playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song3.mp3"));
    playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song4.mp3"));
    playlist->shuffle();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    _player->setPlaylist(playlist);
    _player->play();
}

