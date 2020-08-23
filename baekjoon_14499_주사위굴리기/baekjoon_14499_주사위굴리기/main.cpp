//
//  main.cpp
//  baekjoon_14499_주사위굴리기
//
//  Created by 김대교 on 2020/08/04.
//  Copyright © 2020 김대교. All rights reserved.
//
/*
 문제
 크기가 N×M인 지도가 존재한다. 지도의 오른쪽은 동쪽, 위쪽은 북쪽이다. 이 지도의 위에 주사위가 하나 놓여져 있으며, 주사위의 전개도는 아래와 같다. 지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다.

   2
 4 1 3
   5
   6
 주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며, 놓여져 있는 곳의 좌표는 (x, y) 이다. 가장 처음에 주사위에는 모든 면에 0이 적혀져 있다.

 지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.

 주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.

 주사위는 지도의 바깥으로 이동시킬 수 없다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

 입력
 첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20), 주사위를 놓은 곳의 좌표 x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

 둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 지도의 각 칸에 쓰여 있는 수는 10을 넘지 않는 자연수 또는 0이다.

 마지막 줄에는 이동하는 명령이 순서대로 주어진다. 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.

 출력
 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int dice[4][3]={0};
int map[21][21]={0};
int order[1000]={0};
int n,m,x,y,k;

//여기서 x,y는 주사위의 다음 위치를 의미함.
void change(int id,int y,int x){
    if(id==1){
        int temp1 = dice[1][0];
        int temp2 = dice[1][1];
        int temp3 = dice[1][2];
        int temp4 = dice[3][1];
        
        if(map[y][x]==0){
            map[y][x] = temp3;
            dice[3][1] = temp3;
        }else{
            dice[3][1] = map[y][x];
            map[y][x] = 0;
        }
        dice[1][0] = temp4;
        dice[1][1] = temp1;
        dice[1][2] = temp2;
    }else if(id==2){
        int temp1 = dice[1][0];
        int temp2 = dice[1][1];
        int temp3 = dice[1][2];
        int temp4 = dice[3][1];
        
        if(map[y][x]==0){
            map[y][x] = temp1;
            dice[3][1] =temp1;
        }else{
            dice[3][1] = map[y][x];
            map[y][x] = 0;
        }
        dice[1][0] = temp2;
        dice[1][1] = temp3;
        dice[1][2] = temp4;
    }else if(id==3){
        int temp1 = dice[0][1];
        int temp2 = dice[1][1];
        int temp3 = dice[2][1];
        int temp4 = dice[3][1];
        
        if(map[y][x]==0){
            map[y][x] = temp1;
            dice[3][1] = temp1;
        }else{
            dice[3][1] = map[y][x];
            map[y][x] = 0;
        }
        dice[0][1] = temp2;
        dice[1][1] = temp3;
        dice[2][1] = temp4;
    }else{
        int temp1 = dice[0][1];
        int temp2 = dice[1][1];
        int temp3 = dice[2][1];
        int temp4 = dice[3][1];
        
        if(map[y][x]==0){
            map[y][x] = temp3;
            dice[3][1] = temp3;
        }else{
            dice[3][1] = map[y][x];
            map[y][x] = 0;
        }
        dice[0][1] = temp4;
        dice[1][1] = temp1;
        dice[2][1] = temp2;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>n>>m>>y>>x>>k;
    int nextX=x;
    int nextY=y;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    
    
    for(int i=0;i<k;i++){
        cin>>order[i];
    }
    
    for(int i=0;i<k;i++){
        if(order[i]==1){
            if(nextX+1==m)
                continue;
            nextX++;
        }else if(order[i]==2){
            if(nextX-1<0)
                continue;
            nextX--;
        }else if(order[i]==3){
            if(nextY-1<0)
                continue;
            nextY--;
        }else{
            if(nextY+1==n)
                continue;
            nextY++;
        }
        
        change(order[i], nextY, nextX);
        cout<<dice[1][1]<<endl;

    }

    return 0;
}
