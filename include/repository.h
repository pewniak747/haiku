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
      elements.push_back(element);
    };
    T* getRandomElement() {
      int random = rand() % elements.size();
      return elements[random];
    };
    unsigned size() {
      return elements.size();
    }
    T* getElement(unsigned index) {
      return elements[index];
    }
  protected:
    std::vector<T*> elements;
};

class WordRepository : public Repository<Word> {
  public:
    Word* getWordForTemplate(WordTemplate *wordTemplate) {
      WordRepository filteredRepository;
      for(unsigned i = 0; i < size(); i++) {
        filteredRepository.add(getElement(i));
      }
      return filteredRepository.getRandomElement();
    };
};

class PoemTemplateRepository : public Repository<PoemTemplate> {};

#endif // REPOSITORY_H
