#include "musicplayer.h"
#include "videoplayer.h"

#include <QMediaPlaylist>
#include <QDebug>

MusicPlayer::MusicPlayer()
{
    _player = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist();

    _volume = 8;
    _player->setVolume(_volume);

    playMusic();
}

MusicPlayer::~MusicPlayer()
{
    delete _player;
    delete _playlist;
}

void MusicPlayer::playMusic(int songIndex)
{
    if(songIndex <= 0)
    {//plays all the songs in random order
        _playlist->clear();
        _playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song1.mp3"));
        _playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song2.mp3"));
        _playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song3.mp3"));
        _playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song4.mp3"));

        _playlist->shuffle();
        _playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else
    {
        _playlist->clear();
        _playlist->addMedia(QUrl("https://people.inf.elte.hu/wb9alh/songs/song" + QString::number(songIndex) + ".mp3"));
    }
    _player->setPlaylist(_playlist);
    _player->play();
}

void MusicPlayer::skipSong()
{
    _playlist->next();
}

void MusicPlayer::lowerVolume()
{
    _player->setVolume(--_volume);
}

void MusicPlayer::louderVolume()
{
    _player->setVolume(++_volume);
}

void MusicPlayer::play_pause()
{
    if(_player->state() == 1){
        _player->pause();
    } else {
        _player->play();
    }
}

void MusicPlayer::changeSliderValue(int pos)
{
    double tmp = (_player->duration() / 100.0) * pos;
    _player->setPosition(tmp);
}

