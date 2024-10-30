#include "../includes/ClassIncludes/WorkField.h"

WorkField::WorkField(int id, const std::string& name) : id(id), name(name) {}

int WorkField::getId() const { return id; }
const std::string& WorkField::getName() const { return name; }
