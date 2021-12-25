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

// ü������ ũ��
const int LINE = 8;
const int CROSS = LINE * 2 - 1;

//Q = ��
bool columns[LINE]; // ������ �����ϴ� Q�� ��ġ������ ��� �迭
bool c_rt[CROSS]; // ������ ����� ���ϴ� �밢���� Q�� ��ġ������ ��� �迭
bool c_lt[CROSS]; // ���� ����� ���ϴ� �밢���� Q�� ��ġ������ ��� �迭
int pos[LINE]; // �������� Q�� ��ġ������ ��� �迭

void Print()
{
	for (int j = 0; j < LINE; j++) // �� (������)
	{
		for (int i = 0; i < LINE; i++) // �� (������)
		{
			if (pos[i] == j)
				cout << "��";
			else
				cout << "��";
		}
		cout << "\n";
	}
	cout << "\n" << "\n";
}

void Set(int i) // i�� ��(������)
{
	for (int j = 0; j < LINE; j++) // j�� ��(������)
	{
		// columns�� ������ �ٸ� Q�� Ȯ��
		// c_rt�� ������ ����� ���ϴ� �밢���� �ٸ� QȮ��
		// c_lt�� ���� ����� ���ϴ� �밢���� �ٸ� QȮ��
		// true : ����, false : ����
		if (!columns[j] && !c_rt[i + j] && !c_lt[i - j + (LINE - 1)])
		{
			// ���� ���ٸ� pos[i]�� Q�� ��ġ ������ ����
			pos[i] = j;
			if (i == (LINE - 1)) // i�� �ִ밪�� ��� Print�� ȣ���ϰ� return
			{
				Print(); return;
			}
			else // i�� �ִ밪�� �ƴ� ��� ���� Q�� ������ �����ϰ� ���� ��(i + 1)�� ���� Q�� ������ ã������ Set(i + 1) ȣ��
			{
				columns[j] = c_rt[i + j] = c_lt[i - j + (LINE - 1)] = true;
				Set(i + 1);
				// Set�Լ��� return�Ǿ��ٸ� �ٽ� ���ʴ�� ��ȯ�ϸ鼭 i���� ���� Q�� ��ġ���� �ʱ�ȭ
				columns[j] = c_rt[i + j] = c_lt[i - j + (LINE - 1)] = false;
			}
		}
	}
}

int main()
{
	Set(0);

	return 0;
}