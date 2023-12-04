#include<bits/stdc++.h>
using namespace std;


typedef struct pn_gear_coordinates{
    int pn;
    int gear_row;
    int gear_col;
}pn_gear;

bool part2(int row, int col_start,int col_end, vector<string>& input, pn_gear &p){
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
    vector<string>input;
    int num,row=0,col_start=0,col_end=0,sum=0,i=0;
    vector<pn_gear> pg; 
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
        //cout<<it<<endl;
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
                //cout<<s<<endl;
                col_end=i-1;
                num=stoi(s);
                //cout<<"row:"<<row<<" col_start:"<<col_start<<" col_end:"<<col_end;
                // bool is_part_num = is_part_number(row,col_start,col_end,input);
                // if(is_part_num){
                //     cout<<num<<endl;
                //     sum+=num;
                // }
                pn_gear p;
                if(part2(row,col_start,col_end,input,p)){
                    p.pn = num;
                    pg.push_back(p);
                    cout<<num<<endl;
                } 

            }
            i++;
        }
        row++;
    }
    //cout<<sum;
    int sum_part2=0;
    unordered_set<int>v;
    for(int i=0;i<pg.size();i++){
        int j=i+1;
        while(j<pg.size()){
            if(pg[i].gear_row==pg[j].gear_row && pg[i].gear_col == pg[j].gear_col && v.find(i)==v.end() && v.find(j)== v.end()){
                sum_part2+=pg[i].pn * pg[j].pn;
                v.insert(i);
                v.insert(j); 
                break;
            }
            j++;
        }
    }
    cout<<sum_part2;
    return 0;
}
