#ifndef LILSING_MODEL_MUSICPLAYER_H_
#define LILSING_MODEL_MUSICPLAYER_H_

#include <QDialog>
#include <QMediaPlayer>

class MusicPlayer : public QDialog {
 public:
    MusicPlayer();
    ~MusicPlayer();

    void playMusic(int songIndex = -1);
    void skipSong();
    void lowerVolume();
    void louderVolume();
    void play_pause();
    void changeSliderValue(int pos);

 private:
    QMediaPlayer* _player;
    QMediaPlaylist* _playlist;
    int _volume;
};

#endif  // LILSING_MODEL_MUSICPLAYER_H_
