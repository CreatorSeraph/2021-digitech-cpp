#include <string>
#include <vector>

using namespace std;

int solution(vector<string> scores) {
    int answer = 0;

    int N = scores.size();

    vector<int> v(6, 0);
    // A°¡ 0 / F°¡ 5

    for (int i = 0; i < N; ++i)
    {
        fill(v.begin(), v.end(), 0);
        auto str = scores[i];
        for (int j = 0; j < str.size(); ++j)
        {
            int val = str[j] - 'A';
            v[val]++;
        }

        int val = 5;
        int sum = 0;
        for (int i = 0; i < 6; ++i)
        {
            sum += v[i] * val;
            val--;
        }

        if (v[5] < 2)
        {
            if (v[0] >= 2) answer++;
            else if (sum / str.size() >= 3) answer++;
        }
    }

    return answer;
}