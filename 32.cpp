#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int readPositiveNumber(string message)
{
	int number;
	do
	{
		cout << message;
		cin >> number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: Please enter a valid number.\n";
		}
		else if (number <= 0)
		{
			cout << "Error: Number must be greater than zero.\n";
		}
		else
		{
			return number;
		}

	} while (true);
}

int generateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

vector<int> generateRandomArray(int count)
{
	vector<int> numbers;

	int size = (count >= 100) ? 100 : count;

	for (int i = 0; i < size; i++)
	{
		numbers.push_back(generateRandomNumber(1, 100));
	}

	return numbers;
}

vector<int> reverseArray(const vector<int>& originalArray)
{
	vector<int> reversedArray;
	for (int i = originalArray.size() - 1; i >= 0; i--)
	{
		reversedArray.push_back(originalArray[i]);
	}
	return reversedArray;
}

void printArrays(const vector<int>& original, const vector<int>& reversed)
{
	cout << "Original array elements:\n";
	for (int num : original)
	{
		cout << num << " ";
	}

	cout << "\nReversed array elements:\n";
	for (int num : reversed)
	{
		cout << num << " ";
	}
}

int main()
{
	int count = readPositiveNumber("Enter a positive number: ");
	vector<int> originalArray = generateRandomArray(count);
	vector<int> reversed = reverseArray(originalArray);
	printArrays(originalArray, reversed);
}
