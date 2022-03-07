#include<bits/stdc++.h>

using namespace std;

//Next Smallest to Right
void NSR(vector<int>& heights,vector<int>& right,int n){
    stack<int> st1;
    for(int i=n-1;i>=0;i--){
        while(!st1.empty() && heights[i]<=heights[st1.top()]){
            st1.pop();
        }
        if(!st1.empty()){
            right[i]=st1.top();
        }
        st1.push(i);
    }
}

int main(){
    int n=5;
    vector<int> heights={2,1,5,6,2,3};
    vector<int> right(n,n);
    NSL(heights,left,n);
    for(int i=0;i<n;i++){
        cout<<right[i];
    }
}