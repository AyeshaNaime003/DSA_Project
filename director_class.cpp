#include<iostream>
#include<string>
#include<stack>
#include"bst_template.cpp"
#include"linkedlist_template.cpp"
#include"movie_class.cpp"
#include"movie_collection_class.cpp"
#include"movie_pointer_bst.cpp"

/*
 * AUTHOR: FATIMA HUSSAIN
 */

class Director {
    // every director will have a name and bst of movie pointers
    string director_name_;
    MoviePointerBST director_movie_tree_;
    int director_movie_count_ = 0;

    public:
    // DEFAULT CONSTRUCTOR
    Director() {}

    // PARAMETRIZED CONSTRUCTOR
    // It takes the name of the director and initializes their movie tree
    Director(string name, BST<Movie> &movie_tree) {
        director_name_ = name;
        // traversing the movie tree iteratively to find all the movies director has directed
        // stack is used for inorder traversal and a treenode pointer to traverse through the movie tree
        stack<TreeNode<Movie>*> tree_stack;
        TreeNode<Movie>* ptr = movie_tree.root;
        while (ptr != NULL || tree_stack.empty() == false){
            while (ptr !=  NULL){
                // SEEING IF THE MOVIE INSTANCE IN THE CURRENT NODE HAS THE PARTICULAR ACTOR
                if(ptr->data.director_name_==name ){
                    cout << name << " found in " << ptr->data.movie_title_<<endl; 
                    Movie* m = &(ptr->data);
                    // inserting into the bst of movie pointers
                    director_movie_tree_.insert(m);
                } 
                tree_stack.push(ptr);
                ptr = ptr->left;
            }
            ptr = tree_stack.top();
            tree_stack.pop();
            ptr = ptr->right;
        }
    }

    // function to display the movies directed by the director
    // Parameter: none;
    // Returns nothing, displays the movies
    void displayMoviesDirected() {
        // stack of treenode pointers of movie pointer template
        stack<MoviePointerTreeNode*> s;
        MoviePointerTreeNode* curr = director_movie_tree_.root;

        while (curr != NULL || s.empty() == false){
            while (curr !=  NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data->movie_title_ << "\t" << curr->data->title_year_ << ",\n";
            curr = curr->right;
        }
    }
    
    // OPERATOR OVERLOADING
    bool operator==(const Director& m) {
        return director_name_ == m.director_name_;
    }

    bool operator<(const Director& m) {
        if (director_name_ < m.director_name_) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Director& m) {
        if (director_name_ < m.director_name_) {
            return false;
        } else {
            return true;
        }
    }

    friend ostream &operator<<(ostream &output, const Director& m) {
        output << m.director_name_;
        return output;
    }

    // GETTERS
    // function to get the name of the director
    string getDirectorName() {
        return director_name_;
    }

    // function to get the movie bst of the director
    MoviePointerBST* gatDirectorTree() {
        return &director_movie_tree_;
    }

};