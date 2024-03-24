#include <iostream>
#include <list>
#include <cmath>

using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int sum = 0;
    int dif;
    list<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> dif;
        arr.push_back(dif);

        sum += dif;
    }
    arr.sort();

    int removeCount = (int)round(arr.size() * 0.15f);

    int p;
    int index = 0;
    while (index < removeCount) {
        p = arr.back();
        arr.pop_back();

        sum -= p;

        index++;
    }

    index = 0;
    while (index < removeCount) {
        p = arr.front();
        arr.pop_front();

        sum -= p;

        index++;
    }

    if (arr.empty()) {
        cout << 0;
    } else {
        int average = (int) round(sum / (float)arr.size());
        cout << average;
    }

	return 0;
}