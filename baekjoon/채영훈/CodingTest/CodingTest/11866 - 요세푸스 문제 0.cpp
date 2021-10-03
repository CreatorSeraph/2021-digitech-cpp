#include <iostream>
#include <queue>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (size_t i = 0; i < N; i++) q.push(i + 1);

	cout << "<";
	while (!q.empty())
	{
		for (size_t i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << ", ";
	}
	cout << ">";

	return 0;
}