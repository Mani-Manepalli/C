#include <iostream>
using namespace std;
class Person {
protected:
    string name;
    int age;
    char gender;

public:
    void getPersonalDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender (M/F): ";
        cin >> gender;
    }

    void displayPersonalDetails() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
    }
};

class Patient : public Person {
private:
    string disease;
    int patientID;

public:
    void getPatientDetails() {
        getPersonalDetails();
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cin.ignore(); 
        cout << "Enter Disease: ";
        getline(cin, disease);
    }

    void displayPatientDetails() {
        displayPersonalDetails();
        cout << "\nPatient ID: " << patientID;
        cout << "\nDisease: " << disease << endl;
    }
};

int main() {
    Patient p;
    cout << "Enter Patient Details:\n";
    p.getPatientDetails();

    cout << "\nDisplaying Patient Details:\n";
    p.displayPatientDetails();

    return 0;
}