#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QDialog>
#include <QMediaPlayer>

class MusicPlayer : public QDialog
{
public:
    MusicPlayer();
    ~MusicPlayer();

    void playMusic(int songIndex = -1);
    void skipSong();
    void lowerVolume();
    void louderVolume();

private:
    QMediaPlayer* _player;
    QMediaPlaylist* _playlist;
    int _volume;
};

#endif // MUSICPLAYER_H
