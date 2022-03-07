#include<bits/stdc++.h>

using namespace std;
//Next Smallest to left
void NSL(vector<int> heights,vector<int> left,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            left[i]=st.top();
        }
        st.push(i);
    }
}
int main(){
    int n=5;
    vector<int> heights={2,1,5,6,2,3};
    vector<int> left(n,-1);
    NSL(heights,left,n);
    for(int i=0;i<n;i++){
        cout<<left[i];
    }
}
