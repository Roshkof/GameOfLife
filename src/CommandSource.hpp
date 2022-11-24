#pragma once
#include<string>
#include<vector>
using namespace std;


//ZRODLO KOMEND-----------------------------------------------------
class CommandSource
{
    public:
    virtual string next_command() = 0;
    virtual ~CommandSource() { };
};

class AlwaysNextTurn:public CommandSource
{
    int turns=0;

 public:
    string next_command() override;
 
};

class UserCommands:public CommandSource
{
    int turns=0;
 public:
    string next_command() override;
};