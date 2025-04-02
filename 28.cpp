#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int readPositiveNumber(string msg)
{
    int number;
    do {
        cout << msg;
        cin >> number;

        if (cin.fail())  
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: Please enter a valid positive number.\n";
        }
        else if (number <= 0)  
        {
            cout << "Error: Please enter a number greater than zero.\n";
        }
        else {
            return number;
        }
    } while (true);  
}

int GenerateRandomNumber(int from , int to)
{
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}

vector <int> arrayOfRandomNumbers(int number)
{
    vector <int> arr;
    if (number >= 100)
    {
        for (int i = 0; i < 100; i++)
        {
            arr.push_back(GenerateRandomNumber(0, 100));
        }
    }
    else if (number < 100)
    {
        for (int i = 0; i < number; i++)
        {
            arr.push_back(GenerateRandomNumber(0, 100));
        }
    }
    return arr;
}

void printResult(vector <int> array)
{
    int size = array.size();
    vector <int> arrayCopy;
    for (int i = 0; i < size; i++)
    {
        arrayCopy.push_back(array[i]);
    }
    cout << "array number one: \n";
    for (int i = 0; i < size; i++)
    {
         cout << array[i] << "\n";
    }
    cout << "array number two: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arrayCopy[i] << "\n";
    }
}


int main()
{
    int num = readPositiveNumber("Enter a positive number: ");
    printResult(arrayOfRandomNumbers(num));
    return 0;
}
