#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

using ll = long long;
using ul = unsigned long;
using mc_cp = map<char, char*>;
using pc_c = pair<char, char>;
using mc_pc_c = map<char, pc_c>;
using pi_s = pair<int, string>;
using pi_i = pair<int, int>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int fibo(int n, int& zero, int& one)
{
	if (n == 0) { ++zero; return 0; }
	else if (n == 1) { ++one; return 1; }
	else return fibo(n - 1, zero, one) + fibo(n - 2, zero, one);
}

int main()
{
	async_with_stdio;

	int T;
	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		int N, zero = 0, one = 0;
		cin >> N;
		fibo(N, zero, one);
		cout << zero << " " << one;
	}
}