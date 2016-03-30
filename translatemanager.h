#ifndef TRANSLATEMANAGER_H
#define TRANSLATEMANAGER_H
#include <QMap>
#include <QObject>


class translateManager : public QObject
{
Q_OBJECT
private:
    QMap<QString,QString> translateDictionary;

public:
    translateManager();

signals:
    void signGotText(QString);

public slots:
    void engToMorse(QString);
    void morseToEng(QString);
};

#endif // TRANSLATEMANAGER_H
