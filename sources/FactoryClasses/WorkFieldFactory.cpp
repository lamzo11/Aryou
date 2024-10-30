#include "../../includes/FactoryHeaders/WorkFieldFactory.h"

WorkField WorkFieldFactory::createWorkField(int id, const std::string& name) {
    return WorkField(id, name);
}
