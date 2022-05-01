#ifndef MOVIE_COLLECTION_CLASS_CPP_
#define MOVIE_COLLECTION_CLASS_CPP_
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>
#include"bst_template.cpp"
#include"movie_class.cpp"
#include"actor_hash_map_class.cpp"
#include"director_hash_map_class.cpp"
#include"movie_pointer_bst.cpp"
using namespace std;

/*
 * AUTHOR: FATIMA HUSSAIN
 */

// MovieCollection class
// this class provides a method to read the csv file, 
// store information regarding each movie into an object of Movie, 
// and insert each of these objects into a BST node, 
// and form a BST of movies on the basis of year.

class MovieCollection {
    // BINARY SERACH TREE FOR STORING MOVIES
    // KEY: YEAR
    BST<Movie> movie_bst_;

    public:
    // function to check if the string is a number or not
    // Parameter: the string to be checked
    // Returns a boolean value, true if the string is a number and false otherwise
    bool isNumber(string number_) {
        for (int i = 0; i < number_.length(); i++) {
            if (! ((number_[i] >= 48 && number_[i] <= 57) || number_[i] == ' ' || number_[i] == '.')) {
                return false;
            }
        }
        return true;
    }

    // function to read the file and construct the movie BST
    // It has no parameters and returns nothing
    // It only inserts nodes into the movie BST
    BST<Movie> createMovieBST() {
        // variables required for reading the file line by line and word by word
        string line, token;

        // opening file using the constructor 
        ifstream in("IMDB_Top5000-SEECS.csv");

        // reading the first line which contain headers only so it is not stored
        getline(in, line);

        // parsing the file 
        for (int i = 0; i < 100; i++) {
            // creating a movie object
            Movie current_movie;

            // read an entire row and
            // store it in the 'line' variable
            getline(in, line);

            // creating a stream object from each line
            istringstream stream(line);

            // storing the information in a movie node
            int count = 0;
            while(getline(stream, token, ',')) {
                
                // if the token is a number
                if (isNumber(token)) {
                    // creating a stream object for conversion from string to number
                    stringstream number(token);

                    // TITLE YEAR
                    if (count == 2) {
                        // number >> current_movie.title_year_;
                        current_movie.title_year_ = stoi(token); 
                    } // IMDB SCORE
                    else if (count == 3) {
                        number >> current_movie.imdb_score_;
                    } // DIRECTOR FACEBOOK LIKES
                    else if (count == 5) {
                        number >> current_movie.director_facebook_likes_;
                    } // NUMBER OF CRITICS
                    else if (count == 6) {
                        number >> current_movie.num_critic_for_reviews_;
                    } // DURATION
                    else if (count == 7) {
                        number >> current_movie.duration_;
                    } // ACTOR 1 FB LIKES
                    else if (count == 9) {
                        number >> current_movie.actor_1_facebook_likes_;
                    } // ACTOR 2 FB LIKES
                    else if (count == 11) {
                        number >> current_movie.actor_2_facebook_likes_;
                    } // ACTOR 3 FB LIKES
                    else if (count == 13) {
                        number >> current_movie.actor_3_facebook_likes_;
                    } // GROSS
                    else if (count == 14) {
                        number >> current_movie.gross_;
                    } // NUMBER OF VOTED USERS
                    else if (count == 15) {
                        number >> current_movie.num_voted_users_;
                    } // CAST TOTAL FACEBOOK LIKES
                    else if (count == 16) {
                        number >> current_movie.cast_total_facebook_likes_;
                    } // FACENUMBER IN POSTER
                    else if (count == 17) {
                        number >> current_movie.facenumber_in_poster_;
                    } // NUMBER OF USERS FOR REVIEWS
                    else if (count == 20) {
                        number >> current_movie.num_user_for_reviews_;
                    } // BUDGET
                    else if (count == 24) {
                        number >> current_movie.budget_;
                    } // ASPECT RATIO
                    else if (count == 25) {
                        number >> current_movie.aspect_ratio_;
                    } // MOVIE FACEBOOK LIKES
                    else if (count == 26) {
                        number >> current_movie.movie_facebook_likes_;
                    }
                } // if the token is a string
                else {
                    // MOVIE TITLE
                    if (count == 0) {
                        current_movie.movie_title_ = token.substr(0, (token.length() - 1));
                    } // MOVIE GENRES 
                    else if (count == 1) {
                        // creating a stream object to store the genres
                        istringstream genre_stream(token);
                        string genre;

                        while(getline(genre_stream, genre, '|')) {
                            current_movie.genres_.insert(genre);
                        }
                    } // DIRECTOR
                    else if (count == 4) {
                        current_movie.director_name_ = token;
                    } // ACTOR 1
                    else if (count == 8) {
                        current_movie.actor_1_name_ = token;
                    } // ACTOR 2
                    else if (count == 10) {
                        current_movie.actor_2_name_ = token;
                    } // ACTOR 3
                    else if (count == 12) {
                        current_movie.actor_3_name_ = token;
                    } // PLOT KEYWORDS
                    else if (count == 18) {
                        // creating a stream object to store the plot keywords
                        istringstream keyword_stream(token);
                        string keyword;

                        while(getline(keyword_stream, keyword, '|')) {
                            current_movie.plot_keywords_.insert(keyword);
                        }
                    } // IMDB MOVIE LINK
                    else if (count == 19) {
                        current_movie.movie_imdb_link_ = token;
                    } // LANGUAGE
                    else if (count == 21) {
                        current_movie.language_ = token;
                    } // COUNTRY
                    else if (count == 22) {
                        current_movie.country_ = token;
                    } // CONTENET RATING
                    else if (count == 23) {
                        current_movie.content_rating_ = token;
                    } // COLOR
                    else if (count == 27) {
                        current_movie.color_ = token;
                    }
                }
                count++;
            }

            // inserting this movie node into the movie BST
            movie_bst_.insert(current_movie);
        }
        return movie_bst_;
    }

    // function to print the movies in sorted order, ascending if orderType is true and descending if it is false
    // Parameter: the root node, and a boolean value indicating which order is required
    // Returns nothing, prints the movies in the selected order
    void sortedMovies(TreeNode<Movie>* node, bool orderType) {
        if (orderType == true) {
            movie_bst_.inOrderTraversal();
        } else {
            movie_bst_.reverseInOrder();
        }
    }

    // wrapper function for printing movies in selected order
    void sortedMovies(bool orderType) {
        sortedMovies(movie_bst_.root, orderType);
    }

    // function that prints all the movies of the selected year
    // Parameter: the root node, and the year
    // Returns nothing, prints the movies of the selected year
    void yearMovies(TreeNode<Movie>* node, int year) {
        // cout<<node->data<<endl;
        if (node->data.title_year_ < year) {
            yearMovies(node->right, year);
        } else if (node->data.title_year_ > year) {
            yearMovies(node->left, year);
        } else if (node->data.title_year_ == year) {
            leftTreeTraversal(node, year);
        }
        return;
    }

    // function to find all the movies of the selected year by seraching the left trees each time the selected year is found
    // Parameter: the first movie node with selected year
    // Returns nothing, prints the movies of the given year
    void leftTreeTraversal(TreeNode<Movie>* node, int year) {
        if (node != NULL ) {
            if (node->data.title_year_ != year) {
                leftTreeTraversal(node->right, year);
            }
            if (node->data.title_year_ == year) {
                cout<< node->data<<endl;
                leftTreeTraversal(node->left, year);
            }
        }
    }

    // wrapper function for printing movies of the selected year
    void yearMovies(int year) {
        yearMovies(movie_bst_.root, year);
    }

    // function to search for a movie
    // Parameters: the root node and the name of the movie
    // returns nothing, if found prints the movie and its details
    void search(TreeNode<Movie>* node, string &movie_name) {
        if (node != NULL) {
            string movie_title_lowercase = node->data.movie_title_;
            std::transform(movie_title_lowercase.begin(), movie_title_lowercase.end(), movie_title_lowercase.begin(), ::tolower);
            if (movie_title_lowercase.find(movie_name) != std::string::npos) {
                cout<< "Movie: "<<node->data.movie_title_<<endl;
                cout<< "Director: "<<node->data.director_name_<<endl;
                cout<< "Imdb Score: "<<node->data.imdb_score_<<endl;
                cout<< "Actor 1: "<< node->data.actor_1_name_<<endl;
                cout<< "Actor 2: "<<node->data.actor_2_name_<<endl;
                cout<< "Actor 3: "<<node->data.actor_3_name_<<endl;
                cout<<"IMDB link: "<<node->data.movie_imdb_link_<<endl;
                return;
                } 
            search(node->left, movie_name);
            search(node->right, movie_name);
        }
    }

    // wrapper function for searching a movie
    void search(string &movie_name) {
        std::transform(movie_name.begin(), movie_name.end(), movie_name.begin(), ::tolower);
        search(movie_bst_.root, movie_name);
    }
    // FUNCTION TO CREATE ACTOR'S HASH MAP
    ActorHashMap create_actor_hash_map(BST<Movie> &mt){
        ActorHashMap actor_hash_map; // create instance of actor hashmap
        // AUTHOR: AYESHA SHAMIM NAIME
        // TRAVERSING THROUGH THE FILE AND MAKING A HASH MAP OF ACTORS
        string line, token; // line WILL STORE A ROW FROM THE FILE, token WILL STORE A TOKEN
        ifstream in("IMDB_Top5000-SEECS.csv");
        getline(in, line);
        for (int i = 0; i < 20; i++) {
            getline(in, line);
            istringstream stream(line); // FOR TOKENIZING
            for(int j = 0;  j< 13; j++){ // ONLY NEED COLUMN 8, 10, 12 I.E. ACTOR_1_NAME_, ACTOR_2_NAME_, ACTOR_3_NAME
                getline(stream, token, ',');
                if(j==0){
                    cout << "title: " <<  token << "    ";
                }else if(j!=8 && j!=10 && j!=12){
                    continue;
                }else if(j==8 || j==10 || j==12 && token!=""){ // SHOULD BE COLUMN ACTOR_1_NAME_, ACTOR_2_NAME_, ACTOR_3_NAME AND TOKEN SHOULD NOT BE EMPTY
                    cout << "actor"<< j << ": " << token << "  ";
                    // add to hash
                    actor_hash_map.insert(token, mt);
                }
            }
            cout << endl;
        }
        return actor_hash_map;
    }
    //function to create a director hash map
    // file reading is done to get all the possible names of the directors 
    DirectorHashMap createDirectorHashMap(BST<Movie> &mt){
        // create instance of actor hashmap
        DirectorHashMap director_hash_map; 
        // Traversing through the file and inserting director names into the hash map
        string line, token; // line WILL STORE A ROW FROM THE FILE, token WILL STORE A TOKEN
        ifstream in("IMDB_Top5000-SEECS.csv");
        getline(in, line);
        for (int i = 0; i < 100; i++) {
            getline(in, line);

            // creating a stream of the line to tokenize it
            istringstream stream(line);

            // only column 4 is required i.e. director name
            for(int j = 0;  j< 4; j++){ 
                getline(stream, token, ',');
                if(j==0){
                    cout << "title: " <<  token << "    ";
                }else if(!(j == 4)){
                    continue;
                }else if(j == 4 && token != ""){ 
                    cout << "director"<< j << ": " << token << "  ";
                    // add to hash
                    director_hash_map.insert(token, mt);
                }
            }
            cout << endl;
        }
        return director_hash_map;
    }
};
int main(){
    // ONLY FIRST HUNDRED MOVIES READ-> CHANGE THE FOR LOOP ITERATION IN createMovieBST(), create_actor_hash_map(movie_tree, create_director_hash_map(movie_tree
    MovieCollection mc;
    cout << "CREATING MOVIE BST\n";
    BST<Movie> movie_tree = mc.createMovieBST(); // pointer directing the BST of all movies
    cout << endl;

    cout << "MOVIE TRAVERSAL\n";
    movie_tree.inOrderTraversal();
    cout << endl << endl;
    
    ActorHashMap actor_hash_map = mc.create_actor_hash_map(movie_tree);

    // MAIN MENU NOT WORKING: EXAMPLES HARDCODED
    cout<< "GET JOHNNY DEPP'S PROFILE\n";
    actor_hash_map.getActorProfile("Johnny Depp");
    cout << endl;
    cout<< "GET JOHNNY DEPP'S COACTORS\n";
    actor_hash_map.getCoactors("Johnny Depp");
    cout << endl;
    cout<< "HAVE JOHNNY DEPP AND ORLANDO BLOOM WORKED IN MOVIE TOGETHER\n";
    actor_hash_map.actedTogether("Johnny Depp", "Orlando Bloom");
    cout << endl;
    cout<< "HAVE JOHNNY DEPP AND SCARLETT JOHANSSON WORKED IN MOVIE TOGTEHER\n";
    actor_hash_map.actedTogether("Johnny Depp", "Scarlett Johansson");
    cout << endl;

    // testin the movie tree
    cout<< "ASCENDING ORDER: "<<endl;
    mc.sortedMovies(true);
    cout << endl;


    cout<< "MOVIES RELEASED IN THE YEAR 2015: "<<endl;
    mc.yearMovies(2015);
    cout << endl;


    cout<< "SEARCHING FOR HARRY POTTER: "<<endl;
    string movie_name = "harry potter";
    mc.search(movie_name);


}
#endif