#ifndef POEM_GENERATOR_H
#define POEM_GENERATOR_H

#include "word.h"

class PoemGenerator {
  public:
    PoemGenerator();
    Poem* getPoem();
  private:
    void loadWordRepository();
    std::vector<Word*> wordRepository;
};

#endif // POEM_GENERATOR_H
