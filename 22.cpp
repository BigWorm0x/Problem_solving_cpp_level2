#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int readPositiveNumber(string msg)
{
    int number;
    while (true)
    {
        cout << msg;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
        }
        else if (number <= 0)
        {
            cout << "Please enter a **positive** number greater than 0.\n";
        }
        else
        {
            return number;
        }
    }
}

vector<int> anyThing(int count)
{
    vector<int> x(count);
    for (int i = 0; i < count; i++)
    {
        cout << "Enter element [" << i + 1 << "]: ";
        cin >> x[i];
    }

    return x; 
}

void printResult(int number, vector<int> arr)
{
    int counter = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (number == arr[i])
        {
            counter++;
        }
    }
   
    cout << "\n" << number << " is repeated " << counter << " time(s).\n";
}

int main()
{
    int length = readPositiveNumber("Enter length of array: ");
    vector<int> myArray = anyThing(length);

    int numberToCheck = readPositiveNumber("Enter number to check how many times it is repeated: ");
    
    printResult(numberToCheck, myArray); 

    return 0;
}
