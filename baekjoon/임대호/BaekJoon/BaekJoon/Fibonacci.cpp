#include <iostream>
#include <vector>

using namespace std;

int Fibonacci1()
{
	// �Է¹��� ��
	int input;
	cin >> input;

	// ���� ������� ������ vector!
	vector<int> v(45, 0);
	v[0] = 0;
	v[1] = 1;

	// ������ �ϴ� for��!
	for (int i = 2; i <= input; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[input];
	return 0;
}
