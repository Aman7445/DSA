#include<bits/stdc++.h>

using namespace std;

//tabulation
bool subsetSum(int n,vector<int> arr,int sum,vector<vector<bool>> subsum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0) subsum[i][j]=1;
            if(i==0 && j!=0) subsum[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                subsum[i][j]=(subsum[i-1][j-arr[i-1]]||subsum[i-1][j]);
            }
            else{
                subsum[i][j]=subsum[i-1][j];
            }
        }
    }
    return subsum[n][sum];
}

int main(){
    int n=3;
    vector<int> arr={1,2,7};
    int sum=10;
    vector<vector<bool>> subsum(n+1,vector<bool>(sum+1));
    bool ans=subsetSum(n,arr,sum,subsum);
    cout<<ans;
    return 0;
}