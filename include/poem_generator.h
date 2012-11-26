#ifndef POEM_GENERATOR_H
#define POEM_GENERATOR_H

#include "word.h"
#include "poem.h"
#include "poem_template.h"
#include "repository.h"

class PoemGenerator {
  public:
    PoemGenerator();
    Poem* getPoem();
  private:
    void loadWordRepository();
    void loadTemplateRepository();
    PoemTemplate *getRandomTemplate();
    Word* getWordForTemplate(WordTemplate *wordTemplate);
    WordRepository wordRepository;
    PoemTemplateRepository templateRepository;
};

#endif // POEM_GENERATOR_H
