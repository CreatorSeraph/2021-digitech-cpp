//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<int> v;
//vector<int> _v;
//
//void Merge(int start, int mid, int end)
//{
//	int index = start;
//	int left = start;
//	int right = mid + 1;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left] < v[right])
//			_v[index] = v[left++];
//		else
//			_v[index] = v[right++];
//
//		index++;
//	}
//
//	if (left > mid)
//		while (right <= end)
//			_v[index++] = v[right++];
//
//	else
//		while (left <= mid)
//			_v[index++] = v[left++];
//
//	for (int i = start; i <= end; i++)
//		v[i] = _v[i];
//}
//
//void MergeSort(int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (start + end) / 2;
//
//	MergeSort(start, mid);
//	MergeSort(mid + 1, end);
//	Merge(start, mid, end);
//}
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n, m, temp;
//	map<int, int> _m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		_m.insert(make_pair(temp, 0));
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp;
//
//		auto find = _m.find(temp);
//		if (find != _m.end())
//		{
//			_m.erase(find);
//		}
//	}
//
//
//	if (_m.empty())
//	{
//		cout << 0;
//		return 0;
//	}
//
//	for (auto iter : _m)
//		v.push_back(iter.first);
//	_v.resize(v.size());
//
//	MergeSort(0, v.size() - 1);
//
//	cout << v.size() << '\n';
//	for (auto iter : v)
//		cout << iter << ' ';
//
//	return 0;
//}