#ifndef LILSING_MODEL_SQLHANDLER_H_
#define LILSING_MODEL_SQLHANDLER_H_

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVector>

struct song_struct {
    QString title;
    QString artist;
    QString album;
    QString link;
};

class Sqlhandler {
 public:
    explicit Sqlhandler(const QString& path);
    bool addSong(const QString& title, const QString& album, const QString& artist);
    bool removeSong(const int& id);
    void printSongs();
    QVector<song_struct> getSongs();
    QString loadSong(QString input);

 private:
    QSqlDatabase m_db;
    QVector<song_struct> _vec;
    // song_struct _songs;
};

#endif  // LILSING_MODEL_SQLHANDLER_H_
