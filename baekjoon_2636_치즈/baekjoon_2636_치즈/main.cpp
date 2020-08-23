//
//  main.cpp
//  baekjoon_2636_치즈
//
//  Created by 김대교 on 2020/08/23.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int setY[4] = {-1,0,1,0};
int setX[4] = {0,-1,0,1};

int visit[100][100] = {false};
int board[100][100];
int n,m;

int preCheese=0;
int result=0;

bool inRange(int y, int x){
    return (y>=0&&x>=0)&&(y<n&&x<m);
}

bool meltAll(){
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                temp++;
            }
        }
    }
    
    if(temp==0){
        return true;
    }else{
        preCheese = temp;
        return false;
    }
}

void changeToAir(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==2){
                board[i][j]=3;
            }
        }
    }
}

void bfs(int y,int x){
    memset(visit, 0, sizeof(visit));

    queue<pair<int, int>> q;
    q.push({y,x});
    
    while (!q.empty()) {
        int currentY= q.front().first;
        int currentX = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nextY = currentY+setY[i];
            int nextX = currentX+setX[i];
            if(inRange(nextY, nextX)&&!visit[nextY][nextX]&&(board[nextY][nextX]==0||board[nextY][nextX]==3)){
                q.push({nextY,nextX});
                visit[nextY][nextX] = true;
                board[nextY][nextX] = 3;
            }
        }
    }
}

void bfs2(int y,int x){
    memset(visit, 0, sizeof(visit));

    queue<pair<int, int>> q;
    q.push({y,x});
    
    while (!q.empty()) {
        int currentY= q.front().first;
        int currentX = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nextY = currentY+setY[i];
            int nextX = currentX+setX[i];
            if(inRange(nextY, nextX)&&!visit[nextY][nextX]){
                if(board[currentY][currentX]==3){
                    q.push({nextY,nextX});
                    visit[nextY][nextX]=true;
                }
                
                if(board[currentY][currentX]==3&&board[nextY][nextX]==1){
                    q.push({nextY,nextX});
                    visit[nextY][nextX]=true;
                    board[nextY][nextX]=2;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    
    while(1){
        if(meltAll())
            break;

        bfs(0, 0);
        bfs2(0, 0);
        changeToAir();
        
        result++;
    }
    
    cout<<result<<endl;
    cout<<preCheese<<endl;
    
    return 0;
}
