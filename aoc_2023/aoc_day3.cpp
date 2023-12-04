#include<bits/stdc++.h>
using namespace std;


typedef struct pn_gear_coordinates{
    int pn;
    int gear_row;
    int gear_col;
}pn_gear;

bool store_part_num_and_adjacent_gear_coordinates(int row, int col_start,int col_end, vector<string>& input, pn_gear &p){
    //top left corner
    if(row==0 && col_start ==0){
        if(input[0][col_end+1] == '*'){
            p.gear_row = 0;
            p.gear_col = col_end+1;
            return true;
        }
        for(int i=0;i<=col_end+1;i++){
            if(input[1][i] == '*'){
                p.gear_row =1;
                p.gear_col =i;
                return true;
            }
        }
        return false;
    }

    //top right corner
    else if(row==0 && col_end == input[0].length()-1){
        if(input[0][col_start-1] == '*'){
            p.gear_row =0;
            p.gear_col =col_start-1;
            return true;
        }
        for(int i= col_start-1;i <= col_end;i++){
            if(input[1][i] == '*'){
                p.gear_row =1;
                p.gear_col =i;
                return true;
            }
        }
        return false;
    }
    //bottom left
    else if(row==input.size()-1 && col_start==0){
        if(input[row][col_end+1] == '*'){
            p.gear_row =row;
            p.gear_col = col_end+1;
            return true;
        }
        for(int i=0;i<=col_end+1;i++){
            if(input[row-1][i] == '*'){
                p.gear_row=row-1;
                p.gear_col=i;
                return true;     
            }
        }
        return false;
    }
    
    //bottom right
    else if(row==input.size()-1 && col_end==input[row].length()-1){
        if(input[row][col_start-1] == '*'){
            p.gear_row=row;
            p.gear_col=col_start-1;
            return true;
        }
        for(int i=col_start-1;i<=col_end;i++){
            if(input[row-1][i] == '*'){
                p.gear_row=row-1;
                p.gear_col=i;
                return true;     
            }
        }
        return false;
    }

    //top row
    else if (row == 0 && col_start !=0 && col_end != input[0].length()-1){
        if(input[0][col_start-1] == '*' || input[0][col_end+1] == '*'){
            p.gear_row=0;
            if(input[0][col_start-1]=='*')
                p.gear_col=col_start-1;
            else p.gear_col=col_end+1;

            return true;
        }
        for(int i=col_start-1;i<=col_end+1;i++){
            if(input[1][i] == '*'){
                p.gear_row=1;
                p.gear_col=i;
                return true;
            }
        }
        return false;
    }

    //bottom row
    else if (row == input.size()-1 && col_start !=0 && col_end != input[0].length()-1){
        if(input[row][col_start-1] == '*' || input[row][col_end+1] == '*'){
            p.gear_row=row;
            if(input[row][col_start-1]=='*')
                p.gear_col=col_start-1;
            else p.gear_col=col_end+1; 
            return true;
        }
        for(int i=col_start-1; i<=col_end+1;i++){
            if(input[row-1][i] == '*'){
                p.gear_row=row-1;
                p.gear_col=i;
                return true;
            }
        }
        return false;
    }    
    
    //left edge
    else if (row != input.size()-1 && row != 0 && col_start == 0 ){
        if(input[row][col_end+1] == '*'){
            p.gear_row=row;
            p.gear_col=col_end+1;
            return true;
        }
        for(int i=0; i<=col_end+1;i++){
            if(input[row-1][i] == '*' || input[row+1][i] == '*'){
                if(input[row-1][i]=='*')
                    p.gear_row=row-1;
                else p.gear_row=row+1;
                p.gear_col=i;
                return true;
            }
        }
        return false;
    }    
    
    //right_edge
    else if (row != input.size()-1 && row != 0 && col_end == input[0].length()-1){
        if(input[row][col_start-1] == '*'){
            p.gear_row=row;
            p.gear_col=col_start-1;
            return true;
        }
        for(int i=col_start-1; i<=col_end;i++){
            if(input[row-1][i] == '*' || input[row+1][i] == '*'){
                if(input[row-1][i]=='*')
                    p.gear_row=row-1;
                else p.gear_row=row+1;
                p.gear_col=i;
                return true;
            }
        }
        return false;
    }    

    
    //any other case
    if(input[row][col_start-1] == '*' || input[row][col_end+1] == '*'){
        if(input[row][col_start-1]=='*')
            p.gear_col=col_start-1;
        else p.gear_col=col_end+1;
        p.gear_row=row;
        return true;
    }
    for(int i=col_start-1;i<=col_end+1;i++){
        if(input[row-1][i] == '*' || input[row+1][i] == '*'){
            if(input[row-1][i]=='*')
                p.gear_row=row-1;
            else p.gear_row=row+1;
            p.gear_col=i;
            return true;
        }
    }
    return false;
}

bool is_part_number(int row, int col_start,int col_end, vector<string>& input){
    //top left corner
    if(row==0 && col_start ==0){
        if(input[0][col_end+1] != '.')
            return true;
        for(int i=0;i<=col_end+1;i++){
            if(input[1][i] != '.')
                return true;
        }
        return false;
    }

    //top right corner
    else if(row==0 && col_end == input[0].length()-1){
        if(input[0][col_start-1] != '.')
            return true;
        for(int i= col_start-1;i <= col_end;i++){
            if(input[1][i] != '.')
                return true;
        }
        return false;
    }
    //bottom left
    else if(row==input.size()-1 && col_start==0){
        if(input[row][col_end+1] != '.')
            return true;
        for(int i=0;i<=col_end+1;i++){
            if(input[row-1][i] != '.')
                return true;     
        }
        return false;
    }
    
    //bottom right
    else if(row==input.size()-1 && col_end==input[row].length()-1){
        if(input[row][col_start-1] != '.')
            return true;
        for(int i=col_start-1;i<=col_end;i++){
            if(input[row-1][i] != '.')
                return true;     
        }
        return false;
    }

    //top row
    else if (row == 0 && col_start !=0 && col_end != input[0].length()-1){
        if(input[0][col_start-1] != '.' || input[0][col_end+1] != '.')
            return true;
        for(int i=col_start-1;i<=col_end+1;i++){
            if(input[1][i] != '.')
                return true;
        }
        return false;
    }

    //bottom row
    else if (row == input.size()-1 && col_start !=0 && col_end != input[0].length()-1){
        if(input[row][col_start-1] != '.' || input[row][col_end+1] != '.')
            return true;
        for(int i=col_start-1; i<=col_end+1;i++){
            if(input[row-1][i] != '.')
                return true;
        }
        return false;
    }    
    
    //left edge
    else if (row != input.size()-1 && row != 0 && col_start == 0 ){
        if(input[row][col_end+1] != '.')
            return true;
        for(int i=0; i<=col_end+1;i++){
            if(input[row-1][i] != '.' || input[row+1][i] != '.')
                return true;
        }
        return false;
    }    
    
    //right_edge
    else if (row != input.size()-1 && row != 0 && col_end == input[0].length()-1){
        if(input[row][col_start-1] != '.')
            return true;
        for(int i=col_start-1; i<=col_end;i++){
            if(input[row-1][i] != '.' || input[row+1][i] != '.')
                return true;
        }
        return false;
    }    

    
    //any other case
    if(input[row][col_start-1] != '.' || input[row][col_end+1] != '.')
        return true;
    for(int i=col_start-1;i<=col_end+1;i++){
        if(input[row-1][i] != '.' || input[row+1][i] != '.')
            return true;
    }
    return false;
}

int main(){
    string line;
    int num,row=0,col_start=0,col_end=0,sum=0,i=0,sum_gear_ratios=0;
    vector<string>input;
    vector<pn_gear> part_num_and_associated_gear_list; 
    unordered_set<int> visited_indices;
    ifstream myfile ("input_aoc3");

    if (myfile.is_open()){
        while (getline(myfile,line)){
            input.push_back(line);
        }
        myfile.close();
    }
    else{
        cout<<"unable to open file";
    }

    for(auto it:input){
        i=0;
        while(i < it.length()){
            int pos;
            string s="";
            if(isdigit(it[i])){
                col_start=i;
                while(isdigit(it[i])){
                    s+=it[i];
                    i++;
                }
                col_end=i-1;
                num=stoi(s);
                // bool is_part_num = is_part_number(row,col_start,col_end,input);
                // if(is_part_num){
                //     sum+=num;
                // }
                pn_gear p;
                if(store_part_num_and_adjacent_gear_coordinates(row,col_start,col_end,input,p)){
                    p.pn = num;
                    part_num_and_associated_gear_list.push_back(p);
                } 
            }
            i++;
        }
        row++;
    }

    //cout<<sum;

    for(int i=0;i<part_num_and_associated_gear_list.size();i++){
        int j=i+1;
        while(j<part_num_and_associated_gear_list.size()){
            if(part_num_and_associated_gear_list[i].gear_row==part_num_and_associated_gear_list[j].gear_row && part_num_and_associated_gear_list[i].gear_col == part_num_and_associated_gear_list[j].gear_col && visited_indices.find(i)==visited_indices.end() && visited_indices.find(j)== visited_indices.end()){
                sum_gear_ratios+=part_num_and_associated_gear_list[i].pn * part_num_and_associated_gear_list[j].pn;
                visited_indices.insert(i);
                visited_indices.insert(j); 
                break;
            }
            j++;
        }
    }
    cout<<sum_gear_ratios;
    return 0;
}
