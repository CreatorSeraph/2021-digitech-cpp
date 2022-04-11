#include <iostream>
#include <queue>

using namespace std;

int Ä«µå2()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> q;

	for (int i = 0; i < N; i++)
		q.push(i + 1);

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.back(); 

	return 0;
}