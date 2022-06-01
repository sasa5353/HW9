//
// Created by alex on 10.03.2020.
//

#include "ListElement.h"

ListElement::ListElement(double _value) {
    value = _value;
    next = nullptr;
}

double ListElement::getValue() {
    return value;
}

void ListElement::setValue(double _value) {
    value = _value;
}

ListElement *ListElement::getNext() {
    return next;
}

void ListElement::setNext(ListElement *_next) {
    next = _next;
}

ListElement::~ListElement() {
    delete next;
}
