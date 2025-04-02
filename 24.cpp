#include <iostream>
#include <limits>
#include <vector>
#include <ctime> 

using namespace std;

int readPositiveNumber(string msg) {
    int number;
    while (true) {
        cout << msg;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else if (number <= 0) {
            cout << "Please enter a positive number: ";
        }
        else if (number > 100) {
            cout << "The maximum allowed number is 100. Please enter a valid number: ";
        }
        else {
            return number;
        }
    }
}

int randNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

vector<int> generateRandomArray(int number) {
    vector<int> arrayOfRandomNumbers(number);
    for (int& num : arrayOfRandomNumbers) {
        num = randNumber(1, 101);
    }
    return arrayOfRandomNumbers;
}

void printArrayElements(const vector<int>& arr) {
    cout << "This is the array elements: \n";

    int maxNumber = arr[0]; 
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "[" << i + 1 << "] " << arr[i] << "\n";
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }

    cout << "The largest number in the array is: " << maxNumber << endl;
}

int main() {
    srand((unsigned)time(NULL));

    int read = readPositiveNumber("Please enter the number of array elements (max 100): ");
    vector<int> randomNumbers = generateRandomArray(read);

    printArrayElements(randomNumbers);

    return 0;
}
