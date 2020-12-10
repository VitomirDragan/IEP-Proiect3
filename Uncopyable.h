#ifndef PROJECT1_UNCOPYABLE_H
#define PROJECT1_UNCOPYABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Uncopyable {
protected:
    Uncopyable();

    ~Uncopyable();

private:
    Uncopyable(const Uncopyable &);

    Uncopyable &operator=(const Uncopyable &);
};

#endif //PROJECT1_UNCOPYABLE_H
