#include <iostream>
#include <string>
#include <limits>
using namespace std;

int readPositiveNumber(string message)
{
    long number;
    while (true)
    {
        cout << message;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
        }
        else if (number < 0)
        {
            cout << "Please enter a positive number.\n";
        }
        else
        {
            return number;
        }
    }
}

int countDigitFrequency(int number, int digit)
{
    int frequency = 0;
    string numberStr = to_string(number);
    char target = '0' + digit;

    for (char ch : numberStr)
    {
        if (ch == target)
            frequency++;
    }

    return frequency;
}

void printAllFrequencies(int number)
{
    for (int i = 0; i <= 9; i++)
    {
        int freq = countDigitFrequency(number, i);
        if (freq > 0)
        {
            cout << "Digit " << i << " Frequency is " << freq << " Time(s).\n";
        }
    }
}

int main()
{
    int number = readPositiveNumber("Enter a positive number: ");
    printAllFrequencies(number);
    return 0;
}
