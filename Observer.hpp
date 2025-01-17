#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace s2 {
    template<typename Context>
    class Observer {
    public:
        virtual void notify(Context context) = 0;
    };
}

#endif
