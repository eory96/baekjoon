//
//  main.cpp
//  baekjoon_11047_coin0
//
//  Created by 김대교 on 2020/01/15.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int k;
    int kind[11];
    int count=0;
    
    cin>>n>>k;
    for(int i=1; i<=n;i++){
        cin>>kind[i];
    }

    for(int a=n;a>0;a--){
        count+=k/kind[a];
        k%=kind[a];
    }
    
    cout<<count<<endl;
    return 0;
}
