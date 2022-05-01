#include<iostream>
#include<string>
#include"director_class.cpp"
#include"bst_template.cpp"

/*
 * AUTHOR: FATIMA HUSSAIN
 */
// TREE NODE OF MOVIE* DATA

struct DirectorHashMap {
    // data members 
    // creating a hash map of 26 letters
    BST<Director> hash_map[26];

    // DEFAULT CONSTRUCTOR
    DirectorHashMap() {}

    // FUNCTIONS
    // function to get the hash value on the basis of the first letter of the director
    // Parameters: name of the director
    // Returns the hash value
    int getHashValue(string name) {
        string name_copy = name;
        transform(name_copy.begin(), name_copy.end(), name_copy.begin(), ::tolower);
        char first_letter = name_copy[0];
        return int(first_letter) - 97;
    }

    // function to insert a director name to its respective movie bst in the hash map
    // Parameters: director name and the movie bst in which all the movies were storeed originally
    // Returns nothing, inserts director into the hash map if they exist
    void insert(string name, BST<Movie> &movie_tree) {
        int hash_value = getHashValue(name);
        if (getDirector(name, hash_value) == NULL) {
            // creating an instance of the director to insert into the hash map
            Director director(name, movie_tree);
            (hash_map[hash_value]).insert(director);
        } else {
            cout<< name << " already present in the director hash map.\n";
        }
    }

    // function to check if director exists in the movie bst
    Director* getDirector(string name, int i) {
        // creating a pointer tree node for actor template traversal
        // it will point to the node in which the director was found or be null
        TreeNode<Director>* p = hash_map[i].root;
        while(p!=NULL && p->data.getDirectorName()!=name){
            if(p->data.getDirectorName() < name){
                p=p->right;
            }else if(p->data.getDirectorName() > name){
                p=p->left;
            }
        }
        // if the actor does not exist
        if (p == NULL) {
            return  NULL;
        } // if the director does exist in the tree 
        else {
            return &(p->data);
        }
    }

    
};
