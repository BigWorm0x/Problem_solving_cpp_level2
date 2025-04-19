#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int readPositiveNumber(string msg)
{
	int number;
	do{
		cout << msg;
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() , '\n');
			cout << "!Errorr:don't entern alphapet\nplease";
		}
		else if (number <= 0)
		{
			cout << "!Errorr:don't entern negative number\nplease";
		}
		else
		{
			return number;
		}
	} while (true);
}

int createRandomNumber(int from , int to)
{
	int random = rand() % (to - from + 1) + from;
	return random;
}


vector <int> arrayOfRandomNumbers(int number)
{
	vector <int> array;
	if (number >= 100)
	{
		for (int i = 0; i < 100; i++) {
			array.push_back(createRandomNumber(-100, 100));
		}
	}
	else if (number < 100)
	{
		for (int j = 0; j < number; j++) {
			array.push_back(createRandomNumber(-100, 100));
		}
	}
	return array;
}

void printResult(vector <int> arrayOfRandomNumbers)
{
	int count = 0;
	for (int i = 0; i < arrayOfRandomNumbers.size(); i++) 
	{
		cout << arrayOfRandomNumbers[i] << " ";
		if (arrayOfRandomNumbers[i] > 0)
		{
			count += 1;
		}
	}
	cout << "\npositive number is: " << count;
}


int main()
{
	srand(time(0));
	int read = readPositiveNumber("Enter a number: ");
	vector <int> arrOfrandNumbers = arrayOfRandomNumbers(read);
	printResult(arrOfrandNumbers);
}
