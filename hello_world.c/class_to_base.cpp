#include<iostream>
using namespace std;

class time{

    public :

    int hours,minutes;

    time(int h,int m){

        hours = h;

        minutes = m;

    };

    operator int(){

        return  (hours*60+minutes);
    } 



};
int main(){

    time t(2,30);

    int totalmin = t;
    cout << "Total minutes:"<<totalmin;
    return 0;
    



}