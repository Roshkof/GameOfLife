#include<iostream>
#include<string>
#include"GameOfLife.hpp"
#include"AlwaysNextTurn.cpp"
#include"CommandSource.hpp"
using namespace std;

SquareBoard::SquareBoard(int width, int height)
{
 this->width=width;
 this->height=height;
 board.resize(width*height);
 for(int i=0;i<(width*height);i++)
 {
  board[i].isAlive=false;
  board[i].shouldChange=false;
 }
}

void SquareBoard::displayBoard()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false){cout<<"[.]";}
            if(place(row,col).isAlive==true){cout<<"[o]";}
        }
        cout<<endl;
    }
}


Field& SquareBoard::place(int row,int col)
{
    return board[(row*width+col)];
}
bool SquareBoard::outOfTheBoard(int row, int col)
{
    return ((row < 0 || row >= height) || (col < 0 || col >= width));
}

void SquareBoard::setAliveDead(int row, int col)
{

    if(place(row,col).isAlive){place(row,col).isAlive=false;}
    else{place(row,col).isAlive=true;}
}

int SquareBoard::countAlive(int row, int col)
{
    int aliveCounter=0;
    for(int i=row-1;i<=row+1;i++)
    {
        for(int j=col-1;j<=col+1;j++)
        {
            if((i != row || j != col) && ((i >= 0 && i <= height - 1 ) && (j >= 0 && j <= width - 1)))
            {
                if(place(i,j).isAlive) {aliveCounter++;}
            }
        }
    }

    return aliveCounter;   
}

void SquareBoard::checkChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false && countAlive(row,col)==3){place(row,col).shouldChange=true;}
            if((place(row,col).isAlive) && (countAlive(row,col)<2 || countAlive(row,col)>3)){place(row,col).shouldChange=true;}
        }
    }

}

void SquareBoard::setChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
          if(place(row,col).shouldChange){setAliveDead(row,col);place(row,col).shouldChange=false;}  
        }
    }

}

//FUNKCJA ROZGRYWKI-------------------------------------------------------------------
void SquareBoard::play(CommandSource& command_source)
{
    while(true)
    {
        std::string command = command_source.next_command();
        if(command == "quit") {return;}

        system("clear");
        setChanges();
        displayBoard();
        checkChanges();
    } 
}

//FUNKCJE DLA WALCA---------------------------------------------------------------------

WalecBoard::WalecBoard(int width, int height)
{
 this->width=width;
 this->height=height;
 board.resize(width*height);
 for(int i=0;i<(width*height);i++)
 {
  board[i].isAlive=false;
  board[i].shouldChange=false;
 }

}

void WalecBoard::displayBoard()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false){cout<<"[.]";}
            if(place(row,col).isAlive==true){cout<<"[o]";}
        }
        cout<<endl;
    }
}

Field& WalecBoard::place(int row,int col)
{
    return board[(row*width+col)];
}

void WalecBoard::setAliveDead(int row, int col)
{

    if(place(row,col).isAlive){place(row,col).isAlive=false;}
    else{place(row,col).isAlive=true;}
}

void WalecBoard::checkChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false && countAlive(row,col)==3){place(row,col).shouldChange=true;}
            if((place(row,col).isAlive) && (countAlive(row,col)<2 || countAlive(row,col)>3)){place(row,col).shouldChange=true;}
        }
    }

}

void WalecBoard::setChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
          if(place(row,col).shouldChange){setAliveDead(row,col);place(row,col).shouldChange=false;}  
        }
    }

}

int WalecBoard::countAlive(int row, int col)
{
    int aliveCounter=0;
    for(int i=row-1;i<=row+1;i++)
    {
        for(int j=col-1;j<=col+1;j++)
        {
            if((i != row || j != col) && ((i >= 0 && i <= height - 1 ) && (j >= 0 && j <= width - 1)))
            {
                if(place(i,j).isAlive) {aliveCounter++;}
            }
        }
    }
    if(col-1<0)
    {
        for(int g=row-1;g<=row+1;g++)
        {
            if(place(g,width-1).isAlive){aliveCounter++;}
        }
    }
    if(col+1>width-1)
    {
        for(int k=row-1;k<=row+1;k++)
        {
            if(place(k,0).isAlive){aliveCounter++;}
        } 
    }
    return aliveCounter;   
}

void WalecBoard::play(CommandSource& command_source)
{
    while(true)
    {
        std::string command = command_source.next_command();
        if(command == "quit") {return;}

        system("clear");
        setChanges();
        displayBoard();
        checkChanges();
    } 
}


//FUNKCJE DLA TORUSA---------------------------------------------------------------------

TorusBoard::TorusBoard(int width, int height)
{
 this->width=width;
 this->height=height;
 board.resize(width*height);
 for(int i=0;i<(width*height);i++)
 {
  board[i].isAlive=false;
  board[i].shouldChange=false;
 }    
}

void TorusBoard::displayBoard()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false){cout<<"[.]";}
            if(place(row,col).isAlive==true){cout<<"[o]";}
        }
        cout<<endl;
    }
}

Field& TorusBoard::place(int row,int col)
{
    return board[(row*width+col)];
}

void TorusBoard::setAliveDead(int row, int col)
{

    if(place(row,col).isAlive){place(row,col).isAlive=false;}
    else{place(row,col).isAlive=true;}
}

void TorusBoard::checkChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isAlive==false && countAlive(row,col)==3){place(row,col).shouldChange=true;}
            if((place(row,col).isAlive) && (countAlive(row,col)<2 || countAlive(row,col)>3)){place(row,col).shouldChange=true;}
        }
    }

}

void TorusBoard::setChanges()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
          if(place(row,col).shouldChange){setAliveDead(row,col);place(row,col).shouldChange=false;}  
        }
    }

}

int TorusBoard::countAlive(int row, int col)
{
    int aliveCounter=0;
    for(int i=row-1;i<=row+1;i++)
    {
        for(int j=col-1;j<=col+1;j++)
        {
            if((i != row || j != col) && ((i >= 0 && i <= height - 1 ) && (j >= 0 && j <= width - 1)))
            {
                if(place(i,j).isAlive) {aliveCounter++;}
            }
        }
    }
    if(col-1<0)
    {
        for(int g=row-1;g<=row+1;g++)
        {
            if(place(g,width-1).isAlive){aliveCounter++;}
        }
    }
    if(col+1>width-1)
    {
        for(int k=row-1;k<=row+1;k++)
        {
            if(place(k,0).isAlive){aliveCounter++;}
        } 
    }
    if(row-1<0)
    {
        for(int l=col-1;l<=col+1;l++)
        {
            if(place(height-1,l).isAlive){aliveCounter++;}
        }
    }
    if(row+1>height-1)
    {
        for(int m=col-1;m<=col+1;m++)
        {
            if(place(0,m).isAlive){aliveCounter++;}
        }
    }
    return aliveCounter;
}

void TorusBoard::play(CommandSource& command_source)
{
    while(true)
    {
        std::string command = command_source.next_command();
        if(command == "quit") {return;}

        system("clear");
        setChanges();
        displayBoard();
        checkChanges();
    } 
}
