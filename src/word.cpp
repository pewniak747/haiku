#include <string>

#include "word.h"

Word::Word(std::string kanji, std::string kana, std::string romaji, std::string english, std::string type) {
  this->japaneseKanji = kanji;
  this->japaneseKana = kana;
  this->japaneseRomaji = romaji;
  this->english = english;
  this->type = type;
}

std::string Word::getJapaneseKanji() {
  return this->japaneseKanji;
}

std::string Word::getJapaneseKana() {
  return this->japaneseKana;
}

std::string Word::getJapaneseRomaji() {
  return this->japaneseRomaji;
}

std::string Word::getEnglish() {
  return this->english;
}
std::string Word::getType() {
  return this->type;
}

