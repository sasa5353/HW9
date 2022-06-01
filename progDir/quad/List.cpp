//
// Created by alex on 10.03.2020.
//

#include "List.h"

List::List() {
    first = nullptr;
    last = nullptr;
}

List::~List() {
    delete last;
}

List::List(double *L, double *R) {
    *this = List();
    for (double *p = L; p < R; p++) {
        ListElement *element = new ListElement(*p);
        this->push(element);
    }
}

ListElement *List::getFirst() {
    return first;
}

ListElement *List::getLast() {
    return last;
}

void List::push(ListElement *element) {
    if (first == nullptr && last == nullptr) {
        first = element;
        last = element;
    } else {
        first->setNext(element);
        first = element;
    }
    
}

void List::popBack() {
    if (first == last) first = nullptr;
    ListElement *element = last->getNext();
    last->setNext(nullptr);
    delete last;
    last = element;
}

void List::add(double value) {
    ListElement *element = new ListElement(value);
    push(element);
    popBack();
}
