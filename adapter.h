//
// Created by funke on 2/13/2022.
//
#include <math.h>
#ifndef AP4TEST_ADAPTER_H
#define AP4TEST_ADAPTER_H

#endif //AP4TEST_ADAPTER_H


class RoundPeg{
    int radius;
public:
    explicit RoundPeg(int radius){
        this->radius = radius;
    }
    RoundPeg(){};

    virtual int getRadius(){
        return this->radius;
    }
};

class SquarePeg{
    int width;
public:
    SquarePeg(int width){
        this->width = width;
    }
    SquarePeg(){};
    int getWidth(){
        return this->width;
    }
};

class RoundHole{
    int radius;
public:
    RoundHole(int radius){this->radius = radius;}
    int GetRadius(){
        return this->radius;
    }
    bool fits(RoundPeg& peg){
        return peg.getRadius()<=this->radius;
    }
};

// object adapter
class SquarePegAdapter:public RoundPeg{
    SquarePeg peg;
public:
    SquarePegAdapter(const SquarePeg &peg2){
        this->peg = peg2;
    }
    int getRadius() override{
        return peg.getWidth()*sqrt(2)/2;
    }
};

//class adapter
class ClassAdapter: public RoundPeg,SquarePeg{
public:
    ClassAdapter(): RoundPeg(0) ,SquarePeg(0){
    };
    RoundPeg* adapt(SquarePeg peg){
        return new RoundPeg(peg.getWidth()*sqrt(2)/2);
    }
};

