#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> place;
	int N;
	int M;
	cout << "���� �Է�" << endl;

	cin >> N;

	cout << "��� �Է�" << endl;

	for (int i = 0; i < N; ++i)
	{
		cin >> M;

		place.insert(pair<int, int>(M, M));
	}

	cout << endl << "��� ���� & ���" << endl;

	map<int, int>::iterator iter;

	for (iter = place.begin(); iter != place.end(); iter++)
	{
		cout << (*iter).second << endl;
	}

	return 0;

}

