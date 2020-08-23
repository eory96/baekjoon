//
//  main.cpp
//  baekjoon_2468_안전영역
//
//  Created by 김대교 on 2020/05/16.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int board[101][101]={0};
int visit[101][101] = {false};
vector<pair<int,int>> direction;
int maxV = 0;

void dfs1(int y, int x,int standard){
    visit[y][x] = true;
    for(int i=0;i<4;i++){
        int nextY = y+direction[i].first;
        int nextX = x+direction[i].second;
        
        if(nextY<0||nextY>=N||nextX<0||nextX>=N) continue;
        else{
            if(!visit[nextY][nextX]&&board[nextY][nextX]>standard){
                dfs1(nextY,nextX,standard);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    direction.push_back(make_pair(0, 1));
    direction.push_back(make_pair(0, -1));
    direction.push_back(make_pair(1, 0));
    direction.push_back(make_pair(-1, 0));
    
    int cnt=0;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if( maxV < board[i][j] ){
                maxV = board[i][j];
            }
        }
    }
    
    int answer=0;
    for(int k=0;k<maxV;k++){
        cnt=0;
        memset(visit, false, sizeof(visit));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j]&&board[i][j]>k){
                    cnt++;
                    dfs1(i,j,k);
                }
            }
        }
        answer = max(answer, cnt);
    }

    cout<<answer;
    return 0;
}
