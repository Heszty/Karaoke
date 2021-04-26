#ifndef LILSING_MODEL_MODEL_H_
#define LILSING_MODEL_MODEL_H_

#include <QObject>

class Model : public QObject {
    Q_OBJECT
 public:
    explicit Model(QObject *parent = nullptr);

 signals:
};

#endif  // LILSING_MODEL_MODEL_H_
