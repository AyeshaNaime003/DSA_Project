#ifndef BST_TEMPLATE_H_
#define BST_TEMPLATE_H_
#include<iostream>
#include<string>
#include"movie_class.cpp"
using namespace std;

/*
 * AUTHOR: AYESHA SHAMIM NAIME
 */
// STRUCTURE FOR GENERIC TREE NODE
template<class T>
struct  TreeNode{
    T data; // INSTANCE OF AN OBJECT
    TreeNode* right = NULL; // RIGHT CHILD POINTER->DEFAULT=NULL
    TreeNode* left = NULL; // LEFT CHILD POINTER->DEFAULT=NULL

    // DEFAULT CONSTRUCTOR
    TreeNode() {

    }

    // PARAMETRIZED CONSTRUCTOR
    TreeNode(T d) {
        data = d;
    }
};

// STRCUTURE FOR GENERIC BINARY SERACH TREE
template<class T>
struct BST{
    // DATA MEMBERS
    TreeNode<T>* root = NULL; // by default root points to NULL
    
    // FUNCTION TO TRAVERSE THE TREE IN left->root->right order
    // PARAMETERS: The root node
    // RETURNS NOTHING
    void inOrderTraversal(TreeNode<T>* n) {
        if (n != NULL) {
            inOrderTraversal(n->left);
            cout<< n->data <<",\n";
            inOrderTraversal(n->right);
        }
    }
    // WRAPPER FUCNTION FOR INORDER TRAVERSAL
    void inOrderTraversal() {
        inOrderTraversal(root);
    }
    // FUNCTION TO TRAVERSE THE TREE IN right->root->left order (descending order)
    // PARAMETERS: The root node
    // RETURNS NOTHING
    void reverseInOrder(TreeNode<Movie>* n) {
        if (n != NULL) {
            reverseInOrder(n->right);
            cout<< n->data <<endl;
            reverseInOrder(n->left);
        }
    }
    // WRAPPER FUCNTION FOR INORDER TRAVERSAL
    void reverseInOrder() {
        reverseInOrder(root);
    }
    // FUCNTION TO INSERT A NODE OF A CERTAIN DATA TYPE
    // PARAMETERS: The value to be inserted
    // RETURNS NOTHING
    void insert(T &key){
        // CREATE NEW NODE, ASSIGN VALUE
        TreeNode<T>* newNode = new TreeNode<T>();
        newNode->data=key;
        // cout<< newNode->data<<endl;
        if(root==NULL){ // FIRST NODE: BECOME THE ROOT
            root = newNode;
        }else{ // TWO POINTERS NEEDED FOR TRAVERSAL
            TreeNode<T>* p = root;     
            TreeNode<T>* q = NULL;
            while(p!=NULL){
                q = p;
                if(key>p->data){
                    p=p->right;
                }else {
                   p=p->left;
                }// BY THE END OF THE WHILE LOOP, Q WILL BE RIGHT EBHIND P
            }
            if(key>q->data){
                q->right=newNode;
            }else {
                q->left=newNode;
            }
        }
    }
};
#endif