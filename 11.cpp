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

bool checkPalindrome(int number)
{
    string reversed = "";
    string text = to_string(number);

    for (int i = text.length() - 1; i >= 0; i--)
    {
        reversed += text[i];
    }
    if (text == reversed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printResult(bool x)
{
    if (x == true)
    {
        cout << "This is a palindrome number.\n";
    }
    else
    {
        cout << "Not palindrome!\n";
    }
}

int main()
{
    printResult(checkPalindrome(readPositiveNumber("Enter a number: \n")));
}
