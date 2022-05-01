#include<iostream>
#include<string>
#include"actor_class.cpp"
#include"bst_template.cpp"
struct ActorHashMap{
    // DATA MEMBERS
    BST<Actor> hash_map[26];
    // NO ARGUMENT CONSTRUCTORS
    ActorHashMap(){
    }
    // FUNCTIONS
    // CALCULATES HASHVALUE FROM THE ACTOR'S NAME
    int getHashValue(string n){
        string name_copy = n;
        transform(name_copy.begin(), name_copy.end(), name_copy.begin(), ::tolower);
        char first_letter = name_copy[0];
        return int(first_letter) - 97;
    }
    // CREATES INSTANCE OF ACTOR AND INSERTS IN THE HASHMAP IF NOT ALREADY PRESENT
    void insert(string n, BST<Movie> &mt){ // FUNCTIONS TAKES THE ACTORS NAME AND THE MOVIE BST
        int hash_value = getHashValue(n); 
        cout << "Index: " << hash_value << endl;
        if(getActor(n, hash_value, false)==NULL){ // CHECK IF ACTOR IN BST, IF NOT MAKE INSTANCE AND ADD TO THE TREE, PROFILE NOT NEEDED->BOOL VLAUE FALSE
            Actor actor(n, mt); // CREATE INSTANCE
            (hash_map[hash_value]).insert(actor);
        }else{
            cout << n << " already present in actor tree\n";
        }
    }
    // FUNCTION TO GET ACTOR OBJECT FROM THE ACTOR_HASH_MAP, IF DOESNT EXIST, RETURN NULL
    Actor* getActor(string n, int i, bool needprofile){
        // CREATE POINTER FOR TREE NODE OF ACTOR TEMPLATE TRAVERSAL
        TreeNode<Actor>* p = hash_map[i].root;
        while(p!=NULL && p->data.get_actor_name()!=n){
            if(p->data.get_actor_name() < n){
                p=p->right;
            }else if(p->data.get_actor_name() > n){
                p=p->left;
            }
        } // P POINTS TO NULL OR TARGET NODE
        if(p==NULL){
            return NULL; // ACTOR DOESN'T EXIST IN THE TREE
        }else{
            if(needprofile){ // IF CALLED FROM SEARCH_ACTOR_PROFILE(), PRINT THE NUMBER OF MOVIES ACTOR HASS BEEN IN AND THE TITLES
                cout << "ACTOR'S NAME: " << n << endl;
                cout << "NUMBER OF MOVIES WORKED IN: " << p->data.get_actor_movie_count_() << endl;
                cout << "LIST OF MOVIES IN CHRONOLOGICAL ORDER: " << endl;
                // ITERATIVE INORDER TRAVERSAL
                p->data.displayMovies();
            }
            return &(p->data); // ACTOR DOES EXIST IN THE TREE
        }
    }
    // SEARCES THE ACTORS AND PRINTS PROFILE
    void getActorProfile(string n){
        if(!getActor(n, getHashValue(n), true)){
            cout << "NO SUCH ACTOR IN THE ACTOR HASH MAP\n";
        }
    }
    // SEARCHES ACTOR AND DISPLAYS THE COACTORS: WILL BE REPEATED
    void getCoactors(string n){
        Actor curr_actor = *(getActor(n, getHashValue(n), false));
        curr_actor.display_coactors();
    }
    // SEACHES ONE ACTOR AND SEE'S IF ACTOR1 HAS ACTED WITH ACTOR2 IN ANY MOVIE
    void actedTogether(string n1, string n2){
        // GET ACTOR1'S OBJECT FROM GET_ACTOR()
        // TRAVERSE THROUGH THE ACTOR'S OBJECT'S MOVIE POINTER BST TO CHECK IF ACTOR2 IS ACTOR1'S COACTOR IN ANY MOVIE 
        Actor* curr_actor = getActor(n1, getHashValue(n1), false); // GET ACTOR1'S OBJECT
        if(curr_actor!=NULL){
            curr_actor->check_coactor(n2);
        }
    }
};