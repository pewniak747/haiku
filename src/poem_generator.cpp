#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "poem.h"
#include "poem_generator.h"

PoemGenerator::PoemGenerator() {
  this->loadWordRepository();
  printf("[ DEBUG ] created poem generator\n");
}

Poem* PoemGenerator::getPoem() {
  srand(time(0));
  std::vector<std::string> lines;
  for(int i = 0; i < 3; i++) {
    std::string line = "";
    for(int l = 0; l < 3; l++) {
      int selected = rand() % this->wordRepository.size();
      line += this->wordRepository[selected];
      if(l != 3) line += " ";
    }
    lines.push_back(line);
  }
  printf("[ DEBUG ] generated lines\n");
  Poem *poem = new Poem(lines);
  return poem;
}

void PoemGenerator::loadWordRepository() {
  this->wordRepository.push_back("furuike");
  this->wordRepository.push_back("kawazu");
  this->wordRepository.push_back("tobikomu");
  this->wordRepository.push_back("mizu");
  this->wordRepository.push_back("oto");
  printf("[ DEBUG ] loaded word repository\n");
}
