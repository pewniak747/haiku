#include <string>
#include <vector>

#include "line_template.h"

LineTemplate::LineTemplate(std::vector<WordTemplate*> wordTemplates, std::string japanese, std::string romaji, std::string english) {
  this->wordTemplates = wordTemplates;
  this->japanese = japanese;
  this->romaji = romaji;
  this->english = english;
}

std::string LineTemplate::getJapaneseTemplate() {
  return this->japanese;
}

WordTemplate* LineTemplate::getWord(unsigned i) {
  return this->wordTemplates[i];
}

unsigned LineTemplate::wordsCount() {
  return this->wordTemplates.size();
}
