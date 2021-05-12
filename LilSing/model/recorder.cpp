#include "recorder.h"

Recorder::Recorder(QObject* parent) {
    _recorder = new QAudioRecorder(parent);
    QAudioEncoderSettings audioSettings;

    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    _recorder->setEncodingSettings(audioSettings);

    _recorder->setAudioInput(_recorder->audioInputs().at(0));
    _recorder->setOutputLocation(QUrl::fromLocalFile(url_string));
}

void Recorder::startRecording() {
    if (_recorder->state() != QAudioRecorder::RecordingState) {
        _recorder->record();
        qDebug() << "Recording started";
    } else {
        _recorder->pause();
        qDebug() << "Recording paused";
    }
}

void Recorder::stopRecording() {
    if (_recorder->state() != QAudioRecorder::StoppedState) {
        _recorder->stop();
        qDebug() << "Recording stopped";
    }
}

void Recorder::readWAV(QString wavFile) {
    QString _path = QCoreApplication::applicationDirPath() + "/../../../Karaoke/LilSing/output/output";

    QFile m_WAVFile;
    QDir::setCurrent(_path);

    m_WAVFile.setFileName(wavFile);
    m_WAVFile.open(QIODevice::ReadWrite);

    char* strm = new char(16);
    QVector<double> m_DATA;

    m_WAVFile.read(4);  // RIFF

    m_WAVFile.read(strm, 4);  // chunk size
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm);

    m_WAVFile.read(strm, 4);  // format
    // qDebug() << strm;

    m_WAVFile.read(strm, 4);  // subchunk1 id
    // qDebug() << strm;

    m_WAVFile.read(strm, 4);  // subchunk1 size
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 2);  // audio format
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 2);  // NumChannels
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 4);  // Sample rate
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 4);  // Byte rate
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 2);  // Block Allign
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 2);  // BPS
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    m_WAVFile.read(strm, 4);  // subchunk2 id
    // qDebug() << strm;

    m_WAVFile.read(strm, 4);  // subchunk2 size
    // qDebug() << qFromLittleEndian<quint32>((uchar*)strm) ;

    while (!m_WAVFile.atEnd()) {
        m_WAVFile.read(strm, 2);
        if (qFromLittleEndian<int16_t>(reinterpret_cast<uchar*>(strm))) {
            m_DATA.append(qFromLittleEndian<int16_t>(reinterpret_cast<uchar*>(strm)));
        }
    }

    int ind = 2000;
    while (m_DATA.at(ind) == -1) {
        ind += 100;
    }

    for (ind; ind + 100 < m_DATA.size(); ind += 100) {
        qDebug() << m_DATA.at(ind);
    }
}
