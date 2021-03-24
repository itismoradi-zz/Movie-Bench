#ifndef MOVIE_IG
#define MOVIE_IG

#include <string>

class Movie
{
    public:
        void operator=(Movie &);
        unsigned int operator~() const;     //get score of movie
        void showInformation() const;

        void setName(std::string);
        void setGrade(unsigned int);
        void setYear(unsigned int);
        void setDirector(std::string);
        void setTime(unsigned int);
        void setCountry(std::string);
        void setID();
        void setID(unsigned int);
        static void increasefullIndex();
        static void decreasefullIndex();

        std::string getName() const;
        char getFirstCharOfName() const;
        unsigned int getGrade() const;
        unsigned int getYear() const;
        std::string getDirector() const;
        unsigned int getTime() const;
        std::string getCountry() const;
        unsigned int getID() const;
        static size_t getfullIndex();
        static size_t getNumberOfMovies();

    private:
        std::string name;
        unsigned int grade; //0 to 100
        unsigned int year;  //for example: 2014
        std::string director;
        unsigned int time;  //in minute, for example: 80
        std::string country;
        unsigned int ID;    //a random value
        static size_t fullIndex; //last index of all movies have saved in program
};

#endif