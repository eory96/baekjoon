//
//  main.cpp
//  baekjoon1541_lost()
//
//  Created by 김대교 on 2020/02/08.
//  Copyright © 2020 김대교. All rights reserved.
//
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    string input;
    string temp="";
    bool judge=false;
    int result=0;
    cin>>input;
    
    for(int i=0; i<=input.size();i++){
        if(input[i]=='+'||input[i]=='-'||input[i]=='\0'){
            if(input[i]=='-')
                judge=true;
            
            if(judge)
                result -= stoi(temp);
            else
                result += stoi(temp);
            temp="";
            
            
            continue;
        }
        temp+=input[i];
        cout<<"temp : "<<temp<<endl;
    }
    


    cout<<result<<endl;
    return 0;
}
