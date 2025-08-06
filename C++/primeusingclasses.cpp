#include <iostream>
using namespace std;

// Class Definition
class PrimeChecker {
private:
    int number;

public:
    // Method to read a number
    void readNumber() {
        cout << "Enter a number: ";
        cin >> number;
    }

    // Method to check if the number is prime
    bool isPrime() {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Method to display the result
    void displayResult() {
        if (isPrime()) {
            cout << number << " is a prime number." << endl;
        } else {
            cout << number << " is not a prime number." << endl;
        }
    }
};

int main() {
    PrimeChecker pc;

    // Reading and checking the number
    pc.readNumber();
    pc.displayResult();

    return 0;
}