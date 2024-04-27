//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <climits>
//
//using namespace std;
//
//vector<int> arr;
//
//int nextInsertIdx = 0;
//
//void byInsert(int idx) {
//    if (idx == 0)
//        return;
//
//    int rootIdx = (idx + 1) / 2 - 1;
//
//    if (arr[rootIdx] < arr[idx]) {
//        int temp = arr[rootIdx];
//        arr[rootIdx] = arr[idx];
//        arr[idx] = temp;
//
//        byInsert(rootIdx);
//    }
//}
//
//void byRemoveMax(int idx) {
//    int left = (idx + 1) * 2 - 1;
//    int right = (idx + 1) * 2;
//
//    // 자식 노드 없을 때
//    if (left >= nextInsertIdx && right >= nextInsertIdx)
//        return;
//
//    // 왼쪽 노드만 존재할 때, 대소 비교
//    if (right >= nextInsertIdx && arr[left] <= arr[idx])
//        return;
//
//    if (arr[idx] > arr[left] && arr[idx] > arr[right])
//        return;
//
//    int maxIdx = 0;
//    if (arr[left] > arr[right])
//        maxIdx = left;
//    else
//        maxIdx = right;
//
//    int temp = arr[maxIdx];
//    arr[maxIdx] = arr[idx];
//    arr[idx] = temp;
//
//    byRemoveMax(maxIdx);
//}
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int nextDepth = 1;
//
//    int t, k, startIdx, min, minIdx;
//    cin >> t;
//
//    char c;
//    int v;
//
//    arr.resize(1000001);
//
//    for (int i = 0; i < t; i++) {
//        cin >> k;
//
//        nextDepth = 1;
//        nextInsertIdx = 0;
//
//        for (int j = 0; j < k; j++) {
//            cin >> c >> v;
//
//            if (c == 'I') {
//                arr[nextInsertIdx++] = v;
//
//                byInsert(nextInsertIdx - 1);
//
//                if (nextDepth == 0 || nextInsertIdx == pow(2, nextDepth) - 1)
//                    nextDepth++;
//            } else if (c == 'D') {
//                if (nextInsertIdx == 0)
//                    continue;
//
//                nextInsertIdx--;
//
//                if (v == 1) {
//                    arr[0] = arr[nextInsertIdx];
//                    arr[nextInsertIdx] = 0;
//                    byRemoveMax(0);
//                } else if (v == -1) {
//                    min = INT_MAX;
//                    minIdx = -1;
//                    for (int k_ = nextInsertIdx; k_ ; k_--) {
//                        if (arr[k_] < min) {
//                            min = arr[k_];
//                            minIdx = k_;
//                        }
//                    }
//
//                    if (minIdx != -1) {
//                        for (; minIdx < nextInsertIdx; minIdx++) {
//                            arr[minIdx] = arr[minIdx + 1];
//                        }
//                    }
//                }
//            }
//        }
//
//        if (nextInsertIdx == 0)
//            cout << "EMPTY" << '\n';
//        else {
//            min = INT_MAX;
//            for (int j = 0; j < nextInsertIdx; j++) {
//                if (arr[j] < min) {
//                    min = arr[j];
//                }
//            }
//
//            cout << arr[0] << ' ' << min << '\n';
//        }
//    }
//
//    return 0;
//}
//
