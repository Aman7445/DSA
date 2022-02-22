#include<bits/stdc++.h>

using namespace std;

//subset sum 
int subsetSum(int n,vector<int> arr,int sum,vector<vector<bool>> subsum,vector<int> valsum){
    //creating the tabulation matrix
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
    //storing the valid subset sum in the range [0,tsum] 
    for(int j=0;j<sum/2+1;j++){
        if(subsum[n][j]==1){
            valsum.push_back(j);
        }
    }
    //calculating the minimum subset sum (S2-S1=mini , S2=tsum-S1)
    int mini=INT_MAX;
    for(int i=0;i<valsum.size();i++){
        int secsum=sum-(2*valsum[i]);
        mini=min(secsum,mini);
    }
    return mini;
    
}
int MinSubsetSumDiff(vector<int> arr,int tsum,vector<vector<bool>> subsum){
    vector<int> valsum;
    int n=arr.size();
    return subsetSum(n,arr,tsum,subsum,valsum);
}

int main(){
    vector<int> arr={1,2,7};
    int tsum=0;
    for(int i=0;i<arr.size();i++){
        tsum+=arr[i];
    }
    cout<<"total sum: "<<tsum<<"\n";
    vector<vector<bool>> subsum(arr.size()+1,vector<bool>(tsum+1));
    int res=MinSubsetSumDiff(arr,tsum,subsum);
    cout<<"Minimum Subset Sum Difference will be: "<<res;
    return 0;
}