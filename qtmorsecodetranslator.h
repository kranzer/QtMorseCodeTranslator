#ifndef QTMORSECODETRANSLATOR_H
#define QTMORSECODETRANSLATOR_H
#include <QObject>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "translatemanager.h"

namespace Ui {
class QtMorseCodeTranslator;
}

class QtMorseCodeTranslator : public QWidget
{
    Q_OBJECT

public:
    explicit QtMorseCodeTranslator(QWidget *parent = 0);
    ~QtMorseCodeTranslator();
signals:
    void signFromMorse(QString);//to know what mode
    void signToMorse(QString);  //is on

private slots:
    void on_m_openFileButton_clicked();

    void on_m_translateButton_clicked();

    void on_m_saveResultButton_clicked();

    void setOutputText(const QString&);


private:
    Ui::QtMorseCodeTranslator *ui;
    translateManager* m_translator;
};

#endif // QTMORSECODETRANSLATOR_H
