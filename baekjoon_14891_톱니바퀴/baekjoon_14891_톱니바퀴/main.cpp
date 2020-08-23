//
//  main.cpp
//  baekjoon_14891_톱니바퀴
//
//  Created by 김대교 on 2020/08/02.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>

using namespace std;
string gears[4];

int k;
bool visit[4]={false};

void turnRight(int where){
    int first = gears[where][0];
    for(int i=0;i<7;i++){
        gears[where][i] = gears[where][i+1];
    }
    gears[where][7] = first;
}

void turnLeft(int where){
    int last = gears[where][7];
    for(int i=7;i>0;i--){
        gears[where][i] = gears[where][i-1];
    }
    gears[where][0] = last;
}

void getAnswer(int where,int direction){
    visit[where] = true;
    int nextGear = where+1;
    int prevGear = where-1;
    
    if(prevGear>=0&&!visit[prevGear]){
        if(gears[where][6]!=gears[prevGear][2]){
            getAnswer(prevGear, direction*-1);
        }
    }
    
    if(nextGear<4&&!visit[nextGear]){
        if(gears[where][2]!=gears[nextGear][6]){
            getAnswer(nextGear, direction*-1);
        }
    }
    
    if(direction==1){
        turnLeft(where);
    }else{
        turnRight(where);
    }
}

int main(int argc, const char * argv[]) {
    int answer=0;
    
    cin>>gears[0];
    cin>>gears[1];
    cin>>gears[2];
    cin>>gears[3];

    cin>>k;
    for(int i=0;i<k;i++){
        int temp1;
        int temp2;
        cin>>temp1>>temp2;
        getAnswer(temp1-1, temp2);
        visit[0] = false;
        visit[1] = false;
        visit[2] = false;
        visit[3] = false;
//        memset(visit, false, sizeof(visit));
    }
            
    if(gears[0][0]=='1')answer+=1;
    if(gears[1][0]=='1') answer+=2;
    if(gears[2][0]=='1') answer+=4;
    if(gears[3][0]=='1') answer+=8;
    
    cout<<answer;
    return 0;
}
