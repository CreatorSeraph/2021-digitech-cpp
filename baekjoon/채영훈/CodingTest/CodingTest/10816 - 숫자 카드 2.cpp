#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N, M;

	cin >> N;

	unordered_map<int, int> um;

	int in;

	for (int i = 0; i < N; i++)
	{
		cin >> in;
		++um[in];
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> in;
		cout << um[in] << sp;
	}

	return 0;
}