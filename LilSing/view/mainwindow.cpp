#include <QDebug>

#include "mainwindow.h"

#define _width 500
#define _height 800

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    _musicPlayer = new MusicPlayer;
    _videoPlayer = new VideoPlayer;
    _sqlHandler = new Sqlhandler(_dbPath);
    _recorder = new Recorder();
    qDebug() << "Started";

    wdg = new QWidget(this);
    vlay = new QVBoxLayout(wdg);
    _skipSongButton = new QPushButton("Skip song");
    _volumeDown = new QPushButton("Vol-");
    _volumeUp = new QPushButton("Vol+");
    _play_stop = new QPushButton("Pause, Play");
    _start_recording = new QPushButton("Start, Pause Recording");
    _stop_recording = new QPushButton("Stop Recording");
    _slider = new QSlider(Qt::Horizontal);

    _showDb = new QPushButton("Show Songs");
    _listSongs = new QPushButton("List Songs");

    vlay->addWidget(_volumeDown);
    vlay->addWidget(_skipSongButton);
    vlay->addWidget(_volumeUp);
    vlay->addWidget(_play_stop);
    vlay->addWidget(_start_recording);
    vlay->addWidget(_stop_recording);
    vlay->addWidget(_slider);
    vlay->addWidget(_showDb);
    vlay->addWidget(_listSongs);

    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    setWindowTitle("Lil'Sing");
    setMinimumHeight(_height);
    setMinimumWidth(_width);

    connect(_skipSongButton, SIGNAL(clicked()),
            this, SLOT(skipSongButtonClicked()));

    connect(_volumeDown, SIGNAL(clicked()),
            this, SLOT(volumeDownButtonClicked()));

    connect(_volumeUp, SIGNAL(clicked()),
            this, SLOT(volumeUpButtonClicked()));

    connect(_play_stop, SIGNAL(clicked()),
            this, SLOT(playButtonClicked()));

    connect(_start_recording, SIGNAL(clicked()),
            this, SLOT(recordButtonClicked()));

    connect(_stop_recording, SIGNAL(clicked()),
            this, SLOT(stopRecordButtonClicked()));

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
        _selectList->setText(_song.title);
        _selectList->move(_selectList->pos().x(), _selectList->pos().y() + _pos);
        connect(_selectList, SIGNAL(clicked()),
                this, SLOT(songElementClicked()));
        _selectList->show();

        _songLayout->addWidget(_selectList);
        _pos += 25;
    }
}

void MainWindow::songElementClicked() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString _sender = buttonSender->text();

    QUrl _url = _sqlHandler->loadSong(_sender);
    QDesktopServices::openUrl(_url);
}

void MainWindow::recordButtonClicked() {
    _recorder->startRecording();
}

void MainWindow::stopRecordButtonClicked() {
    _recorder->stopRecording();

    QString _path = QCoreApplication::applicationDirPath() + "/../../../Karaoke/LilSing/output/output";
    QDir _dir(_path);
    QStringList _filter;
    _filter << "*.wav";

    QString _name = _dir.entryList(_filter).at(0);

    _recorder->readWAV(_name);
}
