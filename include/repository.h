#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <cstdlib>

#include "word.h"
#include "poem_template.h"

template<typename T>
class Repository {
  public:
    void add(T *element);
    unsigned size();
    T* getElement(unsigned index);
    T* getRandomElement();
  protected:
    std::vector<T*> elements;
};

class WordRepository : public Repository<Word> {
  public:
    Word* getWordForTemplate(WordTemplate *wordTemplate, unsigned minSyllabes, unsigned maxSyllabes) {
      WordRepository filteredRepository;
      for(unsigned i = 0; i < size(); i++) {
        Word *element = getElement(i);
        if(minSyllabes <= element->getSyllabes() &&
           maxSyllabes >= element->getSyllabes() &&
           wordTemplate->matches(element->getType())) {
          filteredRepository.add(getElement(i));
        }
      }
      return filteredRepository.getRandomElement();
    };
};

class PoemTemplateRepository : public Repository<PoemTemplate> {};

template<typename T>
void Repository<T>::add(T *element) {
  return elements.push_back(element);
}

template<typename T>
unsigned Repository<T>::size() {
  return elements.size();
}

template<typename T>
T* Repository<T>::getElement(unsigned index) {
  return elements[index];
};

template<typename T>
T* Repository<T>::getRandomElement() {
  int random = rand() % elements.size();
  return elements[random];
};

#endif // REPOSITORY_H
