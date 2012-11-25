#ifndef POEM_GENERATOR_H
#define POEM_GENERATOR_H

#include "word.h"
#include "poem_template.h"

class PoemGenerator {
  public:
    PoemGenerator();
    Poem* getPoem();
  private:
    void loadWordRepository();
    void loadTemplateRepository();
    PoemTemplate *getRandomTemplate();
    std::vector<Word*> wordRepository;
    std::vector<PoemTemplate*> templateRepository;
};

#endif // POEM_GENERATOR_H
