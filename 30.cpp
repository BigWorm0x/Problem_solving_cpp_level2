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
    int size = (number >= 100) ? 100 : number;

    for (int i = 0; i < size; i++) {
        arr.push_back(GenerateRandomNumber(0, 100));
    }
    return arr;
}

vector<int> AnotherRandomNumbers(int number) {
    vector<int> arrayTwo;
    int size = (number >= 100) ? 100 : number;

    for (int i = 0; i < size; i++) {
        arrayTwo.push_back(GenerateRandomNumber(0, 100));
    }
    return arrayTwo;
}

vector<int> sumOfAllArrays(vector<int> arrayOfRandomNumbers, vector<int> AnotherRandomNumbers) {
    vector<int> sum;
    for (int i = 0; i < arrayOfRandomNumbers.size(); i++) {
        sum.push_back(arrayOfRandomNumbers[i] + AnotherRandomNumbers[i]);
    }
    return sum; 
}

void printResult(vector<int> arrayOfRandomNumbers, vector<int> AnotherRandomNumbers, vector<int> sum) {
    cout << "First array of random numbers:\n";
    for (int i = 0; i < arrayOfRandomNumbers.size(); i++) {
        cout << arrayOfRandomNumbers[i] << "|";
    }
    cout << "\n";

    cout << "Second array of random numbers:\n";
    for (int i = 0; i < AnotherRandomNumbers.size(); i++) {
        cout << AnotherRandomNumbers[i] << "|";
    }
    cout << "\n";

    cout << "Sum of all elements:\n";
    for (int i = 0; i < sum.size(); i++) {
        cout << sum[i] << "|";
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));

    int read = readPositiveNumber("Enter a positive number: ");

    vector<int> firstArray = arrayOfRandomNumbers(read);
    vector<int> secondArray = AnotherRandomNumbers(read);
    vector<int> sumArray = sumOfAllArrays(firstArray, secondArray);

    printResult(firstArray, secondArray, sumArray);

    return 0;
}
