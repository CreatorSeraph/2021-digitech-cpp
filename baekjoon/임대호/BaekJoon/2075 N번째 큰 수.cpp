//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//vector<int> v;
//
////void QuickSort(int start, int end)
////{
////	if (start >= end) return;
////
////	int left = start;
////	int right = end;
////	int pivot = start;
////	int temp;
////
////	while (left <= right)
////	{
////		while (left < end && v[left] >= v[pivot])left++;
////		while (right > start && v[right] <= v[pivot]) right--;
////
////		if (left <= right)
////		{
////			temp = v[left];
////			v[left] = v[right];
////			v[right] = temp;
////		}
////
////		temp = v[pivot];
////		v[pivot] = v[right];
////		v[right] = temp;
////
////		QuickSort(start, right - 1);
////		QuickSort(right + 1, end);
////	}
////}
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	int n;
//
//	cin >> n;
//
//	v.resize(n * n);
//
//	for (int i = 0; i < n * n; i++)
//	{
//		cin >> v[i];
//	}
//
//	// QuickSort(0, n * n - 1); STL sort´Â ÃÖ°í¾ß ÈæÈæ
//	sort(v.begin(), v.end(), greater<>());
//
//	cout << v[n - 1];
//
//	return 0;
//}
