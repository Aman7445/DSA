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
    return knp[n][W];
}

//tabulation
int tknapsack(int val[],int wt[],int W,int n,vector<vector<int>> t){
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
            if(wt[i-1]<=W){
                t[i][j]=max(val[i-1]+t[i-1][j-1],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){
    int n=4;
    int val[n]={1,3,4,5};
    int wt[n]={1,4,5,7};
    int W=7;
    vector<vector<int>> t;
    int ans=knapsack(val,wt,W,n);
    // int ans2=tknapsack(val,wt,W,n,t);
    cout<<ans<<"\n";
    // cout<<ans2;
    // for(int i=0;i<p.size();i++){
    //     for(int j=0;j<p[i].size();j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}