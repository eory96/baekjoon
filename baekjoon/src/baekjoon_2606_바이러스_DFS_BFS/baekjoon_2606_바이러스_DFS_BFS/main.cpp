//
//  main.cpp
//  baekjoon_2606_바이러스_DFS_BFS
//
//  Created by 김대교 on 2020/01/23.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int comNum;
int n;
int input[101][101]={0};
int visit[101]={0};
int queue[10001];
 
void bfs(){
    
}

void dfs(int where){
    visit[where]=1;
    for(int i=1;i<=comNum;i++){
        if(visit[i]==1||input[where][i]==0) continue;
        else dfs(i);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int ans=0;
    cin>>comNum>>n;
    
    for(int i=0; i<n;i++){
        int a,b;
        cin>>a>>b;
        input[a][b]=1;
        input[b][a]=1;
    }
    
    dfs(1);
    
    for(int i=2;i<=comNum;i++){
        if(visit[i]==1)ans++;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
