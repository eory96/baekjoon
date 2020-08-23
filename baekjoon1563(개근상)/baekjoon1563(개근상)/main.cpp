//
//  main.cpp
//  baekjoon1563(개근상)
//
//  Created by 김대교 on 2019. 8. 4..
//  Copyright © 2019년 김대교. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int N;
//int dp1[1001][3][4]={-1};
vector<vector<vector<int>>>dp1(1001, vector<vector<int>>(3, vector<int>(4,-1)));
int solver(int n, int late, int absence){
    if(absence>=3||late>=2){
        return 0;
    }
    
    if(n==N){
        return 1;
    }
    
    int &ret = dp1[n][late][absence];
    
    if(ret!=-1)
        return ret;
    
    return ret = (solver(n+1, late, 0)
            +solver(n+1, late+1, 0)
            +solver(n+1, late, absence+1))%1000000;
}

int main(int argc, const char * argv[]) {
    cin>>N;
    cout<<solver(0, 0, 0)<<endl;
        
    return 0;
}

