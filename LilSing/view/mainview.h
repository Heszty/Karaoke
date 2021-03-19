#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

class MainView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();
signals:

};

#endif // MAINVIEW_H
