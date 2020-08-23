//
//  main.cpp
//  baekjoon_1120_문자열
//
//  Created by 김대교 on 2020/03/11.
//  Copyright © 2020 김대교. All rights reserved.
//

#include <iostream>

using namespace  std;

string A,B;
int lengthA,lengthB;
int dif=90000;

int main(){
    cin>>A>>B;
    
    for(int i=0;i<=B.length()-A.length();i++){
        int count=0;
        for(int j=0;j<A.length();j++){
            if(A.at(j)!=B.at(i+j)) count++;
        }
        dif = min(dif,count);
    }
    
    cout<<dif;
    return  0;
}

//int countDif(string a, string b, int judeg){
//    int counting=0;
//    int index=0;
//    if(judeg==1){
//        for(int i=0;i<(int)a.length();i++){
//            if(a.at(i)!=b.at(i)){
//                counting++;
//            }
//        }
//    }else{
//        for(int i=(int)a.length()-1;i>=0;i--){
//            index+=1;
//            if(a.at(i)!=b.at(b.length()-index)){
//                counting++;
//            }
//        }
//    }
//
//    return counting;
//}
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    cin>>A>>B;
//    lengthA = (int)A.length();
//    lengthB = (int)B.length();
//
//    dif = lengthB-lengthB;
//
//    if(lengthA==lengthB){
//        dif = countDif(A, B,1);
//    }else{
//        while((int)A.length()<lengthB){
//            string temp1,temp2;
//            int countFront,countBack;
//
//            temp1 =B[0]+A;
//            temp2 =A+B[lengthB-1];
//
//
//
//            countFront = countDif(temp1, B,1);
//            countBack = countDif(temp2, B,2);
//
//            if(countFront>countBack){
//                A = temp2;
//                dif = countBack;
//            }else{
//                A = temp1;
//                dif=countFront;
//            }
//
//        cout<<A<<endl;
//
//        }
//
//    }
//
//
//    cout<<dif<<endl;
//
//    return 0;
//}
