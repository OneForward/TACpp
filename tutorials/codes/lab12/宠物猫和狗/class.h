#ifndef CLASS_H
#define CLASS_H

// Your code goes here.

class Pet {
protected: // accessed by inheritance
    char name[20];
    int age;
public: // accessed by caller or inheritance
    Pet() {};
    Pet(const char*, int);
    virtual void print() const = 0;
};


class Cat: public Pet {
public:
    using Pet::Pet; // C++11
    void print() const;
};

class Dog: public Pet {
public:
    using Pet::Pet; // C++11
    void print() const;
};



#endif //CLASS_H
