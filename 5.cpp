#include <iostream>
using namespace std;

int readNumber(string msg)
{
    int number;
    do
    {
        cout << msg;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (number <= 0); // Ensure the input is a positive number
    return number;
}

void printDigits(int number)
{
    cout << "Reversed number: ";
    while (number > 0)
    {
        int digit = number % 10; // Extract the last digit
        cout << digit; // Print the digit
        number = number / 10; // Remove the last digit
    }
    cout << endl;
}

int main()
{
    int number = readNumber("Enter a number to reverse it: ");
    printDigits(number);
    return 0;
}
