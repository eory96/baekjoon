//
//  main.cpp
//  baekjoon_2110_공유기_설치
//
//  Created by 김대교 on 2020/01/19.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int c,n;//집의 갯수 :c, 공유기의 갯수 :n
    int input[1000000];
    int left,right,mid;
    int max=0;
    
    cin >>c>>n;
    for(int i=0;i<c;i++){
        cin>>input[i];
    }
    sort(input,input+c);
    left=1;
    right=input[c-1]-input[0];
    
    while(left<=right){
        mid=(left+right)/2;
        int start=input[0];
        int cnt=1;
        
        for(int a=1;a<c;a++){
            if(input[a]-start>=mid){
                cnt++;
                start=input[a];
            }
        }
        
        if(cnt<n){
            right=mid-1;
        }else{
            left=mid+1;
            max=mid;
        }
    }
    
    cout<<max;
    
    
    return 0;
}
