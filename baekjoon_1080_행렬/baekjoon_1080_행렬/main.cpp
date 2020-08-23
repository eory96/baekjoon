//
//  main.cpp
//  baekjoon_1080_행렬
//
//  Created by 김대교 on 2020/05/26.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

 행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 -> 1, 1 -> 0)

 입력
 첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.

 출력
 첫째 줄에 문제의 정답을 출력한다. 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.
 
 3 4
 0000
 0010
 0000
 1001
 1011
 1001
 
 ===>2
 */
#include <iostream>
#include <vector>

using namespace std;

int n,m;
int mp[51][51];
int toMake[51][51];

int main(int argc, const char * argv[]) {
    // insert code here...
    int cnt=0;
    bool flag = false;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&mp[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&toMake[i][j]);
        }
    }
    
    for(int i=0;i+2<n;i++){
        for(int j=0;j+2<m;j++){
            if(mp[i][j]!=toMake[i][j]){
                mp[i][j]= mp[i][j]==1?0:1;
                mp[i][j+1]= mp[i][j+1]==1?0:1;
                mp[i][j+2]= mp[i][j+2]==1?0:1;
                mp[i+1][j]= mp[i+1][j]==1?0:1;
                mp[i+1][j+1]= mp[i+1][j+1]==1?0:1;
                mp[i+1][j+2]= mp[i+1][j+2]==1?0:1;
                mp[i+2][j]= mp[i+2][j]==1?0:1;
                mp[i+2][j+1]= mp[i+2][j+1]==1?0:1;
                mp[i+2][j+2]= mp[i+2][j+2]==1?0:1;
                cnt++;
            }
        }
    }
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]!=toMake[i][j]) {
                flag = true;
            }
        }
    }
    
    if(flag) cout<<-1;
    else cout<<cnt;
}
