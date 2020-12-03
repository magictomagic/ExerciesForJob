#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int main(){
    int start, end, num=0, i=2, line = 0;
    cin>>start>>end;
    while(true){
        bool prime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i%j == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            num++;
        }
        if(num >= start && prime){
            line++;
            if(num < end){
                if(line % 10 == 0){
                    cout<<i<<endl;
                }else{
                    cout<<i<<" ";
                }
            }else if(num == end){
                cout<<i;
                break;
            }else{
                break;
            }
        }
        i++;
    }
    return 0;
}
