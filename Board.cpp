#include <iostream>
#include <cstdlib>
#include <vector>
#include "Board.hpp"
using namespace std;


const char space = '_';



void ariel::Board::post(unsigned int row, unsigned int column,Direction d,const string &s){

    unsigned int length_col = board.at(0).size();
    unsigned int board_len = board.size();
    unsigned int post_len = s.size();
    if(d == Direction::Horizontal){

         if (board_len <= row) {
            for (size_t i = 0; i < row+1; i++)
            {
                board.push_back(vector<char>(board.at(0).size(), space));
            }
            
        }
        unsigned int range = column+post_len;
        if(length_col < range){
            for(size_t i=0; i<board.size(); i++){
                board[i].resize(range,space);
            }
        }

    }

    else{
        unsigned int range = row+post_len;
        if (board_len < range) {
            for (size_t i = 0; i < range; i++){
            board.push_back(vector<char>(board.at(0).size(), space));
            }
        }
        if(length_col <= column){
            for(size_t i=0; i<board.size(); i++){
                board[i].resize(column+1,space);
            }
        }

    }

    for (size_t i = 0; i < post_len; i++)
    {
        if(d == Direction::Horizontal){
            board.at(row).at(column+i) = s.at(i);
        }
        else{
            board.at(row+i).at(column)= s.at(i);
        }
    }

}

string ariel::Board::read(unsigned int row, unsigned int column,Direction d,unsigned int length){

    string ans = "";
    unsigned int length_col = board.at(0).size();
    unsigned int board_len = board.size();
    if(d == Direction::Horizontal){

        if (board_len <= row) {
            for (size_t i = 0; i < row+1; i++)
            {
                board.push_back(vector<char>(board.at(0).size(), space));
            }
            
        }
        unsigned int range = column+length+1;
        if(length_col < range){
            for(size_t i=0; i<board.size(); i++){
                board[i].resize(range,space);
            }
        }
    }

    else{
        unsigned int range = row+length;
        if (board_len < range) {
            for (size_t i = 0; i < range; i++){
            board.push_back(vector<char>(board.at(0).size(), space));
            }
        }
        if(length_col <= column){
            for(size_t i=0; i<board.size(); i++){
                board.at(i).resize(column+1,space);
            }
        }

    }
    for (size_t i = 0; i < length; i++)
    {
        if(d == Direction::Horizontal){
            ans += board.at(row).at(column+i);
        }
        else{
            ans += board.at(row+i).at(column);
        }
    }
    
    return ans;
}

void ariel::Board::show(){

    for(size_t i=0 ; i< board.size(); i++){
        for(size_t j=0; j< board.at(i).size(); j++){
            cout<<board.at(i).at(j);
        }
            cout<<" "<<endl;
    }
}

