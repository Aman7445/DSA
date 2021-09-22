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
int main(){
    int n=4;
    int val[n]={1,3,4,5};
    int wt[n]={1,4,5,7};
    int W=7;
    int ans=knapsack(val,wt,W,n);
    cout<<ans;
    // for(int i=0;i<p.size();i++){
    //     for(int j=0;j<p[i].size();j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}