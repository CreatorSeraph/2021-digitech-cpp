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

int main()
{
	ll X, Y, Z = 0, left = 1, right = 1000000000, mid = 0, per = 0, add = -1;
	
	cin >> X >> Y;

	// Z = ������ ������ total�� �¸��� %
	Z = ll(Y * 100 / X);

	// Z�� 99���� �۴ٸ� while���� ���� �ƴ϶�� -1�� add�� print
	if (Z < 99)
	{
		// right�� left�� �Ѿ����, left�� right�� �Ѿ���� ����
		while (left <= right)
		{
			// mid = left�� right�� �߽ɰ�
			mid = (left + right) / 2;

			// val = X�� Y�� mid�� ������ ������ %
			per = (Y + mid) * 100 / (X + mid);

			// mid�� ������ ������ %�� Z���� Ŭ ���
			if (per > Z) // right = mid���� 1�� �� ���� ���������� ����, add�� ������ mid�� ����
				right = mid - 1, add = mid;
			else // left = mid���� 1�� ���� ���� �������� ����
				left = mid + 1;
		}
	}

	// add���� print
	cout << add << "\n";

	return 0;
}