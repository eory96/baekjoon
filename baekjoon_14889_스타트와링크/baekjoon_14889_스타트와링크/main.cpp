//
//  main.cpp
//  baekjoon_14889_스타트와링크
//
//  Created by 김대교 on 2020/02/24.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S[21][21];
bool is_team1[21];
int ans=99999;

void dfs(int currnet, int cnt){
    if(cnt==N/2){
        vector<int> team1,team2;
        
        for(int i=0;i<N;i++){
            if(is_team1[i]) team1.push_back(i);
            else team2.push_back(i);
        }
        
        int team1_stat=0;
        int team2_stat=0;
        for(int i=0;i<N/2;i++){
            for(int j=i+1;j<N/2;j++){
                int team1_x = team1[i];
                int team1_y = team1[j];
                int team2_x = team2[i];
                int team2_y = team2[j];
                
                team1_stat += S[team1_x][team1_y]+S[team1_y][team1_x];
                team2_stat += S[team2_x][team2_y]+S[team2_y][team2_x];
            }
        }
        
        ans = min(ans, abs(team1_stat-team2_stat));
        
        return ;
    }
    
    for(int a=currnet+1;a<N;a++){
        if(is_team1[a]==false){
            is_team1[a]=true;
            dfs(a, cnt+1);
            is_team1[a]=false;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>N;
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            cin>>S[a][b];
        }
    }
    
    dfs(0,0);
    
    cout<<ans;
    
//    for(int i=0;i<N;i++){
//        cout<<is_team1[i]<<endl;
//    }
    
    return 0;
}
