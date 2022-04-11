#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Pressents()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<float> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	printf("%.2f", arr[1]);

	return 0;
}