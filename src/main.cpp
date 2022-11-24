#include <iostream>
#include<string>
#include<fstream>
#include"GameOfLife.hpp"
#include"CommandSource.hpp"

using namespace std;

int main()
{
    AlwaysNextTurn auto_command_source;
    UserCommands user_command_source;

    fstream plik;
    string board_type,wPreset,hPreset,linePreset;
    char preset;
    int rowCounter=0,colCounter=0;

    plik.open("Juan.txt", ios::in);

    if(not plik.is_open()){return 1;}

    getline(plik,board_type);
    getline(plik,wPreset);
    getline(plik,hPreset);
    int w=stoi(wPreset);
    int h=stoi(hPreset);

    SquareBoard b1(w,h);
    WalecBoard b2(w,h);
    TorusBoard b3(w,h);

    while(!plik.eof())
    {
        getline(plik,linePreset);
        for(unsigned int i=0;i<linePreset.size();i++)
        {
            preset=linePreset[i];;
            if(preset== '+')
            {
                b1.setAliveDead(rowCounter,colCounter);
                b2.setAliveDead(rowCounter,colCounter);
                b3.setAliveDead(rowCounter,colCounter);
            }
            colCounter++; 
        }
        colCounter=0;
        rowCounter++;

    }
    plik.close();

    std::string chosen_mode;
    std::cout<<"Wybierz zrodlo komend [user,auto]:";
    std::cin>>chosen_mode;

    if(board_type == "kwadrat")
    {
        if(chosen_mode == "user"){b1.play(user_command_source);}
        else if(chosen_mode == "auto"){b1.play(auto_command_source);}
    }
    if(board_type == "walec")
    {
        if(chosen_mode == "user"){b2.play(user_command_source);}
        else if(chosen_mode == "auto"){b2.play(auto_command_source);}
    }
    if(board_type == "torus")
    {
        if(chosen_mode == "user"){b3.play(user_command_source);}
        else if(chosen_mode == "auto"){b3.play(auto_command_source);}
    }
    
    return 0;
}
