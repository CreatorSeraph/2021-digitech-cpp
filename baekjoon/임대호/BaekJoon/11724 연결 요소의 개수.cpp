//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//class Node {
//public:
//    int idx;
//    bool visited;
//    queue<int> nodes;
//};
//
//vector<Node*> nodes;
//
//void BfsSearch(int start);
//
//int connectedComponentCount = 0;
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n, m;
//
//    cin >> n >> m;
//
//    nodes.resize(n);
//
//    for (int i = 0; i < n + 1; i++) {
//        Node* node = new Node();
//        node->idx = i;
//        node->visited = false;
//
//        nodes[i] = node;
//    }
//
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        cin >> a >> b;
//
//        nodes[a]->nodes.push(b);
//        nodes[b]->nodes.push(a);
//    }
//
//    for (int i = 1; i < n + 1; i++) {
//        if (!nodes[i]->visited)
//            BfsSearch(i);
//    }
//
//    cout << connectedComponentCount;
//
//    return 0;
//}
//
//void BfsSearch(int start) {
//    queue<int> searchList;
//    searchList.push(start);
//
//    while (!searchList.empty()) {
//        int next = searchList.front();
//        searchList.pop();
//
//        if (nodes[next]->visited)
//            continue;
//
//        nodes[next]->visited = true;
//
//        while (!nodes[next]->nodes.empty()) {
//            int child = nodes[next]->nodes.front();
//            nodes[next]->nodes.pop();
//
//            if (nodes[child]->visited)
//                continue;
//
//            searchList.push(child);
//        }
//    }
//
//    connectedComponentCount++;
//}