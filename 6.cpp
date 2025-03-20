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
    } while (number <= 0); 
    return number;
}

int sumOfnumbers(int number)
{
    int sum = 0;
    while (number > 0)
    {
        int digit = number % 10;
        sum = sum + digit;
        number = number / 10;
    }
    return sum;
}


void printResult(int sum)
{
    cout << "this is sum of numbers " << sum;
}

int main()
{
    printResult(sumOfnumbers(readNumber("enter a number: \n")));
}
