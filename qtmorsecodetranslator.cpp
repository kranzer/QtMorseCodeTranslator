#include "qtmorsecodetranslator.h"
#include "ui_qtmorsecodetranslator.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>

QtMorseCodeTranslator::QtMorseCodeTranslator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtMorseCodeTranslator)
{
    ui->setupUi(this);
    ui->m_morseToEng->setChecked(true);
}

QtMorseCodeTranslator::~QtMorseCodeTranslator()
{
    delete ui;
}

void QtMorseCodeTranslator::setOutputText(QString text){
    ui->m_outputText->setText(text);
}

void QtMorseCodeTranslator::on_m_openFileButton_clicked()
{
    //Opening input file
    QFile inputFile(QFileDialog::getOpenFileName(0,
                                                 tr("Select your input file"),
                                                 QDir::homePath(),
                                                 "Text files (*.txt)")
                                                 );
    inputFile.open(QIODevice::ReadOnly);
    QTextStream text(&inputFile);
    ui->m_inputText->setText(text.readAll());
    inputFile.close();
}


void QtMorseCodeTranslator::on_m_translateButton_clicked()
{
    translator = new translateManager();
    if(ui->m_engToMorse->isChecked()){
        emit signEngToMorse(ui->m_inputText->toPlainText());
        connect(this, SIGNAL(signEngToMorse(QString)),
                translator, SLOT(engToMorse(QString)));
    }
    else if(ui->m_morseToEng->isChecked()){
        emit signMorseToEng(ui->m_inputText->toPlainText());
        connect(this, SIGNAL(signMorseToEng(QString)),
                translator, SLOT(morseToEng(QString)));
    }
    connect(translator, SIGNAL(signGotText(QString)),
            this, SLOT(setOutputText(QString)));
}

void QtMorseCodeTranslator::on_m_saveResultButton_clicked()
{
    //Creating output file and writing
    //the result into it
    QFile outputFile(QFileDialog::getSaveFileName(0,
                                                  tr("Save result to file"),
                                                  QDir::homePath(),
                                                  "Text files (*.txt)")
                                                  );
    outputFile.open(QIODevice::WriteOnly);
    QTextStream text(&outputFile);
    text << ui->m_outputText->toPlainText();
}
