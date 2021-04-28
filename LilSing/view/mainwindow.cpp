#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    _musicPlayer = new MusicPlayer;
    _videoPlayer = new VideoPlayer;
    _sqlHandler = new Sqlhandler(_dbPath);
    qDebug() << "Started";

    wdg = new QWidget(this);
    vlay = new QVBoxLayout(wdg);
    _skipSongButton = new QPushButton("Skip song");
    _volumeDown = new QPushButton("Vol-");
    _volumeUp = new QPushButton("Vol+");
    _play_stop = new QPushButton("Pause, Play");
    _slider = new QSlider(Qt::Horizontal);

    _showDb = new QPushButton("Show Songs");
    _listSongs = new QPushButton("List Songs");

    vlay->addWidget(_volumeDown);
    vlay->addWidget(_skipSongButton);
    vlay->addWidget(_volumeUp);
    vlay->addWidget(_play_stop);
    vlay->addWidget(_slider);
    vlay->addWidget(_showDb);
    vlay->addWidget(_listSongs);

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

    connect(_showDb, SIGNAL(clicked()),
            this, SLOT(showDbButtonClicked()));

    connect(_listSongs, SIGNAL(clicked()),
            this, SLOT(listSongsBtnClicked()));
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

void MainWindow::showDbButtonClicked() {
    _sqlHandler->printSongs();
}

void MainWindow::listSongsBtnClicked() {
    _songs = _sqlHandler->getSongs();
    int _pos = 0;

    _songList = new QDockWidget(this);
    _songList->setAllowedAreas(Qt::RightDockWidgetArea);

    _songLayout = new QGridLayout;
    _songLayout->setColumnMinimumWidth(0, 500);
    _songLayout->setHorizontalSpacing(25);

    while ( !_songs.isEmpty() ) {
        _song = _songs.takeFirst();

        _selectList = new QPushButton(this);
        _selectList->setMinimumWidth(400);
        _selectList->setText(_song.artist + " - " + _song.title + " (" + _song.album + ")");
        _selectList->move(_selectList->pos().x(), _selectList->pos().y() + _pos);
        connect(_selectList, SIGNAL(clicked()),
                this, SLOT(songElementClicked()));
        _selectList->show();

        _songLayout->addWidget(_selectList);
        _pos += 25;
    }
}

void MainWindow::songElementClicked() {
    QUrl _url = _song.link;
    QDesktopServices::openUrl(_url);
}
