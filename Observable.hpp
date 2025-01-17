#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include "Observer.hpp"

namespace s2 {
    template<typename Context>
    class Observable {
    public:
    // TODO: Add 'property' support
        void addObserver(Observer<Context>& observer) {
            observers.push_back(&observer);
        }

        void removeObserver(Observer<Context>& observer) {
            observers.remove(&observer);
        }

        void notifyObservers(Context context) {
            for (auto & observer : observers) {
                observer->notify(context);
            }
        }

    private:
        std::list<Observer<Context>*> observers;
    };
}

#endif
