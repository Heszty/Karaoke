#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <model/musicplayer.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MusicPlayer* _musicPlayer;
};
#endif // MAINWINDOW_H
