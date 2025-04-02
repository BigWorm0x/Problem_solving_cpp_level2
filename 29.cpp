#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int readPositiveNumber(string msg) {
    int number;
    do {
        cout << msg;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a valid positive number.\n";
        }
        else if (number <= 0) {
            cout << "Error: Please enter a number greater than zero.\n";
        }
        else {
            return number;
        }
    } while (true);
}

int GenerateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

vector<int> arrayOfRandomNumbers(int number) {
    vector<int> arr;
    int size;
    if (number >= 100) {
        size = 100;
    }
    else {
        size = number;
    }
    for (int i = 0; i < size; i++) {
        arr.push_back(GenerateRandomNumber(0, 100));
    }
    return arr;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void printResult(const vector<int>& array) {
    cout << "Array elements:\n";
    for (int num : array) {
        cout << num << " | ";
    }

    cout << "\n\nPrime numbers in the array:\n";
    bool foundPrimes = false;
    for (int num : array) {
        if (isPrime(num)) {
            cout << num << " ";
            foundPrimes = true;
        }
    }

    if (!foundPrimes) {
        cout << "No prime numbers found in the array.";
    }
    cout << endl;
}

int main() {
    srand(time(0)); 
    int num = readPositiveNumber("Enter a positive number: ");
    printResult(arrayOfRandomNumbers(num));
    return 0;
}
