 #ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

template <typename E>
class ArrayList
{
private:
    E* elements;
    int Max;
    int Size;
    int pos;
public:
    ArrayList(int pMax = DEFAULT_MAX_SIZE) {
        elements = new E[pMax];
        Max = pMax;
        Size = 0;
        pos = 0;
    }

     ~ArrayList() {
        delete [] elements;
    }



void Insert(E pElement) throw(runtime_error) {
        if (Size == Max) {
            throw runtime_error("List full");
        }
        for (int i = Size; i > pos; i--) {
            elements[i] = elements[i - 1];
        }
        elements[pos] = pElement;
        Size++;
    }
void append(E pElement) throw(runtime_error) {
        if (Size == Max) {
            throw runtime_error("List full");
        }
        elements[Size] = pElement;
        Size++;
    }
E Remove() throw(runtime_error) {
        if (Size == 0) {
            throw runtime_error("Empty list");
        }
        if ((pos < 0) || (pos >= Size)) {
            throw runtime_error("Index out of bounds");
        }
        E res = elements[pos];
        for (int i = pos; i < Size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        Size--;
        return res;
    }
void Clear() {
        Size = 0;
        pos = 0;
        delete [] elements;
        elements = new E[Max];
    }
E getElement() throw(runtime_error) {
        if ((pos < 0) || (pos > Size)) {
            throw runtime_error("Index out of bounds");
        }
        return elements[pos];
    }
void goToStart() {
        pos = 0;
    }

void goToEnd() {
        pos = Size-1;
    }

void goToPos(int pPos) throw(runtime_error) {
        if ((pPos < 0) || (pPos > Size)) {
            throw runtime_error("Index out of bounds");
        }
        pos = pPos;
    }
void previous() {
        if (pos > 0) {
            pos--;
        }
    }

void next() {
        if (pos < Size) {
            pos++;
        }
    }
int getPos() {
        return pos;
    }

int getSize() {
        return Size;
    }
void print(){
    if (Size==0){
        cout<< "[  ]"<<endl;
    }else {
    int position=pos;
    pos=0;
    while (pos != Size){
        if (pos==0){
            cout << "[ ";
        }
        if (pos==position){
            cout<<"*";
        }
        cout<<getElement()<<"  ";
        next();
    }
    cout<<" ]";

    pos = position;
    }
    cout << ""<<endl;
    }
void printE(){
    if (Size==0){
        cout<<"\n"<< "El historial esta vacío"<<endl;
    }else {
    int position=pos;
    pos=0;
    cout<<"\n"<< "El historial es"<<"\n"<<endl;
    while (pos != Size){
        cout<<"\t"<<pos+1<<". "<<getElement()<<endl;
        next();
    }

    pos = position;
    }
    cout << ""<<endl;
    }

};
#endif  //ARRAYLIST_H
