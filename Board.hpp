#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Direction.hpp"


namespace ariel{

class Board{

    std::vector<std::vector<char>> board;

    public:
    Board(){
        board.resize(5,vector<char>(5,'_'));
    }
    void post(unsigned int row, unsigned int column,Direction d,const string &s);  
    string read(unsigned int row, unsigned int column,Direction d,unsigned int length);
    void show();
};

}
