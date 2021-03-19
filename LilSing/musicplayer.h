#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QDialog>
#include <QMediaPlayer>

class MusicPlayer : public QDialog
{
public:
    MusicPlayer();

private:
    QMediaPlayer* _player;
    int volume;

    void playMusic();
};

#endif // MUSICPLAYER_H
