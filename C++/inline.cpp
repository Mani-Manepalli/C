#include<iostream>
using namespace std;
inline int mul(int a,int b){
    return a*b;
}
inline int cube(int x){
    return x*x*x;
}
int main(){
    int a,b,c;
    cout << "enter values of a,b,c:";
    cin >> a>>b>>c;
    
    cout<<"Multiplication:"<<mul(a,b)<<"\nCube:"<<cube(c);
    return 0;
}