//
//  main.cpp
//  baekjoon2167(2차원배열의합)
//
//  Created by 김대교 on 2019. 7. 28..
//  Copyright © 2019년 김대교. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int num1, num2,i,j,x,y,k,sum=0;
    int array[100][100]={{0,},{0,}};
    cin>>num1>>num2;
    
    for(int a=1;a<=num1;a++){
        for(int b=1;b<=num2;b++){
            cin>>array[a][b];
        }
    }
    
    cin>>k;
    
    for(int c=0;c<k;c++){
        cin>>i>>j>>x>>y;
        for(int d=i;d<=x;d++){
            for(int e=j;e<=y;e++){
                sum+=array[d][e];
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
}


//#include <stdio.h>
//
//
//
//int main(){
//    int i, j, k, x, y, t, n, m, x2, y2, sum = 0;
//    int num[300][300] = {{0, },{0, }};
//
//    scanf("%d %d", &x, &y);
//
//    for(i = 0; i < x; i++){
//        for(j = 0; j < y; j++){
//            scanf("%d", &num[i][j]);
//        }
//    }
//
//    scanf("%d", &t);
//
//    for(k = 0; k < t; k++){
//        scanf("%d %d %d %d", &x2, &y2, &n, &m);
//
//        for(i = x2 - 1; i < n; i++){
//            for(j = y2 - 1; j < m; j++){
//                sum += num[i][j];
//            }
//        }
//        printf("%d\n", sum);
//        sum = 0;
//    }
//}
