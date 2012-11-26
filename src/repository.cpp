#include <cstdlib>

#include "repository.h"

template<class T>
T* Repository<T>::getRandomElement() {
  int random = rand() % this->elements.size();
  return this->elements[random];
}

template<class T>
void Repository<T>::add(T *newElement) {
  this->elements.push_back(newElement);
}
