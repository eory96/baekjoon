//
//  main.cpp
//  baekjoon_1074_Z
//
//  Created by 김대교 on 2020/05/17.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N,r,c;
int cnt=0;

void Z(int y,int x,int range){
    if(range==2){
        if(y==r&&x==c){
            cout<<cnt;
            return;
        } else{
            cnt++;
        }
        
        if(r==y && c==x+1){
            cout<<cnt;
            return;
        }else{
            cnt++;
        }
        
        if(r==y+1 && c==x){
            cout<<cnt;
            return;
        }else{
            cnt++;
        }
        
        if(r==y+1 && c==x+1){
            cout<<cnt;
            return;
        }else{
            cnt++;
        }
        
        return;
    }
    
    
    Z(y,x,range/2);
    Z(y,x+range/2,range/2);
    Z(y+range/2,x,range/2);
    Z(y+range/2,x+range/2,range/2);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin>>N>>r>>c;
    Z(0,0,pow(2,N));
    return 0;
}
