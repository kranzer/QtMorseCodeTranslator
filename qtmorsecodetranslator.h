#ifndef QTMORSECODETRANSLATOR_H
#define QTMORSECODETRANSLATOR_H
#include <QObject>
#include <QWidget>
#include "translatemanager.h"

namespace Ui {
class QtMorseCodeTranslator;
}

class QtMorseCodeTranslator : public QWidget
{
    Q_OBJECT

private:
    translateManager* translator;
public:
    explicit QtMorseCodeTranslator(QWidget *parent = 0);
    ~QtMorseCodeTranslator();
signals:
    void signMorseToEng(QString);
    void signEngToMorse(QString);

private slots:
    void on_m_openFileButton_clicked();

    void on_m_translateButton_clicked();

    void on_m_saveResultButton_clicked();

    void setOutputText(QString);

private:
    Ui::QtMorseCodeTranslator *ui;
};

#endif // QTMORSECODETRANSLATOR_H
