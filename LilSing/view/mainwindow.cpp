#include "mainwindow.h"
#include "model/musicplayer.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _musicPlayer = new MusicPlayer();
    qDebug() << "Started";

    _skipSongButton = new QPushButton("Skip song");

    //addWidget(_skipSongButton);
    setCentralWidget(_skipSongButton);

    setWindowTitle("Lil'Sing");
    resize(400,200);

    connect(_skipSongButton, SIGNAL(clicked()), this, SLOT(skipSongButtonClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::skipSongButtonClicked()
{
    _musicPlayer->skipSong();
}

