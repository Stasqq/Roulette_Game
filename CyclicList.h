//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_CYCLICLIST_H
#define ROULETTE_PROI_V2_CYCLICLIST_H


#include <iostream>

template <class T>
struct Node{
    T item;
    struct Node * next;
};

template <class T>
class CyclicList {
private:
    struct Node<T> * head;
public:
    CyclicList<T>();
    CyclicList<T>(CyclicList<T> &);
    ~CyclicList<T>();
    CyclicList<T>& operator=(CyclicList<T> const&);

    T* getByIndex(int);
    void pushBack(T);
    int size();
};

template <class T>
CyclicList<T>::CyclicList() {
    head= nullptr;
}

template <class T>
CyclicList<T>::CyclicList(CyclicList<T> &from) {
    CyclicList<T> *tmpCL;
    tmpCL = new CyclicList();
    struct Node<T> *tmpP;
    tmpP=from.head;

    if(tmpP != nullptr){
        do{
            tmpCL -> pushBack( tmpP->item );
            tmpP = tmpP -> next;
        }while(tmpP != from.head);
    }

    head = from.head;
}

template <class T>
CyclicList<T>::~CyclicList<T>() {
    if(head != nullptr) {
        if (head->next != head) {
            struct Node<T> *cPtr = head->next;
            struct Node<T> *sPtr;
            while (cPtr != head) {
                sPtr = cPtr;
                cPtr = cPtr->next;
                delete sPtr;
            }
        }
        delete head;
        head = nullptr;
    }
}

template <class T>
CyclicList<T>& CyclicList<T>::operator=(CyclicList<T> const& from){
    this->head= nullptr;
    struct Node<T>* cPtr;
    cPtr = from.head;
    if(from.head != nullptr){
        do{
            this->pushBack(cPtr->item);
            cPtr=cPtr->next;
        }while(cPtr != from.head);
    }

    head=this->head;
    return *this;
}

template <class T>
T* CyclicList<T>::getByIndex(int index) {
    struct Node<T>* cPtr=head;
    for(int i=0;i<index;i++){
        cPtr=cPtr->next;
    }
    return &cPtr->item;
}

template <class T>
void CyclicList<T>::pushBack(T newItem) {
    struct Node<T> *tmp;
    tmp = new struct Node<T>;
    if(head == nullptr){
        head=tmp;
        tmp->item=newItem;
        tmp->next=head;
    }else{
        tmp=head;
        do{
            tmp=tmp->next;
        }while(tmp->next != head);
        Node<T> *newNode;
        newNode= new Node<T>;
        tmp->next=newNode;
        newNode->item=newItem;
        newNode->next=head;
    }
}

template <class T>
int CyclicList<T>::size() {
    if(head != nullptr) {
        if(head == head->next)
            return 1;
        if(head == head->next->next)
            return 2;
        struct Node<T> *cPtr;
        cPtr = head;
        int counter = 1;
        do {
            counter++;
            cPtr = cPtr->next;
        } while (cPtr->next != head);

        return counter;
    }
    return 0;
}

#endif //ROULETTE_PROI_V2_CYCLICLIST_H
