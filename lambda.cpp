/*
    lambda.cpp

    Examples of captures in lambda functions and use of std::function
*/

#include <functional>
#include <iostream>
#include <sstream>
#include <assert.h>

int add(int n1, int n2) {
    return n1 + n2;
}

int add2(int n) {
    return n + 2;
}

class Application {
public:
    int apply(int n) {
        return n + 2;
    }

    static int applyApplication(int n) {
        return n + 2;
    }
};

int main(int argc, char* argv[]) {

    // function
    {
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // empty capture
    {
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // const variable capture reference
    {
        const int INCR = 2;
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // capture variable because not constexpr
    {
        int size = 2;
        const int INCR = size;
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // non-const variable capture value
    {
        int incr = 2;
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // capture the number of times the function is executed
    {
        int numrun = 0;
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // pass complex object and use inside lambda
    {
        std::istringstream input("2");

        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // pass static method of a class
    {
        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    // pass non-static method of a class
    {
        Application application;

        std::function<int(int)> f;

        if (f) {

            assert(f(1) == 3);
        }
    }

    return 0;
}
