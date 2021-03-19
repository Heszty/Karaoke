#include "mainwindow.h"
#include "model/musicplayer.h"
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _musicPlayer = new MusicPlayer();
    qDebug() << "Started";



    QWidget * wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
    _skipSongButton = new QPushButton("Skip song");
    _skipSongButton->resize(height()/3, width());
    _volumeDown = new QPushButton("Vol-");
    _volumeDown->resize(height()/3, width());
    _volumeUp = new QPushButton("Vol+");
    _volumeUp->resize(height()/3, width());
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

