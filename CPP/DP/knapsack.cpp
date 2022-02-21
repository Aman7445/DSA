#include<bits/stdc++.h>
using namespace std;

//Memoization Technique
vector<vector<int>> knp(10,vector<int>(15,-1)); 
vector<vector<int>> dp(5,vector<int>(8)); 
int knapsack(int val[],int wt[],int we,int n){
    if(n==0){
        return 0;
    }
    if(knp[n][we]!=-1){
        return knp[n][we];
    }
    if(wt[n-1]<=we){
        return knp[n][we]=max(val[n-1]+knapsack(val,wt,we-wt[n-1],n-1),knapsack(val,wt,we,n-1));

    }
    else{
        return knp[n][we]=knapsack(val,wt,we,n-1);
    }
    return knp[n][we];
}

//tabulation
int tknapsack(int val[],int wt[],int we,int n){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<we+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=we){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][we];
}

int main(){
    int n=4;
    int val[n]={1,3,4,5};
    int wt[n]={1,4,5,7};
    int we=7;
    
    int ans=knapsack(val,wt,we,n);
    int ans2=tknapsack(val,wt,we,n);
    cout<<ans<<"\n";
    cout<<ans2;
    // for(int i=0;i<p.size();i++){
    //     for(int j=0;j<p[i].size();j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}