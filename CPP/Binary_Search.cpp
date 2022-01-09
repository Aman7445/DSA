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

int order_agnostic_bs(vector<int> arr,int target){
    int start=0,end=arr.size()-1;
    int mid;
    bool isAsc=arr[start]<arr[end];
    while(start<=end){
        mid=start+(end-start/2);
        if(arr[mid]==target) return mid;
        if(isAsc){
            if(target>arr[mid]) start=mid+1;
            else end=mid-1;
        }
        else{
            if(target>arr[mid]) end=mid-1;
            else start=mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={98,90,78,65,55,43,23};
    int target=90;
    cout<<order_agnostic_bs(arr,target);
    return 0;
}