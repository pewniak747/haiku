#ifndef WORD_TEMPLATE_H
#define WORD_TEMPLATE_H

#include <string>

class WordTemplate {
  public:
    WordTemplate(std::string type);
    std::string getType();
  private:
    std::string type;
};

#endif // WORD_TEMPLATE_H
