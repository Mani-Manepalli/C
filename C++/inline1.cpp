#include<iostream>
using namespace std;
inline int cube(int x){
    return x*x;
}
int main(){
    int a;
    cout << "enter values of a:";
    cin >>a;
    
    cout<<"\nsquare:"<<cube(a);
    return 0;
}