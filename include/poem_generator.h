#ifndef POEM_GENERATOR_H
#define POEM_GENERATOR_H

#include "word.h"
#include "poem.h"
#include "poem_template.h"
#include "repository.h"

class PoemGenerator {
  public:
    PoemGenerator(WordRepository *wordRepository, PoemTemplateRepository *templateRepository);
    Poem* getPoem();
  private:
    PoemTemplate *getRandomTemplate();
    Word* getWordForTemplate(WordTemplate *wordTemplate);
    WordRepository *wordRepository;
    PoemTemplateRepository *templateRepository;
};

#endif // POEM_GENERATOR_H
