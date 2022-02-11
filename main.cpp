#include <iostream>
#include <vector>
std::string offset;
class Person {
public:
    std::string Name;
    int Age;

    Person(std::string name, int age)
    {

        this->Name = name;
        this->Age = age;
    }
};
// component
class Employee : public Person {
public:
    Employee *parent = nullptr;

    Employee(const std::string &name, int age) : Person(name, age)
    {}

    virtual void work()
    {};
};
// leaf
class Programmer : public Employee {
public:
    Programmer(const std::string &name, int age) : Employee(name, age)
    {}

    void work() override
    {

        std::cout << offset << this->Name << ": Im coding!" << std::endl;
    }
};

////composite with infinite recursion
//class Manager : public Employee {
//public:
//    std::vector<Employee*> children;
//
//    Manager(const std::string &name, int age) : Employee(name, age)
//    {}
//
//    void add(Employee *const e)
//    {
//        children.push_back(e);
//    }
//    void work() override
//    {
//        std::cout << offset << this->Name << ": Im managing!" << std::endl;
//        offset.append("\t");
//        for (auto &child: children)
//        {
//            /*if(child.Name != this->Boss.Name){
//                child.work();
//            }*/
//            child->work();
//        }
//    }
//};

//composite without infinite recursion
class Manager : public Employee {
public:
    std::vector<Employee *> children;

    Manager(const std::string &name, int age) : Employee(name, age)
    {}

    void add(Employee *const e)
    {

        if(e != this->parent)
        {
            e->parent = this;
            children.push_back(e);
        }
    }

    void work() override
    {

        std::cout << offset << this->Name << ": Im managing!" << std::endl;
        offset.append("\t");
        for (auto &child: children)
        {
            if(child != this->parent)
            {
                child->work();
            }
        }
    }
};

void drive(Employee *emp)
{

    emp->work();
}

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


int main()
{
    //Composite
    /*Manager* man1 = new Manager("Suzan", 35);
    Manager* man2 = new Manager("Dylan", 23);
    Programmer* prog1 = new Programmer("Bob",27);
    Programmer* prog2 = new Programmer("kevin",22);
    man1->add(prog1);
    man1->add(prog2);
    man1->add(man2);
    man2->add(new Programmer("Hughie",13));
    man2->add(new Programmer("Laurie",63));
    man2->add(man1);
    drive(man1);*/

    //Decorator
    hamburger hamb = hamburger();
    Food* f1 = new withTomato(new hamburger);
    Food* f2 = new withCheese(new withLettuce (new withTomato(new hamburger)));
    std::cout<<"Base price: "<<hamb.getPrice()<<std::endl;
    std::cout<<"With Tomato price: "<<f1->getPrice()<<std::endl;
    std::cout<<"All toppings price: "<<f2->getPrice()<<std::endl;
    delete f1;
    delete f2;
    return 0;
}
