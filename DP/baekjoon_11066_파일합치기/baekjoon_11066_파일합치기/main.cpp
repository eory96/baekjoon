//
//  main.cpp
//  baekjoon_11066_파일합치기
//
//  Created by 김대교 on 2020/03/26.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 소설가인 김대전은 소설을 여러 장(chapter)으로 나누어 쓰는데, 각 장은 각각 다른 파일에 저장하곤 한다. 소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어있는 한 개의 파일을 만든다. 이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속이 되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다. 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.

 예를 들어, C1, C2, C3, C4가 연속적인 네 개의 장을 수록하고 있는 파일이고, 파일 크기가 각각 40, 30, 30, 50 이라고 하자. 이 파일들을 합치는 과정에서, 먼저 C2와 C3를 합쳐서 임시파일 X1을 만든다. 이때 비용 60이 필요하다. 그 다음으로 C1과 X1을 합쳐 임시파일 X2를 만들면 비용 100이 필요하다. 최종적으로 X2와 C4를 합쳐 최종파일을 만들면 비용 150이 필요하다. 따라서, 최종의 한 파일을 만드는데 필요한 비용의 합은 60+100+150=310 이다. 다른 방법으로 파일을 합치면 비용을 줄일 수 있다. 먼저 C1과 C2를 합쳐 임시파일 Y1을 만들고, C3와 C4를 합쳐 임시파일 Y2를 만들고, 최종적으로 Y1과 Y2를 합쳐 최종파일을 만들 수 있다. 이때 필요한 총 비용은 70+80+150=300 이다.

 소설의 각 장들이 수록되어 있는 파일의 크기가 주어졌을 때, 이 파일들을 하나의 파일로 합칠 때 필요한 최소비용을 계산하는 프로그램을 작성하시오.

 입력
 프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T개의 테스트 데이터로 이루어져 있는데, T는 입력의 맨 첫 줄에 주어진다.각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K (3 ≤ K ≤ 500)가 주어진다. 두 번째 행에는 1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 주어진다. 파일의 크기는 10,000을 초과하지 않는다.

 출력
 프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<int> ans;
vector<int> page;
vector<int> temp;

int min1=100000;
int min2=100000;
int index1,index2;

void findTwoMin(){
    for(int i=0;i<page.size();i++){
        if(page[i]!=-1){
            if(min1>page[i]){
                min1 = page[i];
                index1 = i;
            }
        }
    }
    page[index1]=-1;
    for(int i=0;i<page.size();i++){
        if(page[i]!=-1){
            if(min2>page[i]){
                min2 = page[i];
                index2 = i;
            }
        }
    }
    
    page[index2] = min1+min2;
    temp.push_back(min1+min2);
    
    min1=2147483647;
    min2=2147483647;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>T;
    
    for(int i=0;i<T;i++){
        int a,page_cnt;
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>page_cnt;
            page.push_back(page_cnt);
        }
        sort(page.begin(),page.end());
        //int temp1=2147483647,temp2=2147483647;
        for(int k=0;k<a-1;k++){
            if(k==0){
                temp.push_back(page[0]+page[1]);
                page[1] = page[0]+page[1];
                page[0] = -1;
            }else{
                findTwoMin();
            }
        }
        int answering=0;
        for(int i=0;i<temp.size();i++){
            answering+=temp[i];
        }
        ans.push_back(answering);

        temp.clear();
        page.clear();
    }
    
    
   
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
