#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>path{2,3,3};
    
    vector<int>a{0,0,0,0,0,0,0,0,0,0};
    for (auto v : path)
    if(a[v] == 0) a[v] = v;
    else a[v] = a[v] ^ v;
    int counts = 0;
    for (auto v : a){
        if(v != 0) counts++;
        std::cout << "a: " << v << "\t";
    }
    std::cout << "\n" << "count: "<<counts;
    return 0;
}