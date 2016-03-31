#ifndef TRANSLATEMANAGER_H
#define TRANSLATEMANAGER_H
#include <QMap>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

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
    void toMorse(const QString&);
    void fromMorse(const QString&);

};

#endif // TRANSLATEMANAGER_H
