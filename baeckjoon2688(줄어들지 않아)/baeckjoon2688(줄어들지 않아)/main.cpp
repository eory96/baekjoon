#include <iostream>
using namespace std;

int T;
int n[10][65];

int counting(int i,int digit){
    if(digit==1) return 1;
    
    int* ret = n[i][digit];
    if(ret!=-1)
        
}

int main(int argc, const char * argv[]) {
    // insert code here...
    memset(n, -1, sizeof(n));
    cin>>T;
    int cnt,n;
    
    for(int a=1;a<=T;a++){
        cin>>n;
        cnt=0;
        for(int i=0;i<n;i++){
            cnt+=counting(i,n);
        }
        cout<<cnt<<endl;
    }

    
    return 0;
}
