//
//  main.cpp
//  baekjoon_11724_연결요소의개수
//
//  Created by 김대교 on 2020/03/21.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

 입력
 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

 출력
 첫째 줄에 연결 요소의 개수를 출력한다.
 */

#include <iostream>

using namespace std;

int N,M;
int u,v;
int graph[1001][1001];
bool visit[1001]={false};
int cnt=0;

void dfs(int where){
    visit[where]=true;
    
    for(int i=1;i<=N;i++){
        if(visit[i]==true||graph[where][i]==0){
            continue;
        }else{
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    
    for(int i=1;i<=N;i++){
        if(visit[i]==false){
            dfs(i);
            cnt++;
        }
    }
    
    cout<<cnt;
    
    return 0;
}
