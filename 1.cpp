#include <iostream>
using namespace std;

void tableHeader()
{
	cout << "\n\t\t\t Multiplication table from 1 to 10 \t\t\t\n\n ";
	for (int i = 1; i <= 10; i++)
	{
		cout << "\t    " << i;
	}
	cout << "\n------------------------------------------------------------------------------------------------\n";

}

void sideTableLift()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t| ";
		for (int j = 1; j <= 10; j++)
		{
			cout << "  " << i * j << "\t ";
		}
		cout << "\n";
	}
	cout << "\n\t\t\t \t\t Good Luck \n";
}

int main()
{
	tableHeader();
	sideTableLift();
}
