#include "qtmorsecodetranslator.h"
#include "ui_qtmorsecodetranslator.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMap>
#include <QDebug>


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
    QStringList englishChars;
    englishChars << "A" << "B" << "C" << "D" << "E"
                 << "F" << "G" << "H" << "I" << "J"
                 << "K" << "L" << "M" << "N" << "O"
                 << "P" << "Q" << "R" << "S" << "T"
                 << "U" << "V" << "W" << "X" << "Y"
                 << "Z";

    QStringList morseChars;
    morseChars   << ".-"   << "-..." << "-.-." << "-.." << "."
                 << "..-." << "--."  << "...." << ".."  << ".---"
                 << "-.-"  << ".-.." << "--"   << "-."  << "---"
                 << ".--." << "--.-" << ".-." << "..."  << "-"
                 << "..-"  << "...-" << ".--" << "-..-" << "-.--"
                 << "--..";
    QMap<QString,QString> translateDictionary;

    for(int i = 0; i < englishChars.size(); i++){
        translateDictionary.insert(englishChars[i], morseChars[i]);
    }

    if(ui->m_morseToEng->isChecked()){
        QString morseText = (ui->m_inputText->toPlainText());
        QString englishText;
        QStringList words;
        QString chars;
        QString tempString = "";
        words = morseText.split("  ");
        for(int i = 0; i < words.size(); i++){
            chars = words[i];
            for(int j = 0; j < chars.length(); j++){
                if(chars[j] =='-'||chars[j] == '.'||chars[j]==' '){
                    tempString += chars[j];
                }
                else{
                    chars.remove(j,1);
                    j--;
                }
            }
            for(int j=0; j<chars.split(" ").length(); j++){
                englishText+=translateDictionary.key(chars.split(" ")[j]);
            }
            englishText+=" ";
        }
        englishText = englishText.toLower();
        englishText[0] = englishText[0].toUpper();
        ui->m_outputText->setText(englishText);
    }

    else if(ui->m_engToMorse->isChecked()){
        QString englishText = ui->m_inputText->toPlainText().toUpper();
        QString morseText;
        QStringList words;
        words = englishText.split(" ");
        for(int i = 0; i < words.size(); i++){
            QList<QChar> chars;
            for(int j = 0; j < words[i].length(); j++){
                chars << words[i][j];
            }
            for(int j = 0; j < chars.size(); j++){
                morseText+=translateDictionary.value(chars[j]);
                morseText+=" ";
            }

            morseText+="  ";
        }
        ui->m_outputText->setText(morseText);
    }

}

void QtMorseCodeTranslator::on_m_saveResultButton_clicked()
{
    QFile outputFile(QFileDialog::getSaveFileName(0,
                                                  tr("Save result to file"),
                                                  QDir::homePath(),
                                                  "Text files (*.txt)")
                                                  );
    outputFile.open(QIODevice::WriteOnly);
    QTextStream text(&outputFile);
    text << ui->m_outputText->toPlainText();
}
