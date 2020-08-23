//
//  main.cpp
//  baekjoon_1929_소수구하기
//
//  Created by 김대교 on 2020/06/18.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

 입력
 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

 출력
 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */

#include <iostream>
#include <cmath>

using namespace std;

int n,m;
int num[1000001] = {0,};

int main(int argc, const char * argv[]) {
//    cin>>n>>m;
    scanf("%d %d",&n,&m);
    
    for(int i=2;i<=m;i++){
        num[i]=i;
    }
    
    for(int i=2;i<=sqrt(m);i++){
        if(num[i]==0){
            continue;
        }
        for(int j=i+i;j<=m;j+=i){
            num[j] = 0;
        }
    }
    
    for(int i=n;i<=m;i++){
        if(num[i]!=0){
            printf("%d\n",num[i]);
//            cout<<num[i]<<endl;
        }
    }
    
    return 0;
}
