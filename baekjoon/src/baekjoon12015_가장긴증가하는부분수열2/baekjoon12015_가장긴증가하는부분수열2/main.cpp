//
//  main.cpp
//  baekjoon12015_가장긴증가하는부분수열2
//
//  Created by 김대교 on 2020/02/14.
//  Copyright © 2020 김대교. All rights reserved.
//
/*문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
        
    int N, temp, cnt = 0;
    vector <int> v;
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(v.empty()||temp>v.back()){
            v.push_back(temp);
            cnt++;
            //v vector가 비어있거나 맨뒤에것이 temp가 가장 v vector의 가장 뒤의것보다 작으면 vector에 데이터 넣기
        }else{
            auto low=lower_bound(v.begin(), v.end(),temp);
            *low=temp;
            //lower_bound는 v vector에서 temp 보다 크거나 같은 첫번째 원소를 가리킨다.(주소를 반환하게 된다.)
            //lower_bound가 binary search를 통해 해당 위치를 찾아내게 된다.
        }
    }
    
    cout<<cnt;
    
    return 0;
}
