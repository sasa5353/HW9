//
// Created by alex on 10.03.2020.
//

#ifndef UNTITLED_LISTELEMENT_H
#define UNTITLED_LISTELEMENT_H


class ListElement {
private:
    ListElement *next;
    double value;

public:
    ListElement(double);
    
    ~ListElement();
    
    ListElement *getNext();
    
    void setNext(ListElement *);
    
    double getValue();
    
    void setValue(double);
};


#endif //UNTITLED_LISTELEMENT_H
