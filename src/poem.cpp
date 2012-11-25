#include <cstdio>
#include "poem.h"

Poem::Poem(std::vector<Line*> lines) {
  this->lines = lines;
  printf("[ DEBUG ] created poem\n");
}

std::string Poem::toString() {
  std::string result = "";
  for(unsigned i = 0; i < lines.size(); i++) {
    result += this->lines[i]->getJapanese();
    result += "\n";
  }
  return result;
}
