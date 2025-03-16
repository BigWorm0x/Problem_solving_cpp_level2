#include <iostream>
using namespace std;

int readNumber()
{
    int number;
    do
    {
        cout << "Enter number to check if this number perfect or not: \n";
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkNumberIsPerfectOrNot(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == number)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void printResult(bool res)
{
    if (res == true)
    {
        cout << "Perfect number";
    }
    else
    {
        cout << " Not Perfect number!";
    }
}

int main()
{
    int read = readNumber();
    bool checkNum = checkNumberIsPerfectOrNot(read);
    printResult(checkNum);
}
