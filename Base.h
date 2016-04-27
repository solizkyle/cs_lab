#ifndef BASE_H
#define BASE_H
class Base{
    public:
        /* Constructors */
        Base() {}
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};
#endif