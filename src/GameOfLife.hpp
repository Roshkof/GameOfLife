#pragma once
#include<string>
#include<vector>
#include"CommandSource.hpp"
using namespace std;

//KOMORKA----------------------------------------------------------

struct Field
{
    bool isAlive;
    bool shouldChange;

};

//PLANSZE DO GRY---------------------------------------------------
class Board
{
    virtual void displayBoard()=0;
    virtual void setAliveDead(int row, int col)=0;
    virtual void checkChanges()=0;
    virtual void setChanges()=0;
    virtual int countAlive(int row, int col)=0;
    virtual void play(CommandSource& command_source)=0;
    virtual Field& place(int row,int col)=0;

};



class SquareBoard:public Board
{
 int width;
 int height;
 vector<Field> board;

 public:

    SquareBoard(int width, int height);

    int countAlive(int row, int col) override;
    bool outOfTheBoard(int row, int col);


    void displayBoard() override;
    void setAliveDead(int row, int col) override;
    void checkChanges() override;
    void setChanges() override;

    void play(CommandSource& command_source);
 private:
    Field& place(int row,int col);
};



class WalecBoard:public Board
{
 int width;
 int height;
 vector<Field> board;

 public:
    WalecBoard(int width, int height);

    int countAlive(int row, int col) override;
    void displayBoard() override;
    void setAliveDead(int row, int col) override;
    void checkChanges() override;
    void setChanges() override;

    void play(CommandSource& command_source);
 private:
    Field& place(int row,int col);

};



class TorusBoard:public Board
{
 int width;
 int height;
 vector<Field> board;

 public:
    TorusBoard(int width, int height);

    int countAlive(int row, int col) override;
    void displayBoard() override;
    void setAliveDead(int row, int col) override;
    void checkChanges() override;
    void setChanges() override;

    void play(CommandSource& command_source);
 private:
    Field& place(int row,int col);
};
