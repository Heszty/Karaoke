sudo apt-get install -qq libqt5webkit5-dev qtdeclarative5-dev qtmultimedia5-dev libqt5multimediawidgets5
qmake Karaoke.pro -r CONFIG+=debug
make