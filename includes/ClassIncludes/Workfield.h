#ifndef WORKFIELD_H
#define WORKFIELD_H

#include <string>

class WorkField {
private:
    int id;
    std::string name;

public:
    WorkField(int id, const std::string& name);

    // Getters
    int getId() const;
    const std::string& getName() const;
};

#endif
