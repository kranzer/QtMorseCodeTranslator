#ifndef QTMORSECODETRANSLATOR_H
#define QTMORSECODETRANSLATOR_H

#include <QWidget>

namespace Ui {
class QtMorseCodeTranslator;
}

class QtMorseCodeTranslator : public QWidget
{
    Q_OBJECT

public:
    explicit QtMorseCodeTranslator(QWidget *parent = 0);
    ~QtMorseCodeTranslator();

private slots:
    void on_m_openFileButton_clicked();

    void on_m_translateButton_clicked();

    void on_m_saveResultButton_clicked();

private:
    Ui::QtMorseCodeTranslator *ui;
};

#endif // QTMORSECODETRANSLATOR_H
