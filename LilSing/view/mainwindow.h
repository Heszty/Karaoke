#ifndef LILSING_VIEW_MAINWINDOW_H_
#define LILSING_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QSlider>
#include <QCoreApplication>

#include <model/musicplayer.h>
#include <model/videoplayer.h>
#include <model/sqlhandler.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private:
    // ------------------------------music/videoplayer--------------------------------------

    MusicPlayer* _musicPlayer;
    VideoPlayer* _videoPlayer;
    QPushButton* _skipSongButton;
    QPushButton* _volumeDown;
    QPushButton* _volumeUp;
    QPushButton* _play_stop;
    QSlider* _slider;

    // ----------------------------------database-------------------------------------------

    Sqlhandler* _sqlHandler;
    QPushButton* _showDb;
    const QString _dbPath = QCoreApplication::applicationDirPath() + "/../../LilSing/saves/database/songs.db";

    // -------------------------------------------------------------------------------------

    QWidget* wdg;
    QVBoxLayout* vlay;

 public slots:
    void skipSongButtonClicked();
    void volumeDownButtonClicked();
    void volumeUpButtonClicked();
    void playButtonClicked();
    void sliderValueChanged();
    void showDbButtonClicked();
};
#endif  // LILSING_VIEW_MAINWINDOW_H_
