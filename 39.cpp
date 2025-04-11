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

bool isPrime(int number)
{
	if (number < 2)
		return false;
	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

vector <int> arrayOfPrimeNumbers(vector <int> AORNum)
{
	vector <int> prime;
	for (int i = 0; i < AORNum.size(); i++)
	{
		if (isPrime(AORNum[i]))
		{
			prime.push_back(AORNum[i]);
		}
	}
	return prime;
}

void printResult(vector <int> arrayOfRandomNumbers, vector <int> arrayOfPrimeNumbers)
{
	int size = arrayOfRandomNumbers.size();
	cout << "This is elements of array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arrayOfRandomNumbers[i] << " ";
	}
	cout << "\n";
	int sizeOfPrime = arrayOfPrimeNumbers.size();
	cout << "This is elements of prime array:\n";
	for (int i = 0; i < sizeOfPrime; i++)
	{
		cout << arrayOfPrimeNumbers[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int read = readPositiveNumber("Enter a number:\n");
	vector <int> arr = arrayOfRandomNumbers(read);
	vector <int> arrayOfPrime = arrayOfPrimeNumbers(arr);

	printResult(arr, arrayOfPrime);
}
