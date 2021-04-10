#include "mainwindow.h"
#include "model/musicplayer.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _musicPlayer = new MusicPlayer();
    qDebug() << "Started";



    wdg = new QWidget(this);
    vlay = new QVBoxLayout(wdg);
    _skipSongButton = new QPushButton("Skip song");
    _volumeDown = new QPushButton("Vol-");
    _volumeUp = new QPushButton("Vol+");
    vlay->addWidget(_volumeDown);
    vlay->addWidget(_skipSongButton);
    vlay->addWidget(_volumeUp);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    setWindowTitle("Lil'Sing");
    setMinimumHeight(200);
    setMinimumWidth(400);
    //resize(400,200);

    connect(_skipSongButton, SIGNAL(clicked()), this, SLOT(skipSongButtonClicked()));
    connect(_volumeDown, SIGNAL(clicked()), this, SLOT(volumeDownButtonClicked()));
    connect(_volumeUp, SIGNAL(clicked()), this, SLOT(volumeUpButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete _musicPlayer;
    delete wdg;
    delete vlay;
    delete _skipSongButton;
    delete _volumeDown;
    delete _volumeUp;
}

void MainWindow::skipSongButtonClicked()
{
    _musicPlayer->skipSong();
}

void MainWindow::volumeDownButtonClicked()
{
    _musicPlayer->lowerVolume();
}

void MainWindow::volumeUpButtonClicked()
{
    _musicPlayer->louderVolume();
}

