//
//  main.cpp
//  baekjoon_1197_최소스패닝트리
//
//  Created by 김대교 on 2020/05/29.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

 입력
 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

 출력
 첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int getParent(int parent[], int a){
    if(parent[a]==a) return a;
    return parent[a] = getParent(parent, parent[a]);
}

void unionparent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a<=b) parent[b]=a;
    else parent[a]=b;
}

bool findCycle(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a==b) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int v,e,answer=0;
    vector<vector<int>> data;
    //vector<int> parent;
    int parent[10001];
    
    cin>>v>>e;
    for(int i=0;i<=10001;i++){
        parent[i]=i;
    }
    
    for(int i=0;i<e;i++){
        vector<int> tmp;
        int a,b,c;
        cin>>a>>b>>c;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        
        data.push_back(tmp);
    }
    
    sort(data.begin(), data.end(), sorting);
    
    for(int i=0;i<data.size();i++){
        if(!findCycle(parent, data[i][0], data[i][1])){
            answer+=data[i][2];
            unionparent(parent, data[i][0], data[i][1]);
        }
    }
    
    
    cout<<answer<<endl;
    
    return 0;
}
