 //
//  main.cpp
//  baekjoon_9663_N_Queen
//
//  Created by 김대교 on 2020/06/10.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

 N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

 입력
 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

 출력
 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> col(16);
int n;
int answer = 0;

bool isPossible(int row){
    for(int i=1;i<row;i++){
        if(col[row]==col[i])
            return false;
        if(abs(col[row]-col[i])==abs(row-i))
            return false;
    }
    return true;
}

void dfs(int row){
    if(row>n){
        answer++;
    }else{
        for(int i=1;i<=n;i++){
            col[row] = i;
            
            if(isPossible(row)){
                dfs(row+1);
            }else{
                col[row] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for(int i=1;i<=n;i++){
        col = vector<int>(16);
        col[1] = i;
        
        dfs(2);
    }
    
    cout<<answer<<endl;
    return 0;
}
