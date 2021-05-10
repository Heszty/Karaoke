#include "recorder.h"

Recorder::Recorder(QObject* parent) {
    _recorder = new QAudioRecorder(parent);
    QAudioEncoderSettings audioSettings;

    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    _recorder->setEncodingSettings(audioSettings);

    _recorder->setAudioInput(_recorder->audioInputs().at(1));

    _url.setUrl(url_string);
    qDebug() << QUrl::fromLocalFile(url_string);
    _recorder->setOutputLocation(QUrl::fromLocalFile(url_string));
}

void Recorder::startRecording() {
    if(_recorder->state() != QAudioRecorder::RecordingState) {
        _recorder->record();
        qDebug() << "Recording started";
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
