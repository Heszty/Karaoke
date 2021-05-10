#include "recorder.h"

Recorder::Recorder(QObject* parent) {
    _recorder = new QAudioRecorder(parent);
    QAudioEncoderSettings audioSettings;

    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    _recorder->setEncodingSettings(audioSettings);

    _url.setUrl(url_string);
    if(_recorder->setOutputLocation(url_string)) {
        qDebug() << "Helyes location";
    } else {
        qDebug() << _recorder->outputLocation();
    }
}

void Recorder::startRecording() {
    if(_recorder->state() != QAudioRecorder::RecordingState) {
        _recorder->record();
        qDebug() << "Recording";
    } else {
        _recorder->pause();
        qDebug() << "Recording paused";
    }
}

void Recorder::stopRecording() {
    if(_recorder->state() != QAudioRecorder::StoppedState) {
        _recorder->stop();
        qDebug() << "Recording stopped";
    }
}
