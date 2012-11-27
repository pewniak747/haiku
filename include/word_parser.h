#ifndef WORD_PARSER_H
#define WORD_PARSER_H

#include <string>

#include "repository.h"

class WordParser {
  public:
    WordParser(std::string fileName);
    void parse();
    void loadToRepository(WordRepository *repository);
  private:
    std::string xmlFileName;
};

#endif // WORD_PARSER_H
