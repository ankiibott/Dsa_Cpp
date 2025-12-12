#include<iostream>|
using namespace std;

int main(){
    vector<int> vec(4);
    cout<<vec.size();<<endl;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    cout<<vec.capacity();<<endl;

    for(i=0;i<4;i++){
        cout<<vec[i]<<endl;
    }
    vec.pop_back();
    for(i=0;i<4;i++){
        cout<<vec[i]<<endl;
    }
    cout<<vec[2]<<endl;
    
    return 0;
}