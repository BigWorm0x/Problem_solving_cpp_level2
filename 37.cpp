#include <iostream>
#include <vector>
using namespace std;

int readNumber(string msg)
{
	int number;
	cout << msg;
	cin >> number;
	return number;
}

vector<int> createArray()
{
	vector<int> arr;
	char choice;

	do
	{
		arr.push_back(readNumber("Enter a number: "));
		cout << "Do you want to add another number? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	return arr;
}

void printArray(const vector<int>& arr)
{
	cout << "\nYou entered the following numbers:\n";
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << "\n";
}

int main()
{
	vector<int> myArray = createArray();
	printArray(myArray);

	return 0;
}
