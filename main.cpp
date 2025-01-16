#include <iostream>
#include <vector>
#include <string>

#include "Observer.hpp"
#include "Observable.hpp"

typedef int Context;

typedef s2::Observable<Context> IntObservable;
typedef s2::Observer<Context> IntObserver;

class A : public IntObservable {};

class B : public IntObserver {
public:
    void operator()(Context& context) override {
        std::cout << context << '\n';    
    }
};

// This is now possible:
//class D : public IntObservable, public s2::Observer<std::string>, public IntObserver {
//public:
//    void operator()(Context& context) override {
//        std::cout << "int" << context << '\n';    
//    }
//
//    void operator()(std::string& context) override {
//        std::cout << "string" << context << '\n';    
//    }
//};


int main(int argc, char * argv[]) {
    A observableA;
    B observerB;

    int  value = 5;
    observableA.addObserver(observerB);
    observableA.notifyObservers(value);
    //observableA.removeObserver(observerB);
    observableA.notifyObservers(value);

    return 0;
}
