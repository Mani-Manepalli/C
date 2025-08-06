#include<iostream>
using namespace std;
int main(){
    int i,t;
    for ( i = 1; i <= 5; i++)
    {
        for ( t = 1; t < i; t++)
        {
            cout << "*";
        }
        cout << "\n";
        
    }
    return 0;
}