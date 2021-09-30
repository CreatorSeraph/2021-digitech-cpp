#include <iostream>
#include <stack>
#include <string>
#include <hash_map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int N, M;

	cin >> N;

	hash_map<int, int> h;

	int in;

	for (int i = 0; i < N; i++)
	{
		cin >> in;
		++h[in];
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> in;
		cout << h[in] << sp;
	}

	return 0;
}