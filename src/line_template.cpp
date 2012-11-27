#include <string>
#include <vector>

#include "line_template.h"

LineTemplate::LineTemplate(std::vector<WordTemplate*> wordTemplates, std::string japanese, std::string romaji, std::string english, unsigned syllabes) {
  this->wordTemplates = wordTemplates;
  this->japanese = japanese;
  this->romaji = romaji;
  this->english = english;
  this->syllabes = syllabes;
}

std::string LineTemplate::getJapaneseTemplate() {
  return this->japanese;
}

std::string LineTemplate::getRomajiTemplate() {
  return this->romaji;
}

std::string LineTemplate::getEnglishTemplate() {
  return this->english;
}

unsigned LineTemplate::getSyllabes() {
  return this->syllabes;
}

WordTemplate* LineTemplate::getWord(unsigned i) {
  return this->wordTemplates[i];
}

unsigned LineTemplate::wordsCount() {
  return this->wordTemplates.size();
}
