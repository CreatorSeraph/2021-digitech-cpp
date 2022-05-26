//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Merge(vector<int>& v, int start, int mid, int end);
//void MergeSort(vector<int>& v, int start, int end);
//
//vector<int> _v;
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
//	_v = v;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	MergeSort(v, 0, n - 1);
//
//	for (int i = 0; i < n; i++)
//		cout << v[i] << '\n';
//
//	return 0;
//}
//
//void Merge(vector<int>& v, int start, int mid, int end)
//{
//	int index = start;
//	int left = start;
//	int right = mid + 1;
//
//	while (left <= mid && right <= end)
//	{
//		if (v[left] < v[right]) _v[index] = v[left++];
//		else _v[index] = v[right++];
//		index++;
//	}
//
//	while (left <= mid) _v[index++] = v[left++];
//	while (right <= end) _v[index++] = v[right++];
//
//	for (int i = start; i <= end; i++)
//		v[i] = _v[i];
//}
//
//void MergeSort(vector<int>& v, int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (start + end) / 2;
//
//	MergeSort(v, start, mid);
//	MergeSort(v, mid + 1, end);
//	Merge(v, start, mid, end);
//}