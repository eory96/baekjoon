//
//  main.cpp
//  baekjoon_7562_나이트의이동
//
//  Created by 김대교 on 2020/03/23.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?



 입력
 입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

 각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

 출력
 각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int chese[300][300];
int visit[300][300];

int moveY[8] ={-1,-2,-2,-1,1,2,2,1};
int moveX[8] = {-2,-1,1,2,2,1,-1,-2};

int cnt;
vector<int> result;

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y), x(x){}
};

Node start_point(0,0);
Node end_point(0,0);

void initialize(){
    for (int i = 0; i < 300; i++)
        for (int j = 0; j < 300; j++)
            chese[i][j] = 9989;

}

int bfs(int y, int x){
    initialize();
    
    queue<Node> q;
    q.push(Node(y,x));
    chese[y][x] = 0;
    
    while(!q.empty()){
        int current_y = q.front().y;
        int current_x = q.front().x;
        q.pop();
        

        if(current_y==end_point.y&&current_x==end_point.x){
            return chese[current_y][current_x];
        }
        
        for(int i=0;i<8;i++){
            int nextY = current_y+moveY[i];
            int nextX = current_x+moveX[i];
            
            if(0 <= nextY && nextY < cnt && 0 <= nextX && nextX < cnt){
                if(visit[nextY][nextX]!=1){
                    visit[nextY][nextX]=1;
                    q.push(Node(nextY, nextX));
                    
                    chese[nextY][nextX] = min(chese[nextY][nextX],chese[current_y][current_x]+1);
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    cin>>N;
    for(int i=0;i<N;i++){
        memset(visit, 0, sizeof(visit));
        cin>>cnt;
        cin>>start_point.y>>start_point.x;
        cin>>end_point.y>>end_point.x;
        result.push_back(bfs(start_point.y,start_point.x));
    }
    
    for(int i=0;i<(int)result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
