//
//  main.cpp
//  baekjoon_2178_미로찾기
//
//  Created by 김대교 on 2020/02/26.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 N×M크기의 배열로 표현되는 미로가 있다.

 1    0    1    1    1    1
 1    0    1    0    1    0
 1    0    1    0    1    1
 1    1    1    0    1    1
 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

 입력
 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

 출력
 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
 */

#include <iostream>
#include <queue>
using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

char arr[100][101];
bool visited[100][100];

int N, M;


bool inRange(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}



struct Node {
    int y, x, dist;
    Node(int y, int x, int dist):y(y), x(x), dist(dist) {}
};


int bfs(int sy, int sx) {
    queue<Node> q;
    
    
    q.push(Node(sy, sx, 1));
    visited[sy][sx] = true;
    
    
    while (!q.empty()) {
        Node here = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int ythere = here.y + dy[d], xthere = here.x + dx[d];
            if (inRange(ythere, xthere) && !visited[ythere][xthere] && arr[ythere][xthere] == '1') {
                visited[ythere][xthere] = true;
                q.push(Node(ythere, xthere, here.dist + 1));
                
                if (ythere == N - 1 && xthere == M - 1) return here.dist + 1;
                
            }
        }
    }
    return 0;
}


int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) cin>>arr[i];
    
    for(int i=0;i<N;i++){
        for(int a=0;a<M;a++){
            cout<<arr[i][a]<<" ";
        }
        cout<<endl;
    }
    
    cout << bfs(0, 0) << endl;
    
    
}
