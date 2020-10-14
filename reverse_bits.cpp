#include<bits/stdc++.h>
using namespace std;

//good usage of bitset
//reverse the bits of given 32 bits unsigned integer

uint32_t reverse_bits(uint32_t n){
    bitset<32>a(n);
    for(int i=0;i<16;i++){
        bool temp=a[i];
        a[i]=a[31-i];
        a[31-i]=temp;
    }
    return (uint32_t) a.to_ulong();
}

int main(){
    uint32_t n;
    cin>>n;
    cout<<reverse_bits(n);
    return 0;
}