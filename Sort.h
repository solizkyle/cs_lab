#ifndef SORT_H
#define SORT_H
class Container;
class Sort {
    public:
        /* Constructors */
        //Sort();
        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};
#endif