//
//  main.cpp
//  baekjoon_1011_Fly me to the Alpha Centauri
//
//  Created by 김대교 on 2020/05/17.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> point;
bool visit[1000001] = {false};

void bfs(int start,int end,int cnt){
    queue<pair<int,int>> q;
    q.push(make_pair(start, 0));
    visit[start] = true;
    
    while (!q.empty()) {
        <#statements#>
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>N;
    for(int i=0;i<N*2;i++){
        int temp;
        cin>>temp;
        point.push(temp);
    }
    
    while(!point.empty()){
        int start = point.front();
        point.pop();
        int end = point.front();
        point.pop();
        
        
    }
    
    return 0;
}
