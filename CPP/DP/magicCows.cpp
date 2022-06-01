// https:open.kattis.com/problems/magicalcows
#include<bits/stdc++.h>

using namespace std;


int main(){
    int c=2;  //maximum no of cows allowed in a farm
    int n=5; //no of farms or no of cows with min 1 cow(every farm has 1 cow min)
    int m=3; //no of days the regulator with come for inspection;
    vector<int> inCows={1,2,1,2,1}; //no of cows on day 0 
    vector<int> days={0,3,4}; //days on which the regulator will come for inspection
    vector<vector<int>> dp(1000+1,vector<int>(c+1,0));
    for(int i=0;i<n;i++){
        dp[0][inCows[i]]+=1;
    }
    for(int i=0;i<1000;i++){
        for(int j=1;j<=c;j++){
            if(j<=c/2){
                dp[i+1][j*2]+=dp[i][j];
            }
            else{
                dp[i+1][j]+=2*dp[i][j];
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<=c;j++){
            cout<<dp[days[i]][j]<<" ";
        }
        cout<<"\n";
    }


}