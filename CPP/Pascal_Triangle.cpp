#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=5;//size of the triangle
    int pt[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||i==j){
                pt[i][j]=1;
            }
            else{
                pt[i][j]=pt[i-1][j]+pt[i-1][j-1];
            }
            cout<<pt[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}