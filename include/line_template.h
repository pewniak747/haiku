#ifndef LINE_TEMPLATE_H
#define LINE_TEMPLATE_H

#include <string>
#include <vector>

#include "word_template.h"

class LineTemplate {
  public:
    LineTemplate(std::vector<WordTemplate*> wordTemplates, std::string japanese);
  private:
    std::vector<WordTemplate*> wordTemplates;
    std::string japanese;
};

#endif // LINE_TEMPLATE_H