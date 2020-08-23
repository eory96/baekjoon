//
//  main.cpp
//  baekjoon_1697_숨바꼭질
//
//  Created by 김대교 on 2020/05/15.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer=100;
int visit[100001]={false};

int BFS(int current,int K){
    queue<pair<int,int>> q;
    q.push(make_pair(current, 0));
    visit[current] = true;
    
    while (!q.empty()) {
        int position = q.front().first;
        int times = q.front().second;
        q.pop();
        
        if(position==K) return times;
        
        if(position+1<=100000&&!visit[position+1]){
            q.push(make_pair(position+1, times+1));
            visit[position+1] = true;
        }
        if(position-1>=0&&!visit[position-1]){
            q.push(make_pair(position-1, times+1));
            visit[position-1] = true;
        }
        if(position*2<=100000&&!visit[position*2]){
            q.push(make_pair(position*2, times+1));
            visit[position*2] = true;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K;
    cin>>N>>K;
    
    
    cout<<BFS(N,K);
    
    return 0;
}
