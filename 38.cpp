#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int readPositiveNumber(string msg)
{
	int number;
	do
	{
		cout << msg;
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: enter a positive number, not alphabet: \n";
		}
		else if (number <= 0)
		{
			cout << "Enter a positive number: \n";
		}
		else
		{
			return number;
		}
	} while (true);
}

int generateRandomNumber(int from, int to)
{
	int x = rand() % (to - from + 1) + from;
	return x;
}

vector <int> arrayOfRandomNumbers(int number)
{
	vector <int> array;
	if (number >= 100)
	{
		for (int i = 0; i < 100; i++)
		{
			array.push_back(generateRandomNumber(1, 100));
		}
	}
	else if (number < 100)
	{
		for (int i = 0; i < number; i++)
		{
			array.push_back(generateRandomNumber(1, 100));
		}
	}
	return array;
}

vector <int> arrayOfOddNumbers(vector <int> AORNum)
{
	vector <int> ODD;
	for (int i = 0; i < AORNum.size(); i++)
	{
		if (AORNum[i] % 2 != 0) 
		{
			ODD.push_back(AORNum[i]);
		}
	}
	return ODD;
}

void printResult(vector <int> arrayOfRandomNumbers, vector <int> arrayOfOddNumbers)
{
	int size = arrayOfRandomNumbers.size();
	cout << "This is elements of array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arrayOfRandomNumbers[i] << " ";
	}
	cout << "\n";
	int sizeOfOdd = arrayOfOddNumbers.size();
	cout << "This is elements of odd array:\n";
	for (int i = 0; i < sizeOfOdd; i++)
	{
		cout << arrayOfOddNumbers[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	int read = readPositiveNumber("Enter a number:\n");
	vector <int> arr = arrayOfRandomNumbers(read);
	vector <int> arrayOfODD = arrayOfOddNumbers(arr);  
	printResult(arr, arrayOfODD);
}
