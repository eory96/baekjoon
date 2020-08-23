/*
 문제
 <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



 입력
 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

 출력
 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];
int visit[25][25]={false};

int ySet[4]={1,0,-1,0};
int xSet[4]={0,1,0,-1};
int N;
int answer[25];

int num=2;
int section=0;
vector<int> v;

bool inRange(int y,int x){
    return y>=0&&x>=0&&y<N&&x<N;
}

void bfs(int y,int x,int cnt){
    queue<pair<int, int>> q;
    q.push({y,x});
    map[y][x] = num;
    visit[y][x] = true;
    
    while(!q.empty()){
        int currentY = q.front().first;
        int currentX = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nextY = currentY+ySet[i];
            int nextX = currentX+xSet[i];
            if(inRange(nextY, nextX)&&!visit[nextY][nextX]&&map[nextY][nextX]==1){
                map[nextY][nextX] = num;
                visit[nextY][nextX] = true;
                q.push({nextY,nextX});
                cnt++;
            }
        }
    }
    num++;
    section++;
    v.push_back(cnt);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

//    bfs(0, 0,0);
//    cout<<bfs(0, 0,0);
//
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]&&map[i][j]==1){
                bfs(i, j, 1);
            }
        }
    }
    
    cout<<section<<endl;
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cout<<map[i][j];
//        }
//        cout<<endl;
//    }
    
    return 0;
}
