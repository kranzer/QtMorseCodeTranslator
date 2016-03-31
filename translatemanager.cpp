#include "translatemanager.h"

translateManager::translateManager() : QObject()
{
    //translator constructor
    //user chooses his own configuration
    QString fileName = QFileDialog::getOpenFileName(0,
                                                    tr("Select your translate configuration"),
                                                    QDir::homePath(),
                                                    "Text files (*.txt)");
    if(!fileName.isEmpty()){
        QFile configFile(fileName);
        if(!configFile.open(QIODevice::ReadOnly))
            return;
        QTextStream in(&configFile);
        while (!in.atEnd())
        {
            QStringList ls;
            ls = in.readLine().split("   ");
            translateDictionary.insert(ls[0],ls[1]);
        }
        configFile.close();
    }

}

void translateManager::fromMorse(const QString& morseText)
{
    //Morse to natural language translation algorithm
    QString naturalText;
    QStringList words;
    QString tempString = "";
    words = morseText.split("  ");
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words[i].length(); j++){
            if(words[i][j] =='-'||words[i][j] == '.'||words[i][j]==' '){
                tempString += words[i][j];
            }
            else{
                words[i].remove(j,1);
                j--;
            }
        }
        for(int j=0; j<words[i].split(" ").length(); j++){
            naturalText+=translateDictionary.key(words[i].split(" ")[j]);
        }
        naturalText+=" ";
    }
    naturalText[0] = naturalText[0].toUpper();
    emit signGotText(naturalText.trimmed());//send translated text
}

void translateManager::toMorse(const QString& naturalText)
{
    //natural language to Morse translation algorithm
    QString morseText;
    QStringList words;
    words = naturalText.toLower().split(" ");
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words[i].size(); j++){
            morseText+=translateDictionary.value(QString(words[i][j]));
            morseText+=" ";
        }
        morseText+=" ";
    }
    emit signGotText(morseText.trimmed());//send translated text
}
