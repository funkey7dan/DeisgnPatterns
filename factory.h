//
// Created by funke on 2/11/2022.
//

#ifndef AP4TEST_FACTORY_H
#define AP4TEST_FACTORY_H
#endif //AP4TEST_FACTORY_H

class Product{
public:
    ~Product()=default;
    virtual std::string doThing() = 0;
};

class concreteProduct1 : public Product{
    ~concreteProduct1()= default;
std::string doThing() override{
    return "Concrete one yeah!";
}
};

class concreteProduct2 : public Product{
    ~concreteProduct2()= default;
    std::string doThing() override{
        return "Concrete two oh yeah!";
    }
};

class concreteProduct3 : public Product{
    ~concreteProduct3()= default;
    std::string doThing() override{
        return "Concrete three in the house!";
    }
};


// abstract creator
class Creator{
public:
    virtual Product* generate() = 0;
};


class concreteCreator1 : public Creator{
public:
    Product* generate() override{
        return new concreteProduct1;
    }
};

class concreteCreator2 : public Creator{
public:
    Product* generate() override{
        return new concreteProduct2;
    }
};

class concreteCreator3 : public Creator{
public:
    Product* generate() override{
        return new concreteProduct3;
    }
};



