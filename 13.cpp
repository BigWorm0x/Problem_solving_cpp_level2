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


void printResult(int number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1 ; j <= i ; j++ )
        {
            cout << i;
        }
        cout << "\n";
    }
}


int main()
{
    printResult(readPositiveNumber("enter a number: \n"));
}
