#include <QDebug>

#include "sqlhandler.h"

sqlhandler::sqlhandler(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if ( !m_db.open() ) {
       qDebug() << "Error: connection with database failed";
    } else {
       qDebug() << "Database: connection ok";
    }
}

bool sqlhandler::addSong(const QString& title, const QString& album, const QString& artist) {
   bool success = false;

   QSqlQuery query;
   query.prepare("INSERT INTO songs (title, album, artist) VALUES (:title, :album, :artist)");

   query.bindValue(":title", title);
   query.bindValue(":album", album);
   query.bindValue(":artist", artist);

   if(query.exec()) {
       success = true;
   } else {
        qDebug() << "Failed to add song:" << query.lastError();
   }

   return success;
}

bool sqlhandler::removeSong(const int &id) {
    bool success = false;

    QSqlQuery query;
    query.prepare("DELETE FROM songs WHERE id = (:id)");
    query.bindValue(":id", id);
    success = query.exec();

    if(!success) {
        qDebug() << "Failed to remove song:" << query.lastError();
    }

    return success;
}

void sqlhandler::printSongs() {
    QSqlQuery query("SELECT * FROM songs");
    int song_id = query.record().indexOf("title");
    int album_id = query.record().indexOf("album");
    int artist_id = query.record().indexOf("artist");
    qDebug() << "   Title" << "|    Album" << "|    Artist";
    while (query.next())
    {
       QString title = query.value(song_id).toString();
       QString album = query.value(album_id).toString();
       QString artist = query.value(artist_id).toString();
       qDebug() << "        " << title << " | " << album << " | " << artist;
    }
}
