#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace s2 {
    template<typename T>
    class Observer {
    public:
        virtual void operator()(T& context) = 0;
    };
}

#endif
