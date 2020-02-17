//
//  main.cpp
//  baekjoon_11650_좌표정렬하기
//
//  Created by 김대교 on 2020/01/27.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
pair<int,int> input[100000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d %d",&input[i].first,&input[i].second);
        //cin>>input[i].first>>input[i].second;
    }
    
    sort(input, input+n, cmp);
    
    
    for(int i=0;i<n;i++){
        printf("%d %d\n",input[i].first,input[i].second);
        //cout<<input[i].first<<' '<<input[i].second<<endl;
    }
//    int n;
//    int temp1,temp2;
//    int input2[200000];
//
//    cin>>n;
//
//
//    for(int i=0; i<n*2; i+=2){
//        cin>>input2[i]>>input2[i+1];
//    }
//
//    for(int a=0;a<(n*2)-2;a+=2){
//        for(int i=0; i<(n*2)-2;i+=2){
//            if(input2[i]>input2[i+2]){
//                temp1 = input2[i];
//                input2[i]=input2[i+2];
//                input2[i+2] = temp1;
//
//                temp2 = input2[i+1];
//                input2[i+1] = input2[i+3];
//                input2[i+3] = temp2;
//            }else if(input2[i]==input2[i+2]&&input2[i+1]>input2[i+3]){
//                temp2 = input2[i+1];
//                input2[i+1] = input2[i+3];
//                input2[i+3] = temp2;
//            }
//        }
//    }
//
//
//    cout<<endl;
//    for(int i=0;i<n*2;i+=2){
//        cout<<input2[i]<<' '<<input2[i+1]<<endl;
//
//    }
    
    
    
    return 0;
}
