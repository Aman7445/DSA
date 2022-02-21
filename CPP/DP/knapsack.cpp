#include<bits/stdc++.h>
using namespace std;

//Memoization Technique
vector<vector<int>> knp(10,vector<int>(15,-1)); 

int knapsack(int val[],int wt[],int W,int n){
    if(n==0){
        return 0;
    }
    if(knp[n][W]!=-1){
        return knp[n][W];
    }
    if(wt[n-1]<=W){
        return knp[n][W]=max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));

    }
    else{
        return knp[n][W]=knapsack(val,wt,W,n-1);
    }
}
int tknapsack(int val[],int wt[],int W,int n,vector<vector<int>> t){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][W];
}
int main(){
    int n=4,W=7;
    int val[n]={1,3,4,5};
    int wt[n]={1,4,5,7};
    // int t[n+2][W+2];
    vector<vector<int>> t(n+1,vector<int>(W+1));
    int ans=knapsack(val,wt,W,n);
    int ans2=tknapsack(val,wt,W,n,t);
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