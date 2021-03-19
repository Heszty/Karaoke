#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QDialog>
#include <QMediaPlayer>

class MusicPlayer : public QDialog
{
public:
    MusicPlayer();

    void playMusic(int songIndex = -1);
    void skipSong();

private:
    QMediaPlayer* _player;
    QMediaPlaylist* _playlist;
    int volume;
};

#endif // MUSICPLAYER_H
