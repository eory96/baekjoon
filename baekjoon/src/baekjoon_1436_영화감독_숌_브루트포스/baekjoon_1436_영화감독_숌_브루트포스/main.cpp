//
//  main.cpp
//  baekjoon_1436_영화감독_숌_브루트포스
//
//  Created by 김대교 on 2020/01/26.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int num=666;
    int temp;
    int i=0;
    bool check=false;
    cin>>n;
    
    while(true){
        check=false;
        temp=num;
        while(temp){
            if(temp%1000==666){
                check=true;
                break;
            }else{
                temp=temp/10;
            }
        }
        
        if(check==true){
            i++;
            if(i==n){
                break;
            }
        }
        num++;
        
    }
    
    cout<<num<<endl;
    return 0;
}
