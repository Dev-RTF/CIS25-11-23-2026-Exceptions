#include <iostream>
#include <stdexcept>

using namespace std;

// make your own exception
class DivisionByZeroError : public std::invalid_argument {
    public:
        DivisionByZeroError(const std::string& message) : std::invalid_argument(message) {}
};

double throwIfZero(double dub) {
    if (dub == 0) {
        // throw std::invalid_argument("division by zero");
        throw DivisionByZeroError("Zero is not allowed!!!");
    } else {
        return dub;
    }
}

// can only handle division in the case that b is not 0
double divideThenAddOne(double a, double b) {
    
    return (a / throwIfZero(b)) + 1;
    
}

int main() {
    double a;
    double b;

    cout << endl << "Enter a number for a: ";
    cin >> a;

    cout << endl << "Enter a number for b: ";
    cin >> b;
    cout << endl;
    double number;

    try { // whatever's in here only exists in the duration of the try block (kind of like a for loop). the fix is to declare before and initialize after
        number = divideThenAddOne(a, b);
    } catch(const std::invalid_argument& e) { // any function can "throw", but it needs to be caught at some point or else the program crashes
        // whatever you want to make sure that the error is handled gracefully
        cout << endl << "Your number for b was not valid! The exception was: " << e.what();
        cout << endl << "Enter a new number for b: ";
        cin >> b;
        number = divideThenAddOne(a, b);
    } // catch() {} // you can have multiple catches
        cout << number << endl;
    return 0;
}