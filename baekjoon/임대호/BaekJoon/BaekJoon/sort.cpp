#include <iostream>
#include <vector>

#define CTR_SECURE_NO_WARNING

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

/*--------------------------------------------------------------------------*/

void Merge(vector<int>& array, vector<int>& sorted, int start, int middle, int end)
{
	int sortedIndex = start;
	int left = start;
	int right = middle + 1;

	while (left <= middle && right <= end)
	{
		if (array[left] < array[right])
			sorted[sortedIndex] = array[left++];
		else
			sorted[sortedIndex] = array[right++];

		sortedIndex++;
	}

	if (left > middle)
		for (; right <= end; right++, sortedIndex++)
			sorted[sortedIndex] = array[right];

	if (right > end)
		for (; left <= middle; left++, sortedIndex++)
			sorted[sortedIndex] = array[left];

	for (int i = 0; i <= end; i++)
		array[i] = sorted[i];
}

void Merge_Sort(vector<int>& array, vector<int>& sorted, int start, int end)
{
	int middle;
	if (start < end)
	{
		middle = (start + end) / 2;
		Merge_Sort(array, sorted, start, middle);
		Merge_Sort(array, sorted, middle + 1, end);
		Merge(array, sorted, start, middle, end);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	cin >> count;

	vector<int> v(count, 0);

	for (int i = 0; i < count; i++)
		cin >> v[i];

	vector<int> s(count, 0);

	Merge_Sort(v, s, 0, count - 1);

	for (int i = 0; i < count; i++)
		cout << v[i] << '\n';

	return 0;
}
