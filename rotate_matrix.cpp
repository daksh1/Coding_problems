#include<bits/stdc++.h>
using namespace std;



/* 
rotate a matrix by 90 degrees

123                         147                                                 741 
456     after transpose     258     after swapping about the middle column      852
789                         369                                                 963                 


*/

void rotate_matrix(int ** matrix,int n){
    //calcuate transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //now swap about the middle column

    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++)
            swap(matrix[i][j],matrix[i][n-1-j]);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int **matrix=new int *[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    rotate_matrix(matrix,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}