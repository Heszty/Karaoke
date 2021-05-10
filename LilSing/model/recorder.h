#ifndef LILSING_MODEL_RECORDER_H_
#define LILSING_MODEL_RECORDER_H_

#include <QAudioRecorder>
#include <QUrl>
#include <QCoreApplication>

class Recorder {
 public:
    explicit Recorder(QObject *parent = nullptr);
    ~Recorder();
    void setInput();

    void startRecording();
    void stopRecording();

 private:
    const QString url_string = QCoreApplication::applicationDirPath() + "/../../../Karaoke/LilSing/output/output";
    QAudioRecorder* _recorder;
};

#endif  // LILSING_MODEL_RECORDER_H_
