#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include "Observer.hpp"

namespace s2 {
    template<typename T>
    class Observable {
    public:
    // TODO: Add 'property' support
        void addObserver(/*std::string_view property, */Observer<T>& observer) {
            observers.push_back(&observer);
        }

        void removeObserver(/*std::string_view property, */Observer<T>& observer) {
            observers.remove(&observer);
        }

        void notifyObservers(/*std::string_view property, */T& context) {
            for (auto & observer : observers) {
                (*observer)(context);
            }
        }

    private:
        std::list<Observer<T>*> observers;
    };
}

#endif
