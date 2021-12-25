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

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int solution(int n, vector<int> lost, vector<int> reserve)
{
	char answer = lost.size();

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (char l = 0; l < lost.size(); l++)
		for (char r = 0; r < reserve.size(); r++)
			if (reserve[r] == lost[l])
				reserve[r] = -100, lost[l] = -200, --answer;

	for (char l = 0; l < lost.size(); l++)
		for (char r = 0; r < reserve.size(); r++)
			if (reserve[r] == lost[l] - 1 || reserve[r] == lost[l] + 1)
				reserve[r] = -100, lost[l] = -200, --answer;

	return answer;
}

int main()
{
	int N, S, R;
	cin >> N >> S >> R;

	vector<int> lost(S);
	vector<int> reserve(R);

	for (size_t i = 0; i < S; i++)
		cin >> lost[i];

	for (size_t i = 0; i < R; i++)
		cin >> reserve[i];

	cout << solution(N, lost, reserve);

	return 0;
}