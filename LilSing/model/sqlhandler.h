#ifndef LILSING_MODEL_SQLHANDLER_H_
#define LILSING_MODEL_SQLHANDLER_H_

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class Sqlhandler {
 public:
    explicit Sqlhandler(const QString& path);
    bool addSong(const QString& title, const QString& album, const QString& artist);
    bool removeSong(const int& id);
    void printSongs();

 private:
    QSqlDatabase m_db;
};

#endif  // LILSING_MODEL_SQLHANDLER_H_
