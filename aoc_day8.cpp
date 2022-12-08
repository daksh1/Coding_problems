#include<bits/stdc++.h>
using namespace std;


int scenic_score_at_given_index(int i, int j, vector<string> &v){
    
    int scenic_score_left=0;
    int scenic_score_right=0;
    int scenic_score_up=0;
    int scenic_score_down=0;

    //view to left
    for(int col=j-1;col>=0;col--){
        if(v[i][col]<v[i][j])
            scenic_score_left++;
        else{
            scenic_score_left++;
            break;
        }
    }
    //cout<< "left_score"<<" "<<scenic_score_left<<endl;

    //view to right
    for(int col=j+1;col<=v[0].length();col++){
        if(v[i][col]<v[i][j])
            scenic_score_right++;
        else{
            scenic_score_right++;
            break;
        }
    }

    //cout<< "right_score"<<" "<<scenic_score_right<<endl;

    //view down  
    for(int row=i+1;row<v.size();row++){
        if(v[row][j]<v[i][j])
            scenic_score_down++;
        else{
            scenic_score_down++;
            break;
        }
  
    }

    //cout<< "down_score"<<" "<<scenic_score_down<<endl;

    //view up
    for(int row=i-1;row>=0;row--){
        if(v[row][j]<v[i][j])
            scenic_score_up++;
        else{
            scenic_score_up++;
            break;
        }
    }

    //cout<< "up_score"<<" "<<scenic_score_up<<endl;

    return scenic_score_left*scenic_score_right*scenic_score_down*scenic_score_up;

}

int main(){
    string line;
    ifstream myfile ("input_aoc8");
    vector<string>v;
    unordered_set<string>visible_index;
    char temp;
    int scenic_score=-1;

    if (myfile.is_open()){
        while(getline(myfile,line)){
            v.push_back(line);
        }
        myfile.close();     
    }
    else 
        cout<<"unable to open file";

    for(int col=1;col<v[0].length()-1;col++){
        temp=v[0][col];
        for(int row=1;row < v.size()-1;row++){
           if(v[row][col]>temp){
                visible_index.insert(to_string(row)+","+to_string(col));
                temp=v[row][col];
           }
        }           
    }

    //bottom_to_top
    for(int col=1;col<v[0].length()-1;col++){
        temp=v[v.size()-1][col];
        for(int row=v.size()-2;row > 0;row--){
           if(v[row][col]>temp){
                visible_index.insert(to_string(row)+","+to_string(col));
                temp=v[row][col];
           }
        }           
    }
 
    //left_to_right

    for(int row=1;row<v.size()-1;row++){
        temp=v[row][0];
        for(int col=1;col<v[0].length()-1;col++){
            if(v[row][col]>temp){
                visible_index.insert(to_string(row)+","+to_string(col));
                temp=v[row][col];
            }
        }
    }

    //right_to_left
    for(int row=1;row<v.size()-1;row++){
        temp=v[row][v[0].length()-1];
        for(int col=v[0].length()-2;col>0;col--){
            if(v[row][col]>temp){
                visible_index.insert(to_string(row)+","+to_string(col));
                temp=v[row][col];
            }
        }
    }

    // cout<< visible_index.size() + 2*(v[0].length() + v.size()-2)<<endl;

    for(int i=1;i<v.size()-1;i++){
        for(int j=1;j<v[0].length()-1;j++)
            scenic_score=max(scenic_score,scenic_score_at_given_index(i,j,v));
    }

    // int scenic_score= scenic_score_at_given_index(3,2,v);
    cout<<scenic_score;

    return 0;
        
}