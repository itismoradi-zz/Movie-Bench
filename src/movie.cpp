#include "movie.hpp"
#include <iostream>
#include <iomanip>
#include <exception>
#include <random>
#include <time.h>
using namespace std;

size_t Movie::fullIndex = -1;           //There is no movie 
                                        //(Because index 0 itself means the index of a house)


void Movie::operator=(Movie & movie)
{
    try
    {
        this->setName(movie.getName());
        this->setGrade(movie.getGrade());
        this->setYear(movie.getYear());
        this->setDirector(movie.getDirector());
        this->setTime(movie.getTime());
        this->setCountry(movie.getCountry());
        this->setID(movie.getID());
    }
    catch(const char * text)
    {
        cerr << text << endl;
    }
}

unsigned int Movie::operator~() const
{
    return grade;
}

void Movie::showInformation() const
{
    cout << "\t" << setw(15) << left << "name : "     << left << this->getName()     << endl;
    cout << "\t" << setw(15) << left << "ID : "       << left << this->getID()       << endl;
    cout << "\t" << setw(15) << left << "grade : "    << left << this->getGrade()    << endl;
    cout << "\t" << setw(15) << left << "year : "     << left << this->getYear()     << endl;
    cout << "\t" << setw(15) << left << "director : " << left << this->getDirector() << endl;
    cout << "\t" << setw(15) << left << "time : "     << left << this->getTime()     << endl;
    cout << "\t" << setw(15) << left << "country : "  << left << this->getCountry()  << endl;
}

void Movie::setName(string name)
{
    this->name = name;
}

void Movie::setGrade(unsigned int grade)
{
    if(grade < 0 || grade > 100)
    {
        throw "!!! invalid inputed value";
    }
    else
    {
        this->grade = grade;
    }
}

void Movie::setYear(unsigned int year)
{
    if(year < 0)
    {
        throw "!!! invalid inputed value";
    }
    else
    {
        this->year = year;
    }
}

void Movie::setDirector(string director)
{
    this->director = director;
}

void Movie::setTime(unsigned int time)
{
    if(time < 0)
    {
        throw "!!! invalid inputed value";
    }
    else
    {
        this->time = time;
    }
}

void Movie::setCountry(string country)
{
    this->country = country;
}

void Movie::setID()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 10.0);
    ID = dist(mt);
}

void Movie::setID(unsigned int ID)
{
    if(ID < 0)
    {
        throw "!!! invalid inputed value";
    }
    else
    {
        this->ID = ID;
    }
}

void Movie::increasefullIndex()
{
    fullIndex++;
}

void Movie::decreasefullIndex()
{
    fullIndex--;
}

string Movie::getName() const
{
    return name;
}

char Movie::getFirstCharOfName() const
{
    char ch = name.at(0); 
    return ch;
}

unsigned int Movie::getGrade() const
{
    return grade;
}

unsigned int Movie::getYear() const
{
    return year;
}

string Movie::getDirector() const
{
    return director;
}

unsigned int Movie::getTime() const
{
    return time;
}

string Movie::getCountry() const
{
    return country;
}

unsigned int Movie::getID() const
{
    return ID;
}

size_t Movie::getfullIndex()
{
    return fullIndex;
}

size_t Movie::getNumberOfMovies()
{
    return (fullIndex + 1);
}