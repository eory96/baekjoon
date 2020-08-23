//
//  main.cpp
//  baekjoon_15686_치킨배달
//
//  Created by 김대교 on 2020/06/14.
//  Copyright © 2020 김대교. All rights reserved.
//

/*
 문제
 크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.

 이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

 임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

 예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.

 0 2 0 1 0
 1 0 1 0 0
 0 0 0 0 0
 0 0 0 1 1
 0 0 0 1 2
 0은 빈 칸, 1은 집, 2는 치킨집이다.

 (2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.

 (5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.

 이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

 도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

 입력
 첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

 둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

 도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

 출력
 첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> cPos;
vector<pair<int,int>> hPos;


vector<bool> visit;

int answer = 99999;
int map[51][51]={0,};

void dfs(int cnt,int idx){
    if(cnt==m){
//        for(int i=0;i<visit.size();i++){
//            cout<<visit[i]<<" ";
//        }
//        cout<<endl;
//
        vector<pair<int, int>> selected;
        
        for(int i=0;i<visit.size();i++){
            if(visit[i]){
                selected.push_back(make_pair(cPos[i].first, cPos[i].second));
            }
        }
        
        int tempA = 0;
        for(int i=0;i<hPos.size();i++){
            int temp = 99999;
            for(int j=0;j<selected.size();j++){
                temp = min(temp, abs(selected[j].first - hPos[i].first)+abs(selected[j].second - hPos[i].second));
            }
            tempA += temp;
        }
        
        answer = min(answer, tempA);
        
        return;
    }
    
    for(int i=idx;i<visit.size();i++){
        if(visit[i]) continue;
        visit[i] = true;
        dfs(cnt+1,i);
        visit[i] = false;
    }
}

int main(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==1) hPos.push_back(make_pair(i, j));
            if(map[i][j]==2){
                cPos.push_back(make_pair(i, j));
                visit.push_back(false);
            }
        }
    }
    
    dfs(0,0);
    
    cout<<answer;
    
    return 0;
}
//
//int main(int argc, const char * argv[]) {
//    cin>>n>>m;
//    int answer = 100000;
//    int temp;
//
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cin>>map[i][j];
//
//            if(map[i][j]==2) cPos.push_back(make_pair(i, j));
//            if(map[i][j]==1) hPos.push_back(make_pair(i, j));
//        }
//    }
//
//    do{
//        vector<pair<int,int>> selected;
//        for(int i=0;i<m;i++){
//            selected.push_back(cPos[i]);
//        }
//        int tempA=0;
//
//        for(int i=0;i<hPos.size();i++){
//            temp=100000;
//            for(int k=0;k<m;k++){
//                temp = min(temp,abs(hPos[i].first-selected[k].first)+abs(hPos[i].second-selected[k].second));
//            }
//            tempA+=temp;
//        }
//
//        answer = min(tempA, answer);
//
//    }while(next_permutation(cPos.begin(), cPos.end()));
//
//    cout<<answer;
//
//    return 0;
//}
