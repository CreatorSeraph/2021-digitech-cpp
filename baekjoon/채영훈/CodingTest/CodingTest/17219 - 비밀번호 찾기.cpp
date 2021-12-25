#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	int N, M;
	cin >> N >> M;

	unordered_map<string, string> um;

	string url, pw;
	for (size_t i = 0; i < N; i++)
	{
		cin >> url >> pw;
		um[url] = pw;
	}

	for (size_t i = 0; i < M; i++)
	{
		cin >> url;
		cout << um[url] << nl;
	}

	return 0;
}