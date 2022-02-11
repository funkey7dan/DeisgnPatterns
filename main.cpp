#include <iostream>
#include <vector>
#include "composite.h"
#include "decorator.h"
#include "factory.h"



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
    /*hamburger hamb = hamburger();
    Food* f1 = new withTomato(new hamburger);
    Food* f2 = new withCheese(new withLettuce (new withTomato(new hamburger)));
    std::cout<<"Base price: "<<hamb.getPrice()<<std::endl;
    std::cout<<"With Tomato price: "<<f1->getPrice()<<std::endl;
    std::cout<<"All toppings price: "<<f2->getPrice()<<std::endl;
    delete f1;
    delete f2;*/


    return 0;
}
