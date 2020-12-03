#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    vector<int> v(1000, 0);
    int i = 0, input;
    while(cin>>input){
        v[i++] = input;
    }
    i = 0;
    vector<int> result;
    while(v[i] != 0 && v[i + 1] != 0){
        result.push_back(v[i]*v[i+1]);
        result.push_back(v[i+1]-1);
        i = i + 2;
    }
    if(result.size() < 2){
        cout<<"0 0";
    }else{
        for(int i = 0; i < result.size(); i++){
            cout<<result[i];
            if(i != result.size() - 1){
                cout<<" ";
            }else{
                ;
            }
        }
    }
    return 0;
}
