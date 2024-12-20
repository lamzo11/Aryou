#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;  // Pure virtual method to be overridden
};

#endif
