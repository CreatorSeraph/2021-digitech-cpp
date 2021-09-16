#include <iostream>

using namespace std;

int main()
{
	char* str = new char[1000000];
	char* alpha = new char[26];
	int* omega = new int[26];
	int Max = 0, temp = 0, pos = 0;

	for (int i = 0; i < 26; i++)
		omega[i] = 0;

	for (int i = 0; i < 26; i++)
		alpha[i] = i + 65;

	cin >> str;

	for (int i = 0; i < 1000000; i++)
		for (int j = 0; j < 26; j++)
			if ((j + 65) == str[i] || (j + 97) == str[i])
				omega[j]++;

	for (int k = 0; k < 26; k++)
	{
		if (Max == omega[k])
		{
			temp = Max;
		}
		if (Max < omega[k])
		{
			Max = omega[k];
			pos = k;
		}
	}

	if (temp == Max)
		cout << "?\n";
	else
		cout << alpha[pos] << "\n";

	return 0;
}