#include <iostream>
#include <vector>
#include "composite.h"
#include "decorator.h"
#include "factory.h"
#include "adapter.h"
#include "iterator.h"
#include <map>



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

    // factory + map
    /*std::map<std::string,Creator*> myMap;
    myMap.insert(std::pair<std::string,Creator*>("one",new concreteCreator1()));
    myMap.insert(std::pair<std::string,Creator*>("two",new concreteCreator2()));
    myMap.insert(std::pair<std::string,Creator*>("three",new concreteCreator3()));
    std::cout<<myMap.find("one")->second->generate()->doThing()<<std::endl;
    std::cout<<myMap.find("two")->second->generate()->doThing()<<std::endl;
    std::cout<<myMap.find("three")->second->generate()->doThing()<<std::endl;*/

    //Object Adapter
    RoundHole wholeHole = RoundHole(69);
    SquarePeg square = SquarePeg(700);
    SquarePegAdapter SquareAdpater = SquarePegAdapter(square);
    ClassAdapter adapter = ClassAdapter();
    std::cout<<wholeHole.fits(SquareAdpater)<<std::endl;

    //Class Adapter
    std::cout<<wholeHole.fits(*adapter.adapt(square))<<std::endl;

    return 0;
}
