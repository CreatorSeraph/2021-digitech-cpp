//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//void Merge(int start, int mid, int end);
//void MergeSort(int start, int end);
//
//vector<string> v;
//vector<string> _v;
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//
//	map<string, int> m;
//	string s, temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s >> temp;
//
//		auto find = m.find(s);
//
//		if (find == m.end())
//			m.insert(make_pair(s, 0));
//		else
//			m.erase(find);
//	}
//
//	for (auto iter : m)
//	{
//		v.push_back(iter.first);
//	}
//	_v.resize(v.size());
//
//	MergeSort(0, m.size() - 1);
//
//	for (auto iter : v)
//		cout << iter << '\n';
//
//	return 0;
//}
//
//void Merge(int start, int mid, int end)
//{
//	int index = start;
//	int left = start;
//	int right = mid + 1;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left] > v[right])
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