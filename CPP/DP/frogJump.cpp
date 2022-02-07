//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include<bits/stdc++.h>
using namespace std;
//memoization
int frogJump(int n,vector<int> nums,vector<int> t){
    if(n<=0) return 0;
    else{
        int ostep=abs(nums[n]-nums[n-1])+frogJump(n-1,nums,t);
        int tstep=abs(nums[n]-nums[n-2])+frogJump(n-2,nums,t);
        t[n]=min(ostep,tstep);
    }
    return t[n];
}

int main(){
    int n=4;
    vector<int> nums={10,20,30,10};
    vector<int> t(n+1);
    cout<<frogJump(n-1,nums,t);
    return 0;
}