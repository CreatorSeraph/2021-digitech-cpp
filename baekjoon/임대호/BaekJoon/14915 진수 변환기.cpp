#include <iostream>
#include <list>

using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int m, n, temp;

	cin >> m >> n;

	list<int> l;
	while (m / n != 0)
	{
		temp = m % n;
		m /= n;

		l.push_front(temp);
	}
	l.push_front(m % n);

	for (auto iter : l)
	{
		if (n > 10)
			cout << uppercase << hex << iter;
		else
			cout << iter;

	}

	return 0;
}