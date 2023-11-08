// P10-4-2
// Wesley Casselman
// November 8th of 2023

#include <iostream>

using namespace std;

bool isCardValid(int digits[], int size);

int main(void)
{
	const int SIZE = 8;
	int arr[SIZE];
	int n;

	while (true)
	{
		cout << "Enter 8-digit credit card # or Q to quit: ";
		cin >> n;
		if (cin.fail())
			break;

		for (int i = SIZE - 1; i >= 0; i--)
		{
			arr[i] = n % 10;
			n /= 10;
		}

		if (isCardValid(arr, SIZE))
		{
			cout << "Card is valid." << endl;
		}
		else
		{
			cout << "Card is not valid." << endl;
		}

		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i] << endl;
		}

		cout << endl;
	}

	return 0;
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