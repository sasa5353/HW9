//
// Created by alex on 10.03.2020.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H


#include "ListElement.h"

class List {
private:
    ListElement *first;
    ListElement *last;
    
    void push(ListElement *);
    
    void popBack();

public:
    List();
    
    ~List();
    
    List(double *, double *);
    
    ListElement *getFirst();
    
    ListElement *getLast();
    
    void add(double);
    
};


#endif //UNTITLED_LIST_H
