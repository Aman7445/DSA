#include<bits/stdc++.h>

using namespace std;

//Reursive approach
int binExpRec(int a,int b){
    if(b==0){
        return 1;
    }
    int res=binExpRec(a,b/2);
    if(b%2==0){
        return res*res;
    }
    else{
        return a*res*res;
    }
}

int main(){
    int a=3;
    int b=7;
    int ans=binExpRec(a,b);
    cout<<ans<<"\n";
    cout<<pow(a,b);
    return 0;
}