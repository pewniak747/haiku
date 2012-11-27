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
    lines.push_back(getLineForTemplate(lineTemplate));
  }
  return new Poem(lines);
}

PoemTemplate* PoemGenerator::getRandomTemplate() {
  return this->templateRepository->getRandomElement();
}

Line* PoemGenerator::getLineForTemplate(LineTemplate *lineTemplate) {
  std::vector<Word*> lineWords;
  unsigned syllabesLeft = lineTemplate->getSyllabes();
  unsigned wordsLeft = lineTemplate->wordsCount();
  unsigned minSyllabes = 0;
  for(unsigned l = 0; l < lineTemplate->wordsCount(); l++) {
    if(wordsLeft == 1) minSyllabes = syllabesLeft;
    WordTemplate *wordTemplate = lineTemplate->getWord(l);
    Word* selectedWord = this->getWordForTemplate(wordTemplate, minSyllabes, syllabesLeft);
    syllabesLeft-=selectedWord->getSyllabes();

    lineWords.push_back(selectedWord);
    wordsLeft--;
  }
  return new Line(lineWords, lineTemplate);
}

Word* PoemGenerator::getWordForTemplate(WordTemplate *wordTemplate, unsigned minSyllabes, unsigned maxSyllabes) {
  return this->wordRepository->getWordForTemplate(wordTemplate, minSyllabes, maxSyllabes);
}
