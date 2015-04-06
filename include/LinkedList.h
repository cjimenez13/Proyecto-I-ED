#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Array.h"
#include <stdexcept>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename E>
class LinkedList
{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* current;
    int Size;
public:
    LinkedList() {
        head = tail = current = new Node<E>();
        Size = 0;
    }
    ~LinkedList() {
        Clear();
        delete head;
    }

void Insert(E pElement) {
        current->next = new Node<E>(pElement, current->next);
        if (current == tail) {
            tail = tail->next;
        }
        Size++;
    }
void append(E pElement) {
        tail->next = new Node<E>(pElement);
        tail = tail->next;
        Size++;
    }
E Remove() throw(runtime_error) {
        if (current->next == NULL) {
            throw runtime_error("No element to Remove.");
        }
        E result = current->next->element;
        Node<E> *temp = current->next;
        current->next = current->next->next;
        if (temp == tail) {
            tail = current;
        }
        delete temp;
        Size--;
        return result;
    }
void Clear() {
        current = head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
        head = tail = current = new Node<E>();
        Size = 0;
    }
E getElement() throw(runtime_error) {
        if (current->next == NULL) {
            throw runtime_error("No element to get.");
        }
        return current->next->element;
    }
void goToStart() {
        current = head;
    }
void goToEnd() {
        current = tail;
    }

void goToPos(int nPos) throw(runtime_error) {
        if ((nPos < 0) || (nPos > Size)) {
            throw runtime_error("Index out of bounds");
        }
        current = head;
        for (int i = 0; i < nPos; i++) {
            current = current->next;
        }
    }
Node<E>* searchPrevious(Node<E>* pNode) {
        if (current == head) {
            return NULL;
        }
        Node<E> *res = head;
        while (res->next != current) {
            res = res->next;
        }
        return res;
    }
void previous() {
        if (current != head) {
            current = searchPrevious(current);
        }
    }
void next() {
        if (current != tail) {
            current = current->next;
        }
    }
int getPos() {
        int pos = 0;
        Node<E>* temp = head;
        while (temp != current) {
            pos++;
            temp = temp->next;
        }
        return pos;
    }
int getSize() {
        return Size;
    }
};

#endif // LINKEDLIST_H
