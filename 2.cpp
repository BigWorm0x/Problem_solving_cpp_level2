#include <iostream>
using namespace std;

int readNumber()
{
    int number;
    do
    {
        cout << "Enter number to check if this number is prime or not prime: \n";
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkPrimeOrNotPrime(int number)
{
    if (number == 1) 
        return false;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false; 
        }
    }
    return true; 
}

void printResult(int number)
{
    cout << "Prime numbers from " << 1 << " to " << number << endl;
    cout << "are: \n";
    for (int i = 1; i <= number; i++)
    {
        if (checkPrimeOrNotPrime(i))
        {
            cout << i << "\n";
        }
    }
}

int main()
{
    int read = readNumber();
    printResult(read); 
    return 0;
}
