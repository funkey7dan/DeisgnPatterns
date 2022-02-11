//
// Created by funke on 2/11/2022.
//

#ifndef AP4TEST_DECORATOR_H
#define AP4TEST_DECORATOR_H
#endif //AP4TEST_DECORATOR_H
// interface - Component
class Food {
public:
    Food()
    {}

    virtual int getPrice() = 0;
};


// base ConcreteComponent
class hamburger : public Food{
    int price = 45;
public:
    virtual int getPrice() override{
        return this->price;
    }
};

//Decorator
class foodWithTops : public Food{
protected:
    Food* food;
public:
    virtual int getPrice() override{
        return food->getPrice();
    }
};

// concrete decorator
class  withTomato : public foodWithTops{
    int price = 3;
    Food* base;
public:

    withTomato(Food *base) : base(base)
    {}

    virtual int getPrice() override{
        return base->getPrice()+price;
    }
};

// concrete decorator
class  withLettuce : public foodWithTops{
    int price = 2;
    Food* base;
public:

    withLettuce(Food *base) : base(base)
    {}

    virtual int getPrice() override{
        return base->getPrice()+price;
    }
};

// concrete decorator
class  withCheese : public foodWithTops{
    int price =10;
    Food* base;
public:

    withCheese(Food *base) : base(base)
    {}

    virtual int getPrice() override{
        return base->getPrice()+price;
    }
};
