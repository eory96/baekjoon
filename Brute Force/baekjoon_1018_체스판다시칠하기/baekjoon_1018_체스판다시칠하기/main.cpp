//
//  main.cpp
//  baekjoon_1018_체스판다시칠하기
//
//  Created by 김대교 on 2020/03/02.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
char board[50][50];
int N,M;

int answer=9999;

char WB[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
};
char BW[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
};

int paint(int starty,int startx){
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[starty+i][startx+j]!=WB[i][j]){
                cnt1++;
            }
            if(board[starty+i][startx+j]!=BW[i][j]){
                cnt2++;
            }
        }
    }
    return min(cnt1,cnt2);
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int a=0;a<M;a++){
            cin>>board[i][a];
        }
    }
    
        
    for(int i=0;i+8<=N;i++){
        for(int j=0;j+8<=M;j++){
            answer = min(answer,paint(i,j));
        }
    }
    
    cout<<answer<<endl;

    
    return 0;
}
