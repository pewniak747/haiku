#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "poem.h"
#include "poem_generator.h"

PoemGenerator::PoemGenerator() {
  this->loadWordRepository();
  this->loadTemplateRepository();
  printf("[ DEBUG ] created poem generator\n");
}

Poem* PoemGenerator::getPoem() {
  srand(time(0));
  std::vector<std::string> lines;
  for(int i = 0; i < 3; i++) {
    std::string line = "";
    for(int l = 0; l < 3; l++) {
      int selected = rand() % this->wordRepository.size();
      line += this->wordRepository[selected]->getJapanese();
      if(l != 3) line += " ";
    }
    lines.push_back(line);
  }
  printf("[ DEBUG ] generated lines\n");
  Poem *poem = new Poem(lines);
  return poem;
}

void PoemGenerator::loadWordRepository() {
  this->wordRepository.push_back(new Word("furuike", "noun:place"));
  this->wordRepository.push_back(new Word("kawazu", "noun:animal"));
  this->wordRepository.push_back(new Word("tobikomu", "verb"));
  this->wordRepository.push_back(new Word("mizu", "noun:element"));
  this->wordRepository.push_back(new Word("oto", "noun:element"));
  printf("[ DEBUG ] loaded word repository\n");
}

void PoemGenerator::loadTemplateRepository() {
  this->templateRepository.push_back(new PoemTemplate());
  printf("[ DEBUG ] loaded template repository\n");
}
