#include <iostream>
using namespace std;
#include <string>
int readNumber(string msg)
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


int numberOfDigitReapeating(int numbers, int num )
{
    int frequency = 0;
    string text = to_string(numbers);    
    char target = '0' + num;
    for (char ch : text)
    {
        if (ch == target)
        {
            frequency++;
        }
    }

    return frequency;
}

void printResult(int freq)
{
    cout << "frequency = " << freq;
}

int main()
{
    int allNumbers = readNumber("please enter all numbers: \n");
    int numb = readNumber("please enter  numbers: \n");
    printResult(numberOfDigitReapeating(allNumbers, numb));
}
