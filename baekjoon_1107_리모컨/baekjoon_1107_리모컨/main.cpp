//
//  main.cpp
//  baekjoon_1107_리모컨
//
//  Created by 김대교 on 2020/06/01.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

 리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

 수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

 수빈이가 지금 보고 있는 채널은 100번이다.

 입력
 첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

 출력
 첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> mal;

bool isPossible(string temp){
    for(int i=0;i<temp.size();i++){
        auto iter=find(mal.begin(), mal.end(), temp[i]-'0');
        if(iter!=mal.end()){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int start=100;
    int standard=0;
    int standard2=0;
    
    cin>>n;
    cin>>m;
    standard = n;
    standard2 = n;
    
    
    
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        mal.push_back(temp);
    }
    
    if((n>97&&n<103)||m==10){
        cout<<abs(n-start)<<endl;
        return 0;
    }
//    if(n==100){
//        cout<<0<<endl;
//        return 0;
//    }
//
//    if(mal.size()==10){
//        cout<<abs(n-start)<<endl;
//        return 0;
//    }
    
    while(!isPossible(to_string(standard))&&!isPossible(to_string(standard2))){
//        string temp = to_string(standard);
//        isPossible(temp);
//        if(isPossible(temp)) break;
//        else{
//            standard++;
//        }
        standard++;
        if(standard2>0) standard2--;
    }
    
//    while(true){
//        bool flag = true;
//        string temp = to_string(standard2);
//        for(int i=0;i<temp.size();i++){
//            auto iter = find(mal.begin(), mal.end(), temp[i]-'0');
//            if(iter!=mal.end()){
//                flag=false;
//                break;
//            }
//        }
//        if(flag) break;
//        else{
//            standard2--;
//        }
//    }
    
    int r=0;
    
//    if(standard-n<n-standard2) r = standard;
//    else r = standard2;
    r = standard;
    if(isPossible(to_string(standard2))) r = standard2;
    
    int answer=0;
    
    if(to_string(r).size()+abs(n-r)<abs(n-start)) answer = (int)to_string(r).size()+abs(n-r);
    else answer = abs(n-start);
    
    cout<<answer<<endl;

    return 0;
}
