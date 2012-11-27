#include <cstdlib>
#include <ctime>

#include "poem_generator.h"

PoemGenerator::PoemGenerator(WordRepository *wordRepository, PoemTemplateRepository *templateRepository) {
  srand(time(0));
  this->wordRepository = wordRepository;
  this->templateRepository = templateRepository;
}

Poem* PoemGenerator::getPoem() {
  PoemTemplate *poemTemplate = this->getRandomTemplate();
  std::vector<Line*> lines;
  for(unsigned i = 0; i < poemTemplate->linesCount(); i++) {
    LineTemplate *lineTemplate = poemTemplate->getLine(i);
    Line *newLine = getLineForTemplate(lineTemplate);
    lines.push_back(newLine);
  }
  return new Poem(lines);
}

PoemTemplate* PoemGenerator::getRandomTemplate() {
  return this->templateRepository->getRandomElement();
}

Line* PoemGenerator::getLineForTemplate(LineTemplate *lineTemplate) {
  std::vector<Word*> lineWords;
  for(unsigned l = 0; l < lineTemplate->wordsCount(); l++) {
    WordTemplate *wordTemplate = lineTemplate->getWord(l);
    Word* selectedWord = this->getWordForTemplate(wordTemplate);
    lineWords.push_back(selectedWord);
  }
  return new Line(lineWords, lineTemplate);
}

Word* PoemGenerator::getWordForTemplate(WordTemplate *wordTemplate) {
  return this->wordRepository->getWordForTemplate(wordTemplate);
}
