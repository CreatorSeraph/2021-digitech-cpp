#include <iostream>
using namespace std;

string GetText(int count, const char* result)
{
	char* c = new char[128];

	sprintf(c, "Case %d: %s", count, result);

	return c;
}

int ´Ü¾îÆÛÁñ()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int count = 0;
	string a, b, result;

	do
	{
		cin >> a >> b;

		if (a == "END" && b == "END")
			break;

		count++;
		if (a.size() == b.size())
		{
			int arr1[26]{ 0, }, arr2[26]{ 0, };

			for (int i = 0; i < a.size(); i++)
			{
				arr1[a[i] - 97]++;
				arr2[b[i] - 97]++;
			}

			for (int i = 0; i < 26; i++)
			{
				if (arr1[i] != arr2[i])
				{
					result = "different";
					break;
				}
				result = "same";
			}
		}
		else result = "different";

		cout << GetText(count, result.c_str()) << '\n';

	} while (true);

	return 0;
}