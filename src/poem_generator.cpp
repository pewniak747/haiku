#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "poem.h"
#include "poem_generator.h"
#include "repository.h"
#include "repository.cpp"

PoemGenerator::PoemGenerator() {
  srand(time(0));
  this->loadWordRepository();
  this->loadTemplateRepository();
  printf("[ DEBUG ] created poem generator\n");
}

Poem* PoemGenerator::getPoem() {
  PoemTemplate *poemTemplate = this->getRandomTemplate();
  std::vector<Line*> lines;
  for(unsigned i = 0; i < poemTemplate->linesCount(); i++) {
    LineTemplate *lineTemplate = poemTemplate->getLine(i);
    std::vector<Word*> lineWords;
    for(unsigned l = 0; l < lineTemplate->wordsCount(); l++) {
      WordTemplate *wordTemplate = lineTemplate->getWord(l);
      Word* selectedWord = this->getWordForTemplate(wordTemplate);
      lineWords.push_back(selectedWord);
    }
    Line *newLine = new Line(lineWords, lineTemplate);
    lines.push_back(newLine);
  }
  printf("[ DEBUG ] generated lines\n");
  Poem *poem = new Poem(lines);
  return poem;
}

void PoemGenerator::loadWordRepository() {
  this->wordRepository.add(new Word("furuike", "noun:place"));
  this->wordRepository.add(new Word("kawazu", "noun:animal"));
  this->wordRepository.add(new Word("tobikomu", "verb"));
  this->wordRepository.add(new Word("mizu", "noun:element"));
  this->wordRepository.add(new Word("oto", "noun:element"));
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
  this->templateRepository.add(new PoemTemplate(threeLines));
  printf("[ DEBUG ] loaded template repository\n");
}

PoemTemplate* PoemGenerator::getRandomTemplate() {
  return this->templateRepository.getRandomElement();
}

Word* PoemGenerator::getWordForTemplate(WordTemplate *wordTemplate) {
  return this->wordRepository.getRandomElement();
}
