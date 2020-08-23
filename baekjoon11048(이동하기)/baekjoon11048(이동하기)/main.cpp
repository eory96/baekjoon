//
//  main.cpp
//  baekjoon11048(이동하기)
//
//  Created by 김대교 on 2019. 7. 30..
//  Copyright © 2019년 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int twoDArray[1001][1001],dp[1001][1001];

int main() {
    int n,m;
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            cin>>twoDArray[a][b];
        }
    }
    
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            dp[a][b]=max(dp[a][b-1], max(dp[a-1][b],dp[a-1][b-1]))+twoDArray[a][b];
        }
    }
    
    cout<<dp[n][m];
}
