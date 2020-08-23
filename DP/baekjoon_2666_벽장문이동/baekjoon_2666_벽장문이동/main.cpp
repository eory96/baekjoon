//
//  main.cpp
//  baekjoon_2666_벽장문이동
//
//  Created by 김대교 on 2020/03/25.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>

using namespace std;

int closetNum;
int closet[21]; //close : 0, open : 1
int useCnt;
int preOpen1,preOpen2;
int cnt=0;

int moveDoor(int turn, int preOpen1, int preOpen2, int cost){
//    if(abs(willOpen-preOpen1)<=abs(willOpen-preOpen2)){
//        cnt+=abs(willOpen-preOpen1);
//        preOpen1=willOpen;
//    }else{
//        cnt+=abs(willOpen-preOpen2);
//        preOpen2=willOpen;
//    }
    
    if(turn>useCnt) return cost;
    if(closet[turn]==preOpen1||closet[turn]==preOpen2) return moveDoor(turn+1, preOpen1, preOpen2, cost);
    
    return min(moveDoor(turn+1, closet[turn], preOpen2,cost+abs(closet[turn]-preOpen1)), moveDoor(turn+1, preOpen1, closet[turn], cost+ abs(closet[turn]-preOpen2)));
}

int main(int argc, const char * argv[]) {
    memset(closet, 0, 21);
    
    cin>>closetNum;
    cin>>preOpen1>>preOpen2;
    cin>>useCnt;
    
//    closet[preOpen1]=1;
//    closet[preOpen2]=1;
    
    for(int i=1;i<=useCnt;i++){
        int willOpen=0;
        cin>>willOpen;
        closet[i]=willOpen;
    }
    cout<<moveDoor(1,preOpen1,preOpen2,0);
    
    return 0;
}
