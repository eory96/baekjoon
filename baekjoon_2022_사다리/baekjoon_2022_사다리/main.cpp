//
//  main.cpp
//  baekjoon_2022_사다리
//
//  Created by 김대교 on 2020/03/05.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace  std;

double x,y,c;
double result=0;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cin>>x>>y>>c;
    
    double left, right, mid;
    right = min(x,y);
    left = 0;
    
    while(right - left > 0.0000009){
        mid = (left+right)/2;
        
        double h1 = sqrt(y*y-mid*mid);
        double h2= sqrt(x*x-mid*mid);
        double tempC = (h1*h2)/(h1+h2);
        
        if(tempC>=c){
            result = mid;
            left = mid;
        }else{
            right=mid;
        }
    }
    
    cout<<fixed;
    cout.precision(3);
    cout<<result<<endl;
    return 0;
}
