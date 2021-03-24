#include "command.hpp"
#include "app.hpp"
#include <algorithm>
#include <iomanip>
using namespace std;

void Command::getCommand(Movie * movies)
{
    this->movies = movies;

    do
    {
        cout << "> ";
        getline(cin, inputedText);
        command = commandSeparator();   //returns separated command from inputedText Command private data member
        transform(command.begin(), command.end(), command.begin(), ::tolower);  //convert all characters to lowercase

        try
        {
            if(command == "exit" || cin.eof())
            {
                App::status = false;
                break;
            }
            else if(command == "add")
            {
                add();
            }
            else if(command == "remove")
            {
                remove();
            }
            else if(command == "sort-by")
            {
                sortBy();
            }
            else if(command == "show")
            {
                show();
            }
            else if(command == "show-all")
            {
                showAll();
            }
            else if(command == "average-score")
            {
                averageScore();
            }
            else if(command == "help")
            {
                help();
            }
            else if(command == "about")
            {
                about();
            }
            else if(command == "clear")
            {
                clear();
            }
            else if(command.empty())
            {
                continue;
            }
            else
            {
                cerr << "!!! undefined command" << endl;
            }
        }
        catch(const char * t)
        {
            cout << t << endl;
        }
        
    } 
    while(App::status = true);
}

void Command::add()
{
    string args[6];     //saves 6 arguments that input after add command
    // add <movie_name> <grade> <year> <time> <director_name> <country>
    
    for(size_t i=0; i<6; i++)
    {
        args[i] = commandSeparator();

        if(args[i].empty())
        {
            throw "!!! The <add> command arguments were not entered correctly\n"
            "template: add <movie_name> <grade> <year> <time> <director_name> <country>";
        }
    }

    string name        = args[0];
    string director    = args[4];
    string country     = args[5];
    int grade, year, time;

    try 
    {
        //convert integer data that are in string characters
        grade = stoi(args[1]);
        year  = stoi(args[2]);
        time  = stoi(args[3]);

        if(grade < 0 || year < 0 || time < 0)
        {
            throw "!!! invalid inputed value\n"
            "template: add <movie_name> <grade> <year> <time> <director_name> <country>";
        }

        Movie::increasefullIndex();
        unsigned int index = Movie::getfullIndex();    //Movie static function 

        movies[index].setName(name);     
        movies[index].setGrade(grade); 
        movies[index].setYear(year);
        movies[index].setTime(time);
        movies[index].setDirector(director);
        movies[index].setCountry(country);
        movies[index].setID();

        cout << "!!! movie ( " << movies[index].getName() << " ) added successfully.   ID: " << 
        movies[index].getID()<< endl;
    }
    catch(const invalid_argument& e)
    {
        std::cerr << e.what() << endl;
    }
    catch(const char * text)
    {
        cerr << text << endl;
    }
}

void Command::remove()
{
    size_t numberOfMovies = Movie::getNumberOfMovies();

    if(inputedText.empty())
    {
        throw "!!! The <remove> command arguments were not entered correctly\n"
        "template: remove <movie_name>";
    }

    for(size_t i=0; i<numberOfMovies; i++)
    {
       if(movies[i].getName() == inputedText)
       {
           //remove element in dynamic array(movies)
           //shift back 1 unit elements that are after i (movies[i]) 
           *this << static_cast<int>(i);    //command class << index of movie array
           cout << "!!! movie " << inputedText << " deleteed successfully" << endl;
           return;
       }
    }

    throw "!!! not found";
}

void Command::sortBy()
{
    size_t numberOfMovies = Movie::getNumberOfMovies();

    if(inputedText == "name")
    {
        //buble sort
        for(size_t i=0; i<numberOfMovies; i++)
        {
            for(size_t j=i+1; j<numberOfMovies; j++)
            {
                //ascii codes are compared
                if(movies[j].getFirstCharOfName() < movies[i].getFirstCharOfName())
                {
                    swapMovies(movies[j], movies[i]);
                }
            }
        }
        
        cout << "!!! movies are sorted by names" << endl;
    }
    else if(inputedText == "score")
    {
        //buble sort
        for(size_t i=0; i<numberOfMovies; i++)
        {
            for(size_t j=i+1; j<numberOfMovies; j++)
            {
                if(~movies[j] < ~movies[i])     //~ operator returns the score value
                {
                    swapMovies(movies[j], movies[i]);
                }
            }
        }
        
        cout << "!!! movies are sorted by scores" << endl;
    }
    else
    {
        throw "!!! The <sort-by> command arguments were not entered correctly\n"
        "template: sort-by \"name\"   or   sort-by \"score\"";
    }
}

void Command::show() const
{
    size_t numberOfMovies = Movie::getNumberOfMovies();

    if(inputedText.empty())
    {
        throw "!!! The <show> command arguments were not entered correctly\n"
        "template: show <movie_name>";
    }

    for(size_t i=0; i<numberOfMovies; i++)
    {
       if(movies[i].getName() == inputedText)
       {

           cout << "!!! movie " << inputedText << " information" << endl;
           movies[i].showInformation();
           return;
       }
    }

    throw "!!! not found";
}

void Command::showAll() const
{
    size_t numberOfMovies = Movie::getNumberOfMovies();

    if(numberOfMovies == 0)
    {
        throw "!!! There are no movies available";
    }

    cout << "!!! movies information" << endl;

    for(size_t i=0; i<numberOfMovies; i++)
    {
        cout << "----------------------------------------" << endl;
        movies[i].showInformation();
    }
}

void Command::averageScore() const
{
    size_t numberOfMovies = Movie::getNumberOfMovies();
    unsigned int sum = 0;
    unsigned int avg = 0;

    if(numberOfMovies == 0)
    {
        throw "!!! There are no movies available";
    }
    
    for(size_t i=0; i<numberOfMovies; i++)
    {
        sum += ~movies[i];
    }
    
    avg = static_cast<unsigned int>(sum) / numberOfMovies;

    cout << "!!! average of scores : " << setprecision(8) << avg << endl;
}

void Command::help() const
{
    cout << "!!! program commands (case insensitive)" << endl;
    cout << "\t" << setw(20) << left << "add"           << left << "Adds a movie to the movie collection" << endl;
    cout << "\t" << setw(20) << left << "remove"        << left << "Deletes a movie into the movie collection" << endl;
    cout << "\t" << setw(20) << left << "sort-by"       << left << "Sorts movies by name or score" << endl;
    cout << "\t" << setw(20) << left << "show"          << left << "Displays the information by naming the movie" << endl;
    cout << "\t" << setw(20) << left << "show-all"      << left << "Displays information of all videos" << endl;
    cout << "\t" << setw(20) << left << "average-score" << left << "The average score of the critics of all the films is displayed" << endl;
    cout << "\t" << setw(20) << left << "clear"         << left << "Clears the page for you" << endl;
    cout << "\t" << setw(20) << left << "about"         << left << "About the program developer" << endl;
    cout << "\t" << setw(20) << left << "exit"          << left << "Ends the program" << endl;
}

void Command::about() const
{
    cout << "!!! Mohammad Moradi" << endl;
    cout << "Made with love from" << endl;
    cout << "_ __   _  _  _\n"
            "| |_) /_\\ |\\ |\n"
            "| | \\ | | | \\|\n" << endl;
}

void Command::clear() const
{
    //calling App class static functions
    App::clear();
    App::splashScreen();
}

string Command::commandSeparator()
{
    string temp;    //return value

    //clear extra spaces in beginning of string
    while(inputedText.find(" ") == 0)
    {
        inputedText.erase(0, 1);
    }

    size_t separatorPosition = inputedText.find(" ");  //white spaces are separator

    //copies the command until it reaches the space in the inputedText
    temp = inputedText.substr(0, separatorPosition);
    //remove command from inputedText
    inputedText.erase(0, temp.size() + 1);

    return temp; 
}

void Command::swapMovies(Movie & movie1, Movie & movie2)
{
    Movie temp;

    temp = movie1;
    movie1 = movie2;
    movie2 = temp;
}

void Command::operator<<(int index)
{
   size_t lastIndex = Movie::getfullIndex();

    for(size_t i = 0; i < lastIndex; i++)
    {
        movies[index] = movies[index + 1];  //Movie class operator = is overloaded
    }
}