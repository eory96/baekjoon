//
//  main.cpp
//  baekjoon_2234_성곽
//
//  Created by 김대교 on 2020/03/27.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다. 이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.

 이 성에 있는 방의 개수
 가장 넓은 방의 넓이
 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
 위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.

 성은 m×n(1 ≤ m, n ≤ 50)개의 정사각형 칸으로 이루어진다. 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

 입력
 첫째 줄에 두 정수 n, m이 주어진다. 다음 m개의 줄에는 n개의 정수로 벽에 대한 정보가 주어진다. 벽에 대한 정보는 한 정수로 주어지는데, 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다. 참고로 이진수의 각 비트를 생각하면 쉽다. 따라서 이 값은 0부터 15까지의 범위 안에 있다.

 출력
 첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int map[51][51];
bool visit[51][51];

pair<int,int> check_dir[4] = {{0,-1},{-1,0},{0,1},{1,0}};

int one_size=0;
int two_size=0;

int bfs(int y, int x){
    
    queue<pair<int,int>> q;
    q.push({y,x});
    
    visit[y][x]=true;
    int size = 1;
    
    while (!q.empty()) {
        int current_y = q.front().first;
        int current_x = q.front().second;
        
        q.pop();
        int bit=1;
        
        for(int i=0;i<4;i++){
            if(!(map[current_y][current_x]&bit)){
                int next_x = current_x + check_dir[i].second;
                int next_y = current_y + check_dir[i].first;
                
                if(!(0<=next_y&&next_y<m&&next_x<n&&0<=next_x)){
                    continue;
                }
                
                if(!visit[next_y][next_x]){
                    size++;
                    visit[next_y][next_x] = true;
                    q.push({next_y,next_x});
                }
            }
            bit<<=1;
        }
    }
    
    return size;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int room_cnt=0;

    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                room_cnt++;
                one_size = max(one_size, bfs(i,j));
            }
        }
    }
    
    cout<<room_cnt<<endl;
    cout<<one_size<<endl;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<=8;k<<=1){
                if(k&map[i][j]){
                    memset(visit, false, sizeof(visit));
                    map[i][j]-=k;
                    two_size = max(two_size, bfs(i,j));
                    map[i][j]+=k;
                }
            }
        }
    }
    
    cout<<two_size<<endl;

    return 0;
}
