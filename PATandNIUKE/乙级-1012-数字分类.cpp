#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int main(){
    int num, i = 0, a1 = 0, a2 = 0, a3 = 0, a5 = 0, flag = 1, n4 = 0;
    float a4 = 0;
    cin>>num;
    bool f2 = false;
    while(i < num){
        int cur;
        cin>>cur;
        switch(cur%5){
            case 0: a1 = ((cur%2 == 0) ? (a1 + cur) : a1);
                break;
            case 1: a2 = a2 + cur * flag; flag = flag * (-1); f2 = true;
                break;
            case 2: a3++;
                break;
            case 3: a4 += cur; n4++;// avg
                break;
            case 4: a5 = max(a5, cur);
                break;
            default: cout<<"impossible!!!";
        }
        i++;
    }
    if(a1 == 0){
        cout<<"N ";
    }else{
        cout<<a1<<" ";
    }
    if(!f2){
        cout<<"N ";
    }else{
        cout<<a2<<" ";
    }
    if(a3 == 0){
        cout<<"N ";
    }else{
        cout<<a3<<" ";
    }
    if((int)a4 == 0){
        cout<<"N ";
    }else{
        printf("%.1f ", a4/n4);
    }
    if(a5 == 0){
        cout<<"N";
    }else{
        cout<<a5;
    }
    return 0;
}
