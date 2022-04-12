// 다른 프로젝트에서 하고 코드 옮기자 ㅋㅋ
#include <iostream>
#include <vector>

using namespace std;

struct Human
{
public:
	Human() {}
	Human(int _age, string _name, int _count) : age(_age), name(_name), count(_count) {}
	int age;
	string name;
	int count;
};

vector<Human> vec;
vector<Human> _vec;

void Merge(int start, int mid, int end);
void MergeSort(int start, int end);

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, age;
	string name;
	cin >> n;

	vec.resize(n);
	_vec.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> age;
		cin >> name;

		vec[i] = Human(age, name, i);
	}

	MergeSort(0, n - 1);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].age << ' ' << vec[i].name << '\n';
	}

	return 0;
}

void Merge(int start, int mid, int end)
{
	int index = start;
	int left = start;
	int right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (vec[left].age > vec[right].age) _vec[index] = vec[left++];
		else if (vec[left].age < vec[right].age) _vec[index] = vec[right++];
		else
		{
			if (vec[left].count < vec[right].count) _vec[index] = vec[left++];
			else vec[index] = _vec[right++];
		}
	}

	if (left > mid)
		while (right <= end)
			_vec[index++] = vec[right++];

	else if (right > end)
		while (left <= mid)
			_vec[index++] = vec[left++];

	for (int i = start; i <= end; i++)
		vec[i] = _vec[i];
}

void MergeSort(int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;

	MergeSort(start, mid);
	MergeSort(mid + 1, end);
	Merge(start, mid, end);
}
