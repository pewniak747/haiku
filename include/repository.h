#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

#include "word.h"
#include "poem_template.h"

template<class T>
class Repository {
  public:
    void add(T *element);
    T* getRandomElement();
  protected:
    std::vector<T*> elements;
};

class WordRepository : public Repository<Word> {};

class PoemTemplateRepository : public Repository<PoemTemplate> {};

#endif // REPOSITORY_H
