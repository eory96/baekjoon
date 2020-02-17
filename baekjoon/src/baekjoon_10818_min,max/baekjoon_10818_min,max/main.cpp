//
//  main.cpp
//  baekjoon_10818_min,max
//
//  Created by 김대교 on 2019/12/30.
//  Copyright © 2019 김대교. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    int length=0;
    int min=1000000;
    int max=-1000000;
    int arr[1000000]={0};
    cin>>length;
    for(int i=0;i<length;i++){
        cin>>arr[i];
    }
    for(int i=0;i<length;i++){
        if(min>=arr[i]){
            min=arr[i];
        }
        if(max<=arr[i]){
            max=arr[i];
        }
    }
    cout<<min<<" "<<max<<endl;
    return 0;
}
