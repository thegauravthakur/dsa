#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node *start, *end;

public:

    LinkedList() {
        start = end = nullptr;
    }

    void insertNode(int);

    void printAllNodes();

    int findValue(int); // finds value, if present returns index otherwise returns -1;

    void pop();

    void popFront();

};

void LinkedList::insertNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    if (start == nullptr) start = end = temp;
    else {
        end->next = temp;
        end = temp;
        end->next = nullptr;
    }
}

void LinkedList::printAllNodes() {
    Node *temp = start;
    while (temp != nullptr)
        cout << temp->data << ' ', temp = temp->next;
}

int LinkedList::findValue(int value) {
    Node *temp = start;
    int index{0};
    while (temp != nullptr) {
        if (temp->data == value)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
}

void LinkedList::pop() {
    Node *temp = start;
    if (temp->next == nullptr) start = end = nullptr;
    else {
        while (temp->next->next != nullptr)
            temp = temp->next;
        end = temp;
        end->next = nullptr;
    }
}

void LinkedList::popFront() {
    start = start->next;
}

int main() {
    LinkedList ll;
    ll.insertNode(22);
    ll.insertNode(232);
    ll.insertNode(2);
    ll.insertNode(122);
    ll.insertNode(202);

    ll.printAllNodes();
    ll.pop();
    cout << endl;
    ll.printAllNodes();
    ll.pop();
    cout << endl;
    ll.printAllNodes();

}