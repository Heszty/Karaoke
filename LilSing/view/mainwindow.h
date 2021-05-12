#ifndef LILSING_VIEW_MAINWINDOW_H_
#define LILSING_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QSlider>
#include <QCoreApplication>
#include <QDockWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QMediaRecorder>
#include <QDir>
#include <QDirIterator>

#include <model/musicplayer.h>
#include <model/videoplayer.h>
#include <model/sqlhandler.h>
#include <model/recorder.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private:
    // ------------------------------music/videoplayer--------------------------------------

    MusicPlayer* _musicPlayer;
    VideoPlayer* _videoPlayer;
    Recorder* _recorder;
    QPushButton* _skipSongButton;
    QPushButton* _volumeDown;
    QPushButton* _volumeUp;
    QPushButton* _play_stop;
    QPushButton* _start_recording;
    QPushButton* _stop_recording;
    QSlider* _slider;

    // ----------------------------------database-------------------------------------------

    Sqlhandler* _sqlHandler;
    QPushButton* _showDb;
    QPushButton* _listSongs;
    QPushButton* _selectList;
    QGridLayout* _songLayout;
    QDockWidget* _songList;

    QVector<song_struct> _songs;
    song_struct _song;
    QString title;
    QString album;
    QString artist;
    QString link;

    const QString _dbPath = QCoreApplication::applicationDirPath() + "/../../../Karaoke/LilSing/saves/database/songs.db";

    // -------------------------------------------------------------------------------------

    QWidget* wdg;
    QVBoxLayout* vlay;

 signals:
    void linkBtnClicked();

 public slots:
    void skipSongButtonClicked();
    void volumeDownButtonClicked();
    void volumeUpButtonClicked();
    void playButtonClicked();
    void sliderValueChanged();
    void showDbButtonClicked();
    void listSongsBtnClicked();
    void songElementClicked();
    void recordButtonClicked();
    void stopRecordButtonClicked();
};
#endif  // LILSING_VIEW_MAINWINDOW_H_
