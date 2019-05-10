#ifndef BASE_H
#define BASE_H

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual void execute() = 0;
        virtual void print() = 0;
        virtual void parse() = 0;
        virtual void connector() = 0;
};



#endif
