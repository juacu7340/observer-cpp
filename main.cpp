#include <iostream>
#include <vector>
#include <string>

#include "Observer.hpp"
#include "Observable.hpp"

typedef s2::Observable<int> IntObservable;
typedef s2::Observer<int> IntObserver;

class A : public IntObservable {};

class B : public IntObserver {
public:
    void notify(int context) override {
        std::cout << context << '\n';    
    }
};

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
