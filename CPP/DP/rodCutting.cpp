//Ques-Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
//Link-https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include<bits/stdc++.h>

using namespace std;

//memoization
int rodCutting(vector<int> len,vector<int> price,int L,vector<vector<int>> t,int n){
    if(n<=0) return 0;

    if(t[n][L]!=-1) return t[n][L];

    if(len[n-1]<=L){
        t[n][L]=max(price[n-1]+rodCutting(len,price,L-len[n-1],t,n),rodCutting(len,price,L,t,n-1));
    }
    else{
        t[n][L]=rodCutting(len,price,L,t,n-1);
    }
    return t[n][L];
}

//tabulation
int rodCuttingTab(vector<int> len,vector<int> price,int L,int n){
    vector<vector<int>> dp(n+1,vector<int>(L+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<L+1;j++){
            if(i==0||j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<L+1;j++){
            if(len[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][L];
}
int main(){
    int n=8;
    vector<int> len={1,2,3,4,5,6,7,8};
    vector<int> price={1,5,8,9,10,17,17,20};
    int L=8;
    vector<vector<int>> t(n+1,vector<int>(L+1,-1));    
    int ans=rodCutting(len,price,L,t,n);
    cout<<ans<<"\n";
    cout<<rodCuttingTab(len,price,L,n);
    return 0;
}