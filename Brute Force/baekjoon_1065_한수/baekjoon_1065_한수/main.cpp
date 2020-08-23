//
//  main.cpp
//  baekjoon_1065_한수
//
//  Created by 김대교 on 2020/03/18.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
using namespace std;
int cnt=0;
int N;

bool hansu(int i){
    bool judge=true;
    int dif = (i%100)/10-i%10;
    int temp[4];
    int a=0;
    
    while(i!=0){
        temp[a]=i%10;
        a++;
        i/=10;
    }
    
    for(int i=0;i<a-1;i++){
        if(temp[i+1]-temp[i]==dif){
            judge=true;
        }else{
            judge=false;
            break;
        }
    }

    return judge;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>N;
    
    for(int i=1;i<=N;i++){
        if(hansu(i)==true){
            cnt++;
        }
    }
    cout<<cnt;
    
    return 0;
}
