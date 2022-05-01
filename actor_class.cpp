/*
AUTHOR: AYESHA SHAMIM NAIME
*/
#include<iostream>
#include<string>
#include<stack>
#include"bst_template.cpp"
#include"linkedlist_template.cpp"
#include"movie_class.cpp"
#include"movie_collection_class.cpp"
#include"movie_pointer_bst.cpp"

class Actor{
    // INSTANCE VARIABLES->EVERY ACTOR WILL HAVE A NAME AND BST OF MOVIE POINTERS POINTING TO THE MOVIES THEY HAVE WORKED IN
    string actor_name_;
    MoviePointerBST actor_movie_tree_; // BST OF MOVIE POINTERS // WILL POINT TO THE MOVIE INSTANCE IN THE MOVIE BST
    int actor_movie_count_ = 0; // WILL KEEP TRACK OF THE MOVIES THE ACTOR HAS WORKED IN
    public: 
    // NO ARGUMENT CONSTRUCTOR
    Actor(){}
    // PARAMETRIZED CONSTRUCTOR: TAKES THE ACTOR'S NAME AND THE MOVIE TREE AND INITILZES THE ACTOR_MOVIE_TREE
    Actor(string name, BST<Movie> &movie_tree){
        actor_name_ = name;
        // ITERATIVE TRAVERSAL OF THE MOVIE TREE TO FIND ALL THE MOVIES THE CURRENT ACTOR HAS WORKED IN
        stack<TreeNode<Movie>*> s;
        TreeNode<Movie>* p = movie_tree.root; // TRAVERSAL POINTER
        while (p != NULL || s.empty() == false){
            while (p !=  NULL){
                // SEEING IF THE MOVIE INSTANCE IN THE CURRENT NODE HAS THE PARTICULAR ACTOR
                if(p->data.actor_1_name_==name || p->data.actor_2_name_==name || p->data.actor_3_name_==name){
                    cout << name << " found in " << p->data.movie_title_<<endl; 
                    Movie* m = &(p->data);
                    actor_movie_tree_.insert(m);// INSERT INTO THE BST OF MOVIE POINTERS
                    actor_movie_count_++;
                } 
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            // cout << p->data << endl;
            p = p->right;
        }
    }// FUNCTION TO DISPLAY MOVIES OF THE ACTOR IN CHRONOLOGICAL MANNER
    void displayMovies(){
        // ITERATIVE TRAVERSAL OF THE MOVIE TREE TO FIND ALL THE MOVIES THE CURRENT ACTOR HAS WORKED IN
        stack<MoviePointerTreeNode*> s; 
        MoviePointerTreeNode* p = actor_movie_tree_.root;
        while (p != NULL || s.empty() == false){
            while (p !=  NULL){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            cout << p->data->movie_title_ << "\t" << p->data->title_year_ << ",\n";
            p = p->right;
            }
        }
    void display_coactors(){
        // ITERATIVE TRAVERSAL OF THE MOVIE TREE TO FIND ALL THE MOVIES THE CURRENT ACTOR HAS WORKED IN
        stack<MoviePointerTreeNode*> s;
        MoviePointerTreeNode* p = actor_movie_tree_.root; // TREENODE POINTER TO TRAVERSE THROUGH THE MOVIE TREE
        while (p != NULL || s.empty() == false){
            while (p !=  NULL){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            cout << "Movie Name: " << p->data->movie_title_ <<"\t Co-actors: ";
            if(p->data->actor_1_name_!=actor_name_){
                cout << p->data->actor_1_name_ << "\t";
            }if(p->data->actor_2_name_!=actor_name_){
                cout << p->data->actor_2_name_ << "\t";
            }if(p->data->actor_3_name_!=actor_name_){
                cout << p->data->actor_3_name_ << "\t";
            }
            cout << endl;
            p = p->right;
        }
    }
    // CHECKS IF THE CURRENT ACTOR IS COACTOR OF THE ACTOR2 PASSED IN ARGUMENT
    void check_coactor(string n2){
        // ITERATIVE TRAVERSAL OF THE MOVIE TREE TO FIND ALL THE MOVIES THE CURRENT ACTOR HAS WORKED IN
        LinkedList<string> collaborated_movies; // IF THE TWO ACTORS HAVE WORKED TOGTHER: THE LINKEDLIST WILL HOLD ALL THE MOVIE'S NAMES
        stack<MoviePointerTreeNode*> s;
        MoviePointerTreeNode* p = actor_movie_tree_.root; // TREENODE POINTER TO TRAVERSE THROUGH THE MOVIE TREE
        while (p != NULL || s.empty() == false){
            while (p !=  NULL){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(p->data->actor_1_name_==n2 || p->data->actor_2_name_==n2 || p->data->actor_3_name_==n2){
                collaborated_movies.insert(p->data->movie_title_);
            }
            p = p->right;
        }
        // PRINTING THE COLLABORATED MOVIES
        if(collaborated_movies.count==0){
            cout << actor_name_ << " and " << n2 << " have never worked together in a movie";
        }else{
            collaborated_movies.display();
        }
    }
    // OPERATOR OVERLOADING
    bool operator==(const Actor& m) {
        return actor_name_ == m.actor_name_;
    }
    bool operator<(const Actor& m) {
        if (actor_name_ < m.actor_name_) {
            return true;
        } else {
            return false;
        }
    }
    bool operator>(const Actor& m) {
        if (actor_name_ < m.actor_name_) {
            return false;
        } else {
            return true;
        }
    }
    friend ostream &operator<<(ostream &output, const Actor& m) {
        output << m.actor_name_;
        return output;
    }
    // GETTERS
    string get_actor_name(){
        return actor_name_;
    }
    MoviePointerBST* get_actor_movie_tree(){
        return &actor_movie_tree_;
    }
    int get_actor_movie_count_(){
        return actor_movie_count_;
    }
};
