#include <iostream>
#include <list>

using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[n];
	list<int> l;
	auto iter = l.begin();

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		iter = l.begin();
		for (int j = 0; j < arr[i]; j++)
			iter++;

		l.insert(iter, i + 1);
	}

	l.reverse();
	for (auto iter : l)
		cout << iter << ' ';

	return 0;
}