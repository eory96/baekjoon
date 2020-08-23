//
//  main.cpp
//  practice
//
//  Created by 김대교 on 2020/03/29.
//  Copyright © 2020 김대교. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
        vector<vector<int>> board;
    vector<int> moves;
    board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    moves = {1,5,3,5,1,2,1,4};
    int answer = 0;
    vector<int> tempBox;
    for(int i=0;i<moves.size();i++){
        int zeroCnt=0;
        for(int j=0;j<board.size();j++) {
            int value=board.at(j).at(moves[i]-1);
            
            if(value==0){
                zeroCnt++;
            }else{
                break;
            }
        }
        //cout<<board[zeroCnt][moves[i]-1]<<endl;
        tempBox.push_back(board[zeroCnt][moves[i]-1]);
        try{
            board[zeroCnt][moves[i]-1]=0;
        }catch(...){
            cout<<"what the...";
        }
        
        if(tempBox.size()>=2&&tempBox[tempBox.size()-1]==tempBox[tempBox.size()-2]){
            tempBox.pop_back();
            tempBox.pop_back();
            answer+=2;
        }
    }
    return answer;
}
