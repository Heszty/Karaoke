#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    _musicPlayer = new MusicPlayer;
    _videoPlayer = new VideoPlayer;
    qDebug() << "Started";



    wdg = new QWidget(this);
    vlay = new QVBoxLayout(wdg);
    _skipSongButton = new QPushButton("Skip song");
    _volumeDown = new QPushButton("Vol-");
    _volumeUp = new QPushButton("Vol+");
    _play_stop = new QPushButton("Pause, Play");
    _slider = new QSlider(Qt::Horizontal);


    vlay->addWidget(_volumeDown);
    vlay->addWidget(_skipSongButton);
    vlay->addWidget(_volumeUp);
    vlay->addWidget(_play_stop);
    vlay->addWidget(_slider);

    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    setWindowTitle("Lil'Sing");
    setMinimumHeight(200);
    setMinimumWidth(400);

    connect(_skipSongButton, SIGNAL(clicked()),
            this, SLOT(skipSongButtonClicked()));

    connect(_volumeDown, SIGNAL(clicked()),
            this, SLOT(volumeDownButtonClicked()));

    connect(_volumeUp, SIGNAL(clicked()),
            this, SLOT(volumeUpButtonClicked()));

    connect(_play_stop, SIGNAL(clicked()),
            this, SLOT(playButtonClicked()));

    connect(_slider, SIGNAL(sliderReleased()),
            this, SLOT(sliderValueChanged()));
}

MainWindow::~MainWindow() {
    delete _musicPlayer;
    delete wdg;
    delete vlay;
    delete _skipSongButton;
    delete _volumeDown;
    delete _volumeUp;
}

void MainWindow::skipSongButtonClicked() {
    _musicPlayer->skipSong();
    _slider->setSliderPosition(0);
}

void MainWindow::volumeDownButtonClicked() {
    _musicPlayer->lowerVolume();
}

void MainWindow::volumeUpButtonClicked() {
    _musicPlayer->louderVolume();
}

void MainWindow::playButtonClicked() {
    _musicPlayer->play_pause();
    _videoPlayer->play_pause();
}

void MainWindow::sliderValueChanged() {
    _musicPlayer->changeSliderValue(_slider->value());
    _videoPlayer->changeSliderValue(_slider->value());
}
