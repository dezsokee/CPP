#include "List.h"

List::List() {
    first = nullptr;
}

List::~List() {
    Node *temp;
    while(first) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

bool List::exists(int d) const {
    Node *temp = first;
    while(temp) {
        if(temp->value == d) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    Node* newNode = new Node(d, nullptr);

    if (first == nullptr) {
        first = newNode;
    } else {
        newNode->next = first;
        first = newNode;
    }

    nodeCounter++;
}

int List::removeFirst() {
    if (first == nullptr) {
        throw  "List is empty";
    }

    Node* temp = first;
    int value = first->value;
    first = first->next;
    delete temp;

    nodeCounter--;

    return value;
}

void List::remove(int d, List::DeleteFlag df) {
    Node* temp = first;
    Node* prev = nullptr;

    while(temp) {
        if (temp->value == d) {
            if (prev == nullptr) {
                first = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            nodeCounter--;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

}
