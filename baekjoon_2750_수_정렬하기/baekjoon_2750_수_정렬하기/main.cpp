//
//  main.cpp
//  baekjoon_2750_수_정렬하기
//
//  Created by 김대교 on 2020/01/14.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int length;
    int input[1000];
    int temp;
    
    cin>>length;
    for(int i=0;i<length;i++){
        cin>>input[i];
    }
    
    int b;
    
    for(int a=0;a<length;a++){
        b=a+1;
        while(b<length){
            if(input[a]>=input[b]){
                temp = input[a];
                input[a]=input[b];
                input[b]=temp;
            }
            b++;
        }
    }
    
    for(int c=0;c<length;c++){
        cout<<input[c]<<endl;
    }
    return 0;
}
