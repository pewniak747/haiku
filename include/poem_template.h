#ifndef POEM_TEMPLATE_H
#define POEM_TEMPLATE_H

#include "line_template.h"

class PoemTemplate {
  public:
    PoemTemplate(std::vector<LineTemplate*> lineTemplates);
  private:
    std::vector<LineTemplate*> lineTemplates;
};

#endif // POEM_TEMPLATE_H
