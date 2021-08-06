#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void Binary(ull n)
{
	if (n > 0)
	{
		Binary(n / 2);
		cout << n % 2;
	}
}

int main()
{
	ull N;
	cin >> N;

	Binary(N);

	return 0;
}