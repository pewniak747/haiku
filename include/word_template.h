#ifndef WORD_TEMPLATE_H
#define WORD_TEMPLATE_H

#include <string>
#include <vector>

#include "word.h"

class WordTemplate {
  public:
    WordTemplate(std::string type);
    bool matches(std::string otherType);
  private:
    std::string type;
    std::string wordType;
    std::string wordCategory;
    std::vector<std::string> splitString(std::string input);
};

#endif // WORD_TEMPLATE_H
