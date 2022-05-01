#ifndef LINKEDLIST_TEMPLATE_H_
#define LINKEDLIST_TEMPLATE_H_
#include<iostream>
#include<string>
using namespace std;

// STRUCTURE FOR GENERIC LINKED LIST NODE
// Can have an object fo any class as data and a pointer pointing to another node
template<class T>
struct LinkedListNode{
        // data members
        T data;
        LinkedListNode* next;
};
// STRCUTURE FOR GENERIC LINKED LIST
template<class T>
struct LinkedList{
    // data members
    LinkedListNode<T>* root=NULL; // by default, root points to null
    int count = 0;
    // FUNCTION TO INSERT A NEW NODE 
    // PARAMETERS: The value to be inserted
    // RETURNS NOTHING
    void insert(T key){
        LinkedListNode<T>* newNode = new LinkedListNode<T>();
        newNode->data=key;
        if(!root){
            root=newNode;
        }else{
            // pointer for traversal
            LinkedListNode<T>* p = root;
            while(p->next!=NULL){
                p=p->next;
            }// will stop at the last node
            p->next=newNode;
        }
        count++;
    }
    
    // FUNCTION TO SEARCH FOR THE SPECIFIED VALUE
    // PARAMETERS: The value to be searched
    // RETURNS THE NODE WITH THW SPECIFIED VALUE
    LinkedListNode<T>* search(T k){
        // pointer for traversal
        LinkedListNode<T>* p = root;
        while(p!=NULL && p->data!=k){
            cout << p->data << endl;
            p=p->next;
        }// will stop at the last node
        if(p->data==k){
            return p;
        }else{
            return NULL;
        }
    }
    
    // FUNCTION TO DISPLAY ALL THE ELEMENTS OF THE LINKED LIST
    void display(){
        // pointer to traverse
        LinkedListNode<T>* p = root;
        while(p!=NULL){
            cout << p->data << "\t";
            p=p->next;
        }
        cout << endl;
    }
};

#endif