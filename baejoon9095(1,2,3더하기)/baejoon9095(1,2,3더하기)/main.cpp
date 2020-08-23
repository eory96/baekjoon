//
//  main.cpp
//  baejoon9095(1,2,3더하기)
//
//  Created by 김대교 on 2019. 7. 27..
//  Copyright © 2019년 김대교. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int input = 0;
    int inputList[12]={0,};
    int dp[12];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for(int a=4;a<12;a++){
        dp[a]=dp[a-1]+dp[a-2]+dp[a-3];
    }

    cin>>input;
    
    for(int a=1;a<=input;a++){
        cin>>inputList[a];
    }
    
    for(int a=1;a<=input;a++){
        cout<<dp[inputList[a]]<<endl;
    }
    
    return 0;
}
