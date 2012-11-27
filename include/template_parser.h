#ifndef TEMPLATE_PARSER_H
#define TEMPLATE_PARSER_H

#include <string>
#include <vector>

#include "repository.h"

using namespace xercesc;

class TemplateParser {
  public:
    TemplateParser(std::string fileName);
    void parse();
    void loadToRepository(PoemTemplateRepository *repository);
  private:
    std::string xmlFileName;
    std::vector<PoemTemplate*> parsedElements;
};

#endif // TEMPLATE_PARSER_H
