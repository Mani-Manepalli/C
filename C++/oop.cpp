#include <iostream>
using namespace std;
class vinay {
  public: 
  int age;
void display();
};
void vinay::display(){
  
    cin>>age;

    cout<<"age is"<<age;
}
int main() {
    vinay v1;
    v1.display();
 
    return 0;
}