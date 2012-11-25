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
  std::vector<WordTemplate*> firstLineWords;
  firstLineWords.push_back(new WordTemplate("noun:place"));
  std::vector<WordTemplate*> secondLineWords;
  secondLineWords.push_back(new WordTemplate("noun:animal"));
  secondLineWords.push_back(new WordTemplate("verb:*"));
  std::vector<WordTemplate*> thirdLineWords;
  thirdLineWords.push_back(new WordTemplate("noun:element"));
  thirdLineWords.push_back(new WordTemplate("noun:element"));
  LineTemplate *firstLine = new LineTemplate(firstLineWords, "$1 ya");
  LineTemplate *secondLine = new LineTemplate(secondLineWords, "$1 $2");
  LineTemplate *thirdLine = new LineTemplate(thirdLineWords, "$1 no $2");
  std::vector<LineTemplate*> threeLines;
  threeLines.push_back(firstLine);
  threeLines.push_back(secondLine);
  threeLines.push_back(thirdLine);
  this->templateRepository.push_back(new PoemTemplate(threeLines));
  printf("[ DEBUG ] loaded template repository\n");
}
