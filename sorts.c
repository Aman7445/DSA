#include<stdio.h>

int swap(int *a,int *b){
    int *temp=*a;
    *a=*b;
    *b=*temp;
}
int bubble(int arr[],int n){
    int a,b;
    for(a=0;a<n-1;a++){
        for(b=0;b<n-a-1;b++){
            if(arr[b]>arr[b+1]){
                swap(&arr[b],&arr[b+1]);
            }
        }
    }
    
}

int main(){
    int n;
    int arr[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    return 0;
}