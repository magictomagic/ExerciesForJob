#include<iostream>
#include<algorithm>
using namespace std;
class Student{
  private:
    string name;
    string subject;
  public:
    int grade;
    Student(string n, string s, int g){
        name = n;
        subject = s;
        grade = g;
    }
    Student(){} // for -> Student stu[n];
    void toString(){
        cout<<name + " " + subject;
    }
};
int main(){
    int n;
    cin>>n;
    // 静态对象数组
    Student stu[n]; // because -> Student(){}
    int i = 0;
    while(i < n){
        string n1, s1;
        int g1;
        cin>>n1>>s1>>g1;
        stu[i] = Student(n1, s1, g1);
        i++;
    }
    sort(stu, stu + n, [&stu](Student a, Student b){return a.grade < b.grade;});
    stu[n-1].toString();
    cout<<endl;
    stu[0].toString();
    return 0;
}
