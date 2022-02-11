//
// Created by funke on 2/11/2022.
//

#ifndef AP4TEST_COMPOSITE_H
#define AP4TEST_COMPOSITE_H
#endif //AP4TEST_COMPOSITE_H
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
