//#include <iostream>
//#include <list>
//#include <vector>
//#include <unordered_map>
//#include <math.h>
//
//using namespace std;
//
//void Merge(vector<int>& v, vector<int>& _v, int start, int mid, int end)
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
//	else if (right > end)
//		while (left <= mid)
//			_v[index++] = v[left++];
//
//	for (int i = start; i <= end; i++)
//		v[i] = _v[i];
//}
//
//void MegeSort(vector<int>& v, vector<int>& _v, int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (start + end) / 2;
//
//	MegeSort(v, _v, start, mid);
//	MegeSort(v, _v, mid + 1, end);
//	Merge(v, _v, start, mid, end);
//}
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
//	vector<int> v(n);
//	vector<int> _v = v;
//
//	int sum = 0, max_count = 1, max_value = 0;
//	bool several = false;
//
//	unordered_map<int, int> m;
//	list<int> l;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//		sum += v[i];
//
//		auto find = m.find(v[i]);
//
//		if (find != m.end())
//		{
//			int count = find->second + 1;
//
//			m[v[i]] = count;
//
//			if (count > max_count)
//			{
//				several = false;
//				max_value = find->first;
//				max_count = count;
//				l.clear();
//				l.push_back(find->first);
//			}
//			else if (count == max_count)
//			{
//				several = true;
//				l.push_back(find->first);
//			}
//
//		}
//		else
//		{
//			m.insert(make_pair(v[i], 1));
//
//			if (max_count == 1)
//			{
//				several = true;
//				max_value = v[i];
//				l.push_back(v[i]);
//			}
//		}
//	}
//
//	if (several && l.size() > 1)
//		l.sort();
//
//	MegeSort(v, _v, 0, n - 1);
//
//
//	// Æò±Õ
//	cout << (int)round(sum / (float)n) << '\n';
//
//	// Áß¾Ó°ª
//	cout << v[(int)(n / 2)] << '\n';
//
//	// ÃÖºó°ª
//	if (several && l.size() > 1)
//		cout << *(++l.begin()) << '\n';
//	else
//		cout << max_value << '\n';
//
//	// ¹üÀ§
//	cout << v[n - 1] - v[0];
//
//
//	return 0;
//}