#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int readNumber(string msg)
{
	int num;
	do {
		cout << msg;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: Please enter a valid number.\n";
		}
		else if (num <= 0)
		{
			cout << "Error: Number must be positive.\n";
		}
		else
		{
			return num;
		}
	} while (true);
}

int generateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

vector<int> arrayOfNumbers(int number)
{
	vector<int> arr;
	for (int i = 0; i < number; i++)
	{
		arr.push_back(generateRandomNumber(1, 100));
	}
	return arr;
}

void printArray(vector<int> arr)
{
	cout << "Generated Array:\n";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void printResult(int search, vector<int> arr)
{
	cout << "Number you are looking for: " << search << "\n";
	bool found = false;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == search)
		{
			cout << "The number is found at index: " << i << "\n";
			cout << "The number's order is: " << i + 1 << "\n";
			found = true;
			break; 
		}
	}

	if (!found)
	{
		cout << "The number is not found in the array.\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arraySize = readNumber("Enter number of elements in the array: ");
	vector<int> numbers = arrayOfNumbers(arraySize);

	printArray(numbers);

	int numberToSearch = readNumber("Enter the number to search for: ");
	printResult(numberToSearch, numbers);

	return 0;
}
