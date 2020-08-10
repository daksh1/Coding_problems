#include<iostream>
using namespace std;


bool is_this_position_valid(int x,int y,int **board,int num){
    
    //row check
    for(int i=0;i<num;i++){
        if(board[x][i]==1)
            return false;
    }
    
    //column check
    for(int i=0;i<num;i++){
        if(board[i][y]==1)
            return false;
    }
    
    for(int i=x+1,j=y+1;i<num && j<num;i++,j++){
        if(board[i][j]==1)
            return false;
    }
    for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
            return false;
    }

    for(int i=x-1,j=y+1;i>=0 && j<num;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    for(int i=x+1,j=y-1;i<num && j>=0;i++,j--){
        if(board[i][j]==1)
            return false;
    }

return true;
}



bool N_queens(int **board,int num, int queens){
    if(queens==0)
        return true;
    else {
        for(int x=0;x<num;x++){
            for(int y=0;y<num;y++){
                if(is_this_position_valid(x,y,board,num))
                    board[x][y]=1;
                else continue;
                if(N_queens(board,num,queens-1))
                    return true;
                
                board[x][y]=0;
            }
        }
    }
    return false;
}

int main() {
    int num;
	cin >>num;								
    int **board= new int *[num];
    for(int i=0;i<num;i++){
        board[i]=new int[num];
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            board[i][j]=0;
    }

    bool check=N_queens(board,num,num);

    if(check){
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++)
                cout<<board[i][j];
        cout<<endl;
        }
    }
    else return -1;
    return 0;
}