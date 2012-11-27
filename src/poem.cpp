#include <cstdio>
#include "poem.h"

Poem::Poem(std::vector<Line*> lines) {
  this->lines = lines;
}

std::string Poem::toString(std::string (*wordToString)(Word *word), std::string (*lineToTemplateString)(LineTemplate *line)) {
  std::string result = "";
  for(unsigned i = 0; i < lines.size(); i++) {
    result += this->lines[i]->toString(wordToString, lineToTemplateString);
    result += "\n";
  }
  return result;
}
