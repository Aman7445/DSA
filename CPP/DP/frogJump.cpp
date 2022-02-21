//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include<bits/stdc++.h>
using namespace std;
//memoization not AC
int frogJump(int n,vector<int> nums,vector<int> t){
    if(n<=0) return 0;
    else{
        int ostep=abs(nums[n]-nums[n-1])+frogJump(n-1,nums,t);
        int tstep=abs(nums[n]-nums[n-2])+frogJump(n-2,nums,t);
        t[n]=min(ostep,tstep);
    }
    return t[n];
}
//tabulation
int frogJumptab(int n,vector<int> nums,vector<int> dp){
    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(nums[1]-nums[0]);
    for(int i=3;i<=n+1;i++){
        int ostep=dp[i-1]+abs(nums[(i-1)-1] - nums[i-1]);
        int tstep=dp[i-2]+abs(nums[(i-2)-1] - nums[i-1]);
        dp[i]=min(ostep,tstep);
    }
    return dp[n];
}

int main(){
    int n=4;
    vector<int> nums={10,20,30,10};
    vector<int> t(n+1);
    vector<int> dp(n+1);
    cout<<frogJump(n-1,nums,t)<<"\n";
    cout<<frogJumptab(n-1,nums,dp);
    return 0;
}