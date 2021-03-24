#ifndef APP_IG
#define APP_IG

#include "command.hpp"
#define MOVIES_NUMBERS 10000 

class App
{
    friend class Command;
    public:
        App();
        ~App();
        int exec();
        static void splashScreen();
    private:
        Command command;
        Movie * movies;
        static bool status;
        static void clear();
};

#endif