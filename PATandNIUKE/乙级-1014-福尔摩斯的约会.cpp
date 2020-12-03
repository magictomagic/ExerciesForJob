#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<sstream>
using namespace std;
int main(){
    unordered_map<char, string> week = {
        {'A', "MON "},{'B', "TUE "},{'C', "WED "},{'D', "THU "},{'E', "FRI "},{'F', "SAT "},{'G', "SUN "}
    };
    unordered_map<char, int> hour;
    for(int i = 0; i < 10; i++){
        hour['0' + i] = i;
    }
    for(int i = 0; 10 + i < 24; i++){
        hour['A' + i] = 10 + i;
    }
    string l1,l2,l3,l4;
    cin>>l1>>l2>>l3>>l4;
    int zone = 0;
    for(int i = 0; i < min(l1.size(), l2.size()); i++){
      // cout<<l1[i]<<" "<<l2[i]<<endl;
        if(l1[i] >= 'A' && l2[i] <= 'G' && l1[i] == l2[i] && zone == 0){
            cout<<week[l1[i]];
            zone++;
            continue; ////////////////////////////
        }
        if(zone == 1 && l1[i] == l2[i] && (isdigit(l1[i]) || (l1[i] >= 'A' && l1[i] <= 'N'))){
            printf("%02d:", hour[l1[i]]);
            zone++;
            break;//////////////////////////
        }
    }
    for(int i = 0; i < min(l3.size(), l4.size()); i++){
        if(isalpha(l3[i]) && l3[i] == l4[i]) {
            printf("%02d", i);
            break; ////////////////
        }
    }
    return 0;
}
