//
//  main.cpp
//  baekjoon_2231_분해합
//
//  Created by 김대교 on 2020/01/01.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int input;
    int sum;
    int part;
    cin>>input;
    
    for(int i=1;i<input;i++){
        sum=i;
        part=i;
        while(part){
            sum+=part%10;
            part=part/10;
        }
        
        if(sum==input){
            cout<<i<<endl;
            return 0;
        }
    }
    
    cout<<0<<endl;
    
    return 0;
}
