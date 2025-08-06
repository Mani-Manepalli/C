#include<iostream>
using namespace std;
int main(){
int a,mod,rem;
cout<<"Enter no.of minutes:"<<endl;
cin >> a;
mod = a%60;
rem = a/60;
cout << "Given minutes is"<<a<<"\nThe output is:"<<rem<<":"<<mod<<endl;

return 0;

}