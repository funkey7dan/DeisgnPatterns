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
    Employee* parent = nullptr;
    Employee(const std::string &name, int age) : Person(name, age)
    {}

    virtual void work(){};
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
    std::vector<Employee*> children;

    Manager(const std::string &name, int age) : Employee(name, age)
    {}

    void add(Employee *const e)
    {
        if(e!= this->parent){
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
            if(child != this->parent){
                child->work();
            }
        }
    }
};

void drive(Employee *emp){
    emp->work();
}

int main()
{

    Manager* man1 = new Manager("Suzan", 35);
    Manager* man2 = new Manager("Dylan", 23);
    Programmer* prog1 = new Programmer("Bob",27);
    Programmer* prog2 = new Programmer("kevin",22);
    man1->add(prog1);
    man1->add(prog2);
    man1->add(man2);
    man2->add(new Programmer("Hughie",13));
    man2->add(new Programmer("Laurie",63));
    man2->add(man1);
    drive(man1);
    return 0;
}
