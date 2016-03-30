#include "translatemanager.h"

translateManager::translateManager() : QObject()
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

    for(int i = 0; i < englishChars.size(); i++){
        translateDictionary.insert(englishChars[i], morseChars[i]);
    }
}

void translateManager::morseToEng(QString morseText){
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
    emit signGotText(englishText);
}

void translateManager::engToMorse(QString englishText){
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
    emit signGotText(morseText);
}


