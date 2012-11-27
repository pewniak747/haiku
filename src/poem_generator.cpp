#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "poem_generator.h"

PoemGenerator::PoemGenerator(WordRepository *wordRepository, PoemTemplateRepository *templateRepository) {
  srand(time(0));
  this->wordRepository = wordRepository;
  this->templateRepository = templateRepository;
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

PoemTemplate* PoemGenerator::getRandomTemplate() {
  return this->templateRepository->getRandomElement();
}

Word* PoemGenerator::getWordForTemplate(WordTemplate *wordTemplate) {
  return this->wordRepository->getWordForTemplate(wordTemplate);
}
