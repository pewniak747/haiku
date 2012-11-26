#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <cstdlib>

#include "word.h"
#include "poem_template.h"

template<typename T>
class Repository {
  public:
    void add(T *element) {
      this->elements.push_back(element);
    };
    T* getRandomElement() {
      int random = rand() % this->elements.size();
      return this->elements[random];
    };
  protected:
    std::vector<T*> elements;
};

class WordRepository : public Repository<Word> {
  public:
    Word* getWordForTemplate(WordTemplate *wordTemplate) {
      return this->getRandomElement();
    };
};

class PoemTemplateRepository : public Repository<PoemTemplate> {};

#endif // REPOSITORY_H
