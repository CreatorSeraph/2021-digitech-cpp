#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, count;
	string result;

	cin >> n;

	if ((n / 3) % 2 == 0)
		count = 0;
	else count = 1;

	n %= 3;

	for (int i = 1; i <= n; i++)
		count++;

	if (count % 2 == 0)
		result = "CY";
	else result = "SK";

	cout << result;

	return 0;
}