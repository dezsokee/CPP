//
// Created by dezsokee on 12/7/2023.
//

#ifndef LAB11_EXTRA_ORDEREDLIST_H
#define LAB11_EXTRA_ORDEREDLIST_H

#include <functional>
#include <iostream>

using namespace std;

// Class declaration
template<class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

// Class definition
template<class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node(const T &d, Node *n = nullptr, Node *p = nullptr) : data(d), next(n), prev(p) {}
    };

    friend class Iterator<T, LessComp, Equal>;

    Node *first;
    Node *last;
    LessComp less;
    Equal equal;
    int size;
public:
    OrderedList() : first(nullptr), last(nullptr), size(0) {}

    ~OrderedList();

    OrderedList(const OrderedList &other);

    OrderedList &operator=(const OrderedList &other);

    void insert(const T &data);

    void remove(const T &data);

    bool find(const T &data) const;

    int getSize() const { return size; }

    Iterator<T, LessComp, Equal> begin() { return Iterator<T, LessComp, Equal>(*this, first); }

    Iterator<T, LessComp, Equal> end() { return Iterator<T, LessComp, Equal>(*this, nullptr); }

    void listItems(ostream &os) const;
};

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) const {
    Node *act = first;
    while (act != nullptr) {
        os << act->data << " ";
        act = act->next;
    }
    os << endl;

}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T &data) const {
    Node *act = first;
    while (act != nullptr && !equal(act->data, data)) {
        act = act->next;
    }
    return act != nullptr;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &data) {
    Node *act = first;
    while (act != nullptr && !equal(act->data, data)) {
        act = act->next;
    }
    if (act != nullptr) {
        if (act->prev == nullptr) {
            first = act->next;
        } else {
            act->prev->next = act->next;
        }
        if (act->next == nullptr) {
            last = act->prev;
        } else {
            act->next->prev = act->prev;
        }
        delete act;
        size--;
    }

}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList(const OrderedList &other) {
    first = nullptr;
    last = nullptr;
    size = 0;
    Node *act = other.first;
    while (act != nullptr) {
        insert(act->data);
        act = act->next;
    }

}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    Node *act = first;
    while (act != nullptr) {
        Node *next = act->next;
        delete act;
        act = next;
    }
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &data) {
    Node *new_node = new Node(data);
    if (first == nullptr) {
        first = new_node;
        last = new_node;
    } else {
        Node *act = first;
        while (act != nullptr && less(act->data, data)) {
            act = act->next;
        }
        if (act == nullptr) {
            new_node->prev = last;
            last->next = new_node;
            last = new_node;
        } else {
            if (act->prev == nullptr) {
                new_node->next = first;
                first->prev = new_node;
                first = new_node;
            } else {
                new_node->next = act;
                new_node->prev = act->prev;
                act->prev->next = new_node;
                act->prev = new_node;
            }
        }
    }
    size++;

}

// Class definition
template<class T, class LessComp, class Equal>
class Iterator {
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node *act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &l) : list(l), act(l.first) {};

    bool hasNext() const { return act != nullptr; }

    T &next() {
        T &data = act->data;
        act = act->next;
        return data;
    }
};


#endif //LAB11_EXTRA_ORDEREDLIST_H
