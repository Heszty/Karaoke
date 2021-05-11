#ifndef LILSING_MODEL_RECORDER_H_
#define LILSING_MODEL_RECORDER_H_

#include <QAudioRecorder>
#include <QUrl>
#include <QCoreApplication>
#include <QFile>
#include <QtEndian>
#include <QDir>

class Recorder {
 public:
    explicit Recorder(QObject *parent = nullptr);
    ~Recorder();
    void setInput();

    void startRecording();
    void stopRecording();
    void readWAV(QString wavFile);
 private:
    const QString url_string = QCoreApplication::applicationDirPath() + "/../../../Karaoke/LilSing/output/output";
    QAudioRecorder* _recorder;
};

#endif  // LILSING_MODEL_RECORDER_H_
