#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
  public:
    Word(std::string kanji, std::string kana, std::string romaji, std::string english, std::string type);
    std::string getJapaneseKanji();
    std::string getJapaneseKana();
    std::string getJapaneseRomaji();
    std::string getEnglish();
    std::string getType();
  private:
    std::string japaneseKanji;
    std::string japaneseKana;
    std::string japaneseRomaji;
    std::string english;
    std::string type;
};

#endif // WORD_H
