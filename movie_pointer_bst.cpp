#ifndef MOVIE_POINTER_BST_CPP
#define MOVIE_POINTER_BST_CPP
#include<iostream>
#include<stack>
#include<string>
#include"bst_template.cpp"
struct MoviePointerTreeNode{
    Movie* data;
    MoviePointerTreeNode* left = NULL;
    MoviePointerTreeNode* right = NULL;
};
// BST OF MOVIE* DATA TYPE
struct MoviePointerBST{
    // INSTANCE VARIABLES OF MOVIE* BST
    MoviePointerTreeNode* root = NULL;
    // FUNCTIONS
    public:
        // FUNCTION TO INSERT MOVIE POINTER TO THE ACTOR_MOVIE_TREE_
        void insert(Movie* mp){
            // CREATE NEW NODE, ASSIGN VALUE
            MoviePointerTreeNode* newNode = new MoviePointerTreeNode();
            newNode->data=mp;
            // cout<< newNode->data<<endl;
            if(root==NULL){ // FIRST NODE: BECOME THE ROOT
                root = newNode;
            }else{ // TWO POINTERS NEEDED FOR TRAVERSAL
                MoviePointerTreeNode* p = root;     
                MoviePointerTreeNode* q = NULL;
                while(p!=NULL){
                    q = p;
                    if(mp->title_year_ > p->data->title_year_){ // COMPARING THE TITLE YEAR OF THE MOVIE THE POINTER IS POINTING TO 
                        p=p->right;
                    }else {
                        p=p->left;
                    }// BY THE END OF THE WHILE LOOP, Q WILL BE RIGHT EBHIND P
                }
                if(mp->title_year_ > q->data->title_year_){
                    q->right=newNode;
                }else {
                    q->left=newNode;
                }
            }
        }
        // GETTERS
};
#endif