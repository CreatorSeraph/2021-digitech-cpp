#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int answer = 0;

    int N = v.size();

    vector<int> dp(N, 0);

    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(v[0], v[1]) + v[2];

    for (int i = 3; i < N; ++i)
    {
        dp[i] = max(v[i] + dp[i - 2], v[i] + v[i - 1] + dp[i - 3]);
    }

    answer = dp[N - 1];

    return answer;
}