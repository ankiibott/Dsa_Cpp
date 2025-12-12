#include<iostream>|
using namespace std;

int main(){
    vector<int> vec(4);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for(i=0;i<4;i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}