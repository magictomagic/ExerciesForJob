#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int main(){
    string input;
    getline(cin, input);
    istringstream tmp(input);
    string s;
    stack<string> st;
    while(tmp>>s){
        st.push(s);
    }
    while(!st.empty()){
        if(st.size()!=1){
            cout<<st.top()<<" ";
            st.pop();
        }else{
            cout<<st.top();
            st.pop();
        }
    }
    return 0;
}
