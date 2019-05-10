#ifndef BASE_H
#define BASE_H

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        /**
        TODO
        **/
        virtual bool execute() = 0;
        virtual string getCommand() = 0;
        // virtual void print() = 0;
        // virtual void parse() = 0;
        // virtual void connector() = 0;
};



#endif
