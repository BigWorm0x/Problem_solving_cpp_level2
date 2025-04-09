#include <iostream>
#include <limits>
#include <vector>
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
			cin.ignore(numeric_limits<streamsize>::max() , '\n');
			cout << "Errorr: don't enter alphapet \n";
		}
		else if (num <= 0)
		{
			cout << "Errorr: don't enter nigative number \n";
		}
		else
		{
			return num;
		}
	} while (true);
}

char generateRandomCharacter(char from ,  char to)
{
	char x = rand() % (to - from + 1) + from;
	return x;
}

string generateRandomKey()
{
	string secretKey;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				secretKey = secretKey + generateRandomCharacter('A', 'Z');
			}
			if (i != 3)
			{
				secretKey += '-';
			}
		}
	return secretKey;
}

vector <string> addSecKeyToArray(int number)
{
	vector <string> array;
	for (int i = 0; i < number; i++)
	{
		array.push_back(generateRandomKey());
	}
	return array;
}

void printResult(vector <string> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "secret-Key[" << i + 1 << "]: " << arr[i] << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));
	printResult(addSecKeyToArray(readNumber("Enter how many keys you want: ")));
}
