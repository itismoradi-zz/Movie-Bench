#include "app.hpp"
#include "movie.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

bool App::status = true;

App::App()
{
    status = true;
    movies = new Movie[MOVIES_NUMBERS];
}

App::~App()
{
    delete [] movies;
    movies = nullptr;
}

int App::exec()
{
    splashScreen();
    command.getCommand(movies);
    cout << "!!! program finished\n" << endl;
    return 0;
}

void App::clear()
{
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}

void App::splashScreen()
{
    clear();
    cout << "  .___  ___.   ______   ____    ____  __   _______       \n"   << 
            "  |   \\/   |  /  __  \\  \\   \\  /   / |  | |   ____|  \n"   << 
            "  |  \\  /  | |  |  |  |  \\   \\/   /  |  | |  |__      \n"   << 
            "  |  |\\/|  | |  |  |  |   \\      /   |  | |   __|      \n"   << 
            "  |  |  |  | |  `--'  |    \\    /    |  | |  |____      \n"   << 
            "  |__|  |__|  \\______/      \\__/     |__| |_______|    \n"   <<                                     
            "  .______    _______   .__   __.   ______  __    __      \n"   << 
            "  |   _  \\  |   ____| |  \\ |  |  /      ||  |  |  |    \n"   << 
            "  |  |_)  | |  |__    |   \\|  | |  ,----'|  |__|  |     \n"   << 
            "  |   _  <  |   __|   |  . `  | |  |     |   __   |      \n"   << 
            "  |  |_)  | |  |____  |  |\\   | |  `----.|  |  |  |     \n"   << 
            "  |______/  |_______| |__| \\__|  \\______||__|  |__|    \n"   << endl;
    cout << "  -------------------------------------------------\n"         << endl;
    cout << "!!! Enter < help > to get instructions on the program commands!\n" << endl;

}