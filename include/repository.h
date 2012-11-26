#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "word.h"
#include "poem_template.h"

template<typename T>
class Repository {
};

class WordRepository : Repository<Word> {};

class PoemTemplateRepository : Repository<PoemTemplate> {};

#endif // REPOSITORY_H
