//
//  main.cpp
//  baekjoon11054(바이토닉수열)
//
//  Created by 김대교 on 2019. 8. 3..
//  Copyright © 2019년 김대교. All rights reserved.
//


#include<stdio.h>
#include<algorithm>

int a[1000+1];
int dp[1000+1];
int dp2[1000+1];

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=0; i<tc; i++)
        scanf("%d",&a[i]);

    for(int i=0; i<tc; i++){
        dp[i] = 1;
        dp2[tc-1-i] = 1;
        for(int j=0; j<i; j++)
        {
            if(a[i] > a[j] && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;
            if(a[tc-i-1] > a[tc-j-1] && dp2[tc-j-1]+1 > dp2[tc-i-1])
                dp2[tc-i-1] = dp2[tc-j-1] + 1;
        }
    }

    int result = dp2[0]+dp[0];
    for(int i=0; i<tc ; i++)
        if(result < dp[i]+dp2[i]) result = dp2[i]+dp[i];

    printf("%d\n",result-1);

}



