//
//  main.cpp
//  baekjoon_2688_숫자고르기
//
//  Created by 김대교 on 2020/03/08.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;
vector<int> visited;
vector<int> ans;

void dfs(int start, int current){
    if(visited[current]){
        if(start==current){
            ans.push_back(start);
        }
    }
    else{
        visited[current]=1;
        dfs(start,vec[current]);
    }
}

int main(int argc, const char * argv[]) {
    cin>>N;
    vec = vector<int> (N+1,0);
    visited = vector<int> (N+1,0);
    
    for(int i=1;i<=N;i++){
        scanf("%d",&vec[i]);
    }
    
    for(int i=1;i<=N;i++){
        dfs(i,i);
        visited=vector<int> (N+1,0); //초기화
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
