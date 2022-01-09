#include<bits/stdc++.h>

using namespace std;

int bs(vector<int> arr,int target){
    int start=0,end=arr.size()-1;
    int mid;
    while(start<=end){
        int mid=start+(end-start/2);
        if(target==arr[mid]) return mid;
        else if(target>arr[mid]) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr={2,30,35,55,90,98};
    int target=90;
    cout<<bs(arr,target);
    return 0;
}