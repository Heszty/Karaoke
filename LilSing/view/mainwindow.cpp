#include "mainwindow.h"
#include "model/musicplayer.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _musicPlayer = new MusicPlayer();
    qDebug() << "Starts";
}

MainWindow::~MainWindow()
{
}

