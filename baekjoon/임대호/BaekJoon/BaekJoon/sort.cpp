#include <iostream>
#include <vector>

using namespace std;

// ���ڷ� �Ѱܹ��� �� ������ ���� �ٲ��ִ� �Լ�!
void Swap(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int Sort1()
{
	// �Է¹޴� Ƚ��!
	int count;
	cin >> count;

	// �Է¹޴� �����͸� �����ϱ� ���� vector!
	vector<int> v(count, 0);

	for (int i = 0; i < count; i++)
	{
		// �Է¹޴�!
		cin >> v[i];

		// ���� for���� ���� vector�� �� �պ��� ��� ��
		for (int j = 0; j < i; j++)
		{
			// ���� �� �� �� ���� ���� �������� ����
			if (v[j] > v[i])
			{
				Swap(&v[j], &v[i]);
			}
		}
	}

	// ����ϴ� for��!
	for (int i = 0; i < count; i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
