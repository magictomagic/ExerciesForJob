#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int len, hs;
    cin>>len>>hs;
    hs = hs % len;
    int a[len];
    for(int i = hs; i < len; i++){
        cin>>a[i];
    }
    for(int i = 0; i < hs; i++){
        cin>>a[i];
    }
    for(int i = 0; i < len; i++){
        cout<<a[i];
        if(i != len - 1){
            cout<<" ";
        }
    }
    return 0;
}
