#include <iostream>
#include <queue>
using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, size, i, temp;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);
	}


	return 0;
}