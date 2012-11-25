#include <string>
#include <vector>

#include "line_template.h"

LineTemplate::LineTemplate(std::vector<WordTemplate*> wordTemplates, std::string japanese) {
  this->wordTemplates = wordTemplates;
  this->japanese = japanese;
}

WordTemplate* LineTemplate::getWord(unsigned i) {
  return this->wordTemplates[i];
}

unsigned LineTemplate::wordsCount() {
  return this->wordTemplates.size();
}
