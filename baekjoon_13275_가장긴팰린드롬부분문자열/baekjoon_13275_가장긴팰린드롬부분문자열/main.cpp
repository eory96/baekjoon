//
//  main.cpp
//  baekjoon_13275_가장긴팰린드롬부분문자열
//
//  Created by 김대교 on 2020/05/14.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    int answer=1;
    string s;
    cin>>s;
    int len = s.length();
    
    
    if(s.size()==0){
        cout<<0;
        return 0;
    }
    
     시간초과 코드임
     while(len>=2){
         for(int i=0;i<=s.length()-len;i++){
             bool flag=false;
             if(len%2!=0){
                 for(int j=0;j<len/2;j++){
                     if(s[i+j]!=s[i+(len/2*2)-j]){
                         flag = true;
                         break;
                     }
                 }
                 if(!flag){
                     cout<<len;
                     return len;
                 }
             }else{
                 for(int j=0;j<len/2;j++){
                     if(s[i+j]!=s[i+(len/2*2)-1-j]){
                         flag = true;
                         break;
                     }
                 }
                 if(!flag){
                     cout<<len;
                     return len;
                 }
             }
         }
         len-=1;
     }
     
     cout<<answer;
     return answer;
     */
    string s;
    cin>>s;
    int answer=1;
    int len = s.length();
    if(len==0) return 0;
    set<string> subSet;

    for(int i=2;i<=s.size();i++){
        int start=0;
        while(true){
            if(start+i==s.size()+1) break;
            string temp = s.substr(start,i);
            start++;
            subSet.insert(temp);
        }
    }
    
    for(auto i = subSet.begin();i!=subSet.end();i++){
        string original = *i;
        string cmp = *i;
        for(int i=0;i<cmp.size()/2;i++){
            swap(cmp[i],cmp[original.size()-i-1]);
        }
        
        if(original==cmp){
            if(cmp.size()==s.size()) {
                cout<<cmp.size();
                return cmp.size();
            }
            if(answer<cmp.size()) answer = cmp.size();
        }
    }
    cout<<answer;
    return answer;
}
