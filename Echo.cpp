#include<iostream>

using namespace std;

int main()
{
	cout << "Enter:\n";
	char symbol;
	do
	{
		cin.get(symbol);
		cout << symbol;
	}while(symbol != '\n');
	cout << "That's echo.\n";
	return 0;
}