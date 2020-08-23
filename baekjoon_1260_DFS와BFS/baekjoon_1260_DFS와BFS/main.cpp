//
//  main.cpp
//  baekjoon_1260_DFS와BFS
//
//  Created by 김대교 on 2020/06/12.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

 입력
 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

 출력
 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int m;
int v;
bool visit1[1001] = {false,};
bool visit2[1001] = {false,};
int map[1001][1001] = {0,};

void dfs(int where){
    visit1[where] = true;
    cout<<where<<" ";
    for(int i=1;i<=n;i++){
        if(visit1[i]==true||map[where][i]==0) continue;
        dfs(i);
    }
}

void bfs(int where){
    visit2[where] = true;
    queue<int> q;
    q.push(where);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        cout<<current<<" ";
        
        for(int i=1;i<=n;i++){
            if(visit2[i]==true||map[current][i]==0) continue;
            else{
                visit2[i]=true;
                q.push(i);
            }
            
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>n>>m>>v;
    
    for(int i=0;i<m;i++){
        int temp1;
        int temp2;

        cin>>temp1>>temp2;
        
        map[temp1][temp2] = 1;
        map[temp2][temp1] = 1;
    }
  
    dfs(v);
    cout<<endl;
    bfs(v);
    
    return 0;
}
