#ifndef WORKFIELDFACTORY_H
#define WORKFIELDFACTORY_H

#include "../ClassIncludes/Workfield.h"
#include <string>

class WorkFieldFactory {
public:
    static WorkField createWorkField(int id, const std::string& name);
};

#endif
