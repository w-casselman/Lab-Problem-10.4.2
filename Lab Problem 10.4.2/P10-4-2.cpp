// P10-4-2
// Wesley Casselman
// November 8th of 2023

#include <iostream>
#include <string>

using namespace std;

bool isNumeric(string s);
bool isCorrectLength(string s);
void convert2Digits(string s, int digits[]);
bool isCardValid(int digits[], int size);

const int SIZE = 16;

int main(void)
{
	int arr[SIZE];
	string cardInput;

	while (true)
	{
		cout << "Enter 16-digit credit card # or Q to quit: ";
		getline(cin, cardInput);
		if (cardInput == "Q")
			break;
		if (!isNumeric(cardInput))
		{
			cout << "Error - card number must contain only digits." << endl << endl;
			continue;
		}
		if (!isCorrectLength(cardInput))
		{
			cout << "Error - card number must contain 16 digits." << endl << endl;
			continue;
		}
		convert2Digits(cardInput, arr);
		if (isCardValid(arr, SIZE))
		{
			cout << "Card is valid." << endl << endl;
		}
		else
		{
			cout << "Card is not valid." << endl << endl;
		}
	}

	return 0;
}

bool isNumeric(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '0': break;
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		case '5': break;
		case '6': break;
		case '7': break;
		case '8': break;
		case '9': break;
		default: return false;
		}
	}
	return true;
}

bool isCorrectLength(string s)
{
	if (s.length() == SIZE)
		return true;
	return false;
}

void convert2Digits(string s, int digits[])
{
	for (int i = 0; i < s.length(); i++)
	{
		digits[i] = s[i] - 48;
	}
}

bool isCardValid(int digits[], int size)
{
	int crit = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		if (i % 2 == 1)
		{
			crit += digits[i];
		}
		else
		{
			if (digits[i] >= 0 && digits[i] <= 4)
			{
				crit += 2 * digits[i];
			}
			else
			{
				crit += 2 * digits[i] - 9;
			}
		}
	}
	if (crit % 10 == 0)
		return true;
	return false;
}