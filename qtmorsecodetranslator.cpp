#include "qtmorsecodetranslator.h"
#include "ui_qtmorsecodetranslator.h"


QtMorseCodeTranslator::QtMorseCodeTranslator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtMorseCodeTranslator)
{
    m_translator = new translateManager();//initialization of translator

    ui->setupUi(this);
    ui->m_fromMorse->setChecked(true);//translation from Morse to natural language is by default

    connect(this, SIGNAL(signToMorse(QString)),        //
            m_translator, SLOT(toMorse(QString)));     // Processing text
    connect(this, SIGNAL(signFromMorse(QString)),      //
            m_translator, SLOT(fromMorse(QString)));   //

    connect(m_translator, SIGNAL(signGotText(QString)),// Output of result into QTextEdit
            this, SLOT(setOutputText(QString)));

}

QtMorseCodeTranslator::~QtMorseCodeTranslator()
{
    delete ui;
}

void QtMorseCodeTranslator::setOutputText(const QString& text)
{
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
    //sending natural text from QTextEdit for processing
    if(ui->m_toMorse->isChecked()){
        emit signToMorse(ui->m_inputText->toPlainText());
    }
    //sending Morse text from QTextEdit for processing
    else if(ui->m_fromMorse->isChecked()){
        emit signFromMorse(ui->m_inputText->toPlainText());
    }


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
