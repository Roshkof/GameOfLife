#include "CommandSource.hpp"
#include<iostream>
#include<string>
#include<chrono>
#include<thread>


string AlwaysNextTurn::next_command()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);

    if(turns++>100){return "quit";}
    return "next";
}

string UserCommands::next_command()
{
    getchar();

    if(turns++>50){return "quit";}
    return "next";
}
