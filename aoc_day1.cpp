#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input");
    int sum = 0;
    int max_cal = 0;
    int second_highest_cal = 0;
    int third_highest_cal = 0;

    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line.length() == 0){
                if (sum > max_cal){
                    third_highest_cal = second_highest_cal;
                    second_highest_cal = max_cal;
                    max_cal=sum;
                }

                if (sum < max_cal && sum > second_highest_cal){
                    third_highest_cal = second_highest_cal;
                    second_highest_cal = sum;
                }
                
                if (sum < max_cal && sum < second_highest_cal && sum > third_highest_cal){
                    third_highest_cal = sum;
                }

                sum = 0;
            }
            else sum += stoi(line);
        }
        
        myfile.close();
    }

    else {
        cout<<"unable to open file";
        return 0;
    }
    // check for the last elf
    if (sum > max_cal){
        third_highest_cal = second_highest_cal;
        second_highest_cal = max_cal;
        max_cal=sum;
    }

    if (sum < max_cal && sum > second_highest_cal){
        third_highest_cal = second_highest_cal;
        second_highest_cal = sum;
    }
                
    if (sum < max_cal && sum < second_highest_cal && sum > third_highest_cal){
        third_highest_cal = sum;
    }

    cout<< max_cal + second_highest_cal + third_highest_cal;
    return 0;

}