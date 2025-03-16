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



// with enum 

#include <iostream>
using namespace std;

enum ePerfectNumber { perfect = 1, notPerfect = 2 };

int readNumber()
{
    int number;
    do
    {
        cout << "Enter number to check if this number is perfect or not: \n";
        cin >> number;
    } while (number <= 0);
    return number;
}

ePerfectNumber checkNumberPerfectOrNot(int number)
{
    int perfectSum = 0;
    for (int i = 1; i < number; i++)  
    {
        if (number % i == 0)
        {
            perfectSum += i;
        }
    }

    if (perfectSum == number)  
    {
        return ePerfectNumber::perfect;
    }
    else
    {
        return ePerfectNumber::notPerfect;
    }
}

void printResult(ePerfectNumber result)
{
    if (result == ePerfectNumber::perfect)  
    {
        cout << "This is a perfect number.\n";
    }
    else
    {
        cout << "This is not a perfect number.\n";
    }
}

int main()
{
    int number = readNumber();
    ePerfectNumber result = checkNumberPerfectOrNot(number);
    printResult(result);
    return 0;
}
