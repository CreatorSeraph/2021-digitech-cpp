#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int 요세푸스문제0()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	queue<int> q;

	for (int i = 0; i < N; i++)
		v[i] = i + 1;

	int count = 0;
	int index = K - 1;
	int loop_count = K;

	bool ignore = false;
	while (true)
	{
		if (loop_count % K == 0 || ignore)
		{
			if (v[index] != 0)
			{
				q.push(v[index]);
				v[index] = 0;
				count++;
				ignore = false;

				if (count >= N) break;
			}
			else
				ignore = true;
		}
		index++;

		if (index >= N)
			index -= N;

		while (v[index] == 0)
		{
			index++;

			if (index >= N)
				index -= N;
		}

		loop_count++;
	}

	cout << '<';
	int back;

	int size = q.size();
	for (int i = 0; i < size; i++)
	{
		back = q.front();
		q.pop();

		cout << back;
		if (i != size - 1)
			cout << ", ";
	}
	cout << '>';

	return 0;
}