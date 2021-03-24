#ifndef COMMAND_IG
#define COMMAND_IG

#include "movie.hpp"
#include <iostream>
#include <string>

class Command
{
    public:
        void getCommand(Movie *);
        void add();
        void remove();
        void sortBy();
        void show() const;
        void showAll() const;
        void averageScore() const;
        void help() const;
        void clear() const;
        void about() const;
    private:
        std::string inputedText;
        std::string command;    //The first word separated from inputeText
        Movie * movies;
        std::string commandSeparator();
        void swapMovies(Movie &, Movie &);
        void operator<<(int);   //shift back 1 unit movies that are after a particular movie
};

#endif