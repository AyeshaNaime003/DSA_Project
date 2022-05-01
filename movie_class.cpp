#ifndef MOVIE_CLASS_H_
#define MOVIE_CLASS_H_
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include"linkedlist_template.cpp"
using namespace std;

class Movie {
    public:
    // DATA MEMBERS-> TRAILING UNDERSCORE DUE TO DATA MEMBERS
    string movie_title_;

    // ENUM for genre 
    // sci-fi
    enum GenreType {action, adventure, animation, comedy, fantasy, 
    western, drama, romance, mystery, documentary, thriller, 
    history, horror, war, biography, crime, sport, musical, family, sci_fi};

    LinkedList<string> genres_; // LINKED LIST FOR GENRE AS MULTIVALUED
    int title_year_;
    float imdb_score_;
    string director_name_;
    int director_facebook_likes_;
    int num_critic_for_reviews_;
    int duration_;
    string actor_1_name_;
    int actor_1_facebook_likes_;
    string actor_2_name_;
    int actor_2_facebook_likes_;
    string actor_3_name_;
    int actor_3_facebook_likes_;
    long gross_;
    long num_voted_users_;
    long cast_total_facebook_likes_;
    int facenumber_in_poster_;
    LinkedList<string> plot_keywords_; // LINKED LIST FOR GENRE AS MULTIVALUED
    string movie_imdb_link_;
    int num_user_for_reviews_;
    string language_;
    string country_;
    string content_rating_; 
    float budget_; // ATLEAST A MILLION->MULTIPLY THE VALUE WITH 
    float aspect_ratio_;
    long movie_facebook_likes_;
    string color_; // either color 'c' or black and white 'b'
    
    // DEFAULT CONSTRUCTOR
    Movie() {

    }
    
    // COPY CONSTRUCTOR 
    Movie(Movie &movie) {
        movie_title_ = movie.movie_title_;

    }

    bool operator <(const Movie& m) {
        if (title_year_ < m.title_year_) {
            return true;
        } else {
            return false;
        }
    }
    bool operator >(const Movie& m) {
        if (title_year_ > m.title_year_) {
            return true;
        } else {
            return false;
        }
    }
    friend ostream &operator<< (ostream &output, const Movie& m) {
        //ouput << "MOVIE TITLE: "<<m.title_year_<< "TITLE YEAR: "<<m.title_year_<< "\t"<< "IMDB SCORE: "<<m.imdb_score_<<endl;
        output << m.movie_title_ << ", " << m.title_year_ << ", " << m.imdb_score_ << ", " << m.director_name_ << ", " << m.actor_1_name_;
        return output;
    }
};

#endif