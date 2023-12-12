#include "cpp_utilities.h"

std::vector<int> split_at_space(std::string input_string){
    std::vector<int> nums;
    bool negative=false;
    int i=0;
    while(i<input_string.length()){
        std::string s="";
        while(std::isdigit(input_string[i])){
            s+=input_string[i];
            i++;
        }
        if(s!=""){
            if(negative){
                nums.push_back(stoi("-"+s));
                negative=false;
            }
            else
                nums.push_back(stoi(s));
        }
        if(input_string[i]=='-')
            negative=true;

        i++;
    }
    return nums;
}

bool are_all_numbers_zero(std::vector<int> nums){
    for(int i=0;i<nums.size()-1;i++)
        if(nums[i] != nums[i+1] || nums[i]!=0)
            return false;
    return true;
}

std::vector<int> difference_vector(std::vector<int> nums){
    std::vector<int> vector_of_differences;
    for(int i=0;i<nums.size()-1;i++){
        vector_of_differences.push_back(nums[i+1]-nums[i]);
    }
    return vector_of_differences;
}

int main(){
    std::string line;
    std::ifstream myfile ("input_aoc9");
    std::stack<int> last_num; 
    int final_sum=0;
    if (myfile.is_open()){
        while (getline(myfile,line)){
            std::vector<int> nums=split_at_space(line);
            // for(auto it: nums)
            //     std::cout<<it<<"  "<<std::endl;
            int num_of_seq=0,sum=0;
            //std::cout<<are_all_numbers_zero(nums)<<std::endl; 
            while(!(are_all_numbers_zero(nums))){
                last_num.push(nums[nums.size()-1]);
                num_of_seq++; 
                nums=difference_vector(nums);
            }
            //std::cout<< num_of_seq<<std::endl; 
            while(last_num.size() != 0){
                sum+=last_num.top();   
                last_num.pop();
            }
            //std::cout<<sum<<std::endl;
            final_sum+=sum;

        }
        myfile.close();
    }
    else{
        std::cout<<"unable to open file";
    }

    std::cout<<final_sum;
    return 0;
}