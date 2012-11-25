#include "line.h"

Line::Line(std::vector<Word*> words, LineTemplate *lineTemplate) {
  this->words = words;
  this->lineTemplate = lineTemplate;
}

std::string Line::getJapanese() {
  return "";
}
