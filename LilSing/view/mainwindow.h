#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>

#include <model/musicplayer.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MusicPlayer* _musicPlayer;
    QPushButton* _skipSongButton;

public slots:
    void skipSongButtonClicked();

};
#endif // MAINWINDOW_H
