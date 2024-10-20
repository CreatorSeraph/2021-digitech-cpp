//#include <iostream>
//#include <queue>
//#include <vector>
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
//vector<Node> nodes;
//vector<vector<int> > distResult;
//
//int DFSSearch(int first, int fromIdx, int startIdx, int goalIdx, vector<vector<int> >& distTable, int dist);
//
//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<int> > distTable(n, vector<int>(n));
//
//    nodes.resize(n);
//    vector<Node> tempNodes(n);
//
//    distResult.resize(n);
//
//    for (int i = 0; i < n; i++) {
//        distResult[i].resize(n);
//
//        for (int j = 0; j < n; j++)
//            distResult[i][j] = 100000001;
//
//        Node node;
//        node.idx = i;
//        node.visited = false;
//
//        nodes[i] = node;
//        tempNodes[i] = node;
//    }
//
//
//    int a, b, dist;
//    for (int i = 0; i < n - 1; i++) {
//        cin >> a >> b >> dist;
//
//        nodes[a - 1].nodes.push(b - 1);
//        nodes[b - 1].nodes.push(a - 1);
//
//        tempNodes[a - 1].nodes.push(b - 1);
//        tempNodes[b - 1].nodes.push(a - 1);
//
//        distTable[a - 1][b - 1] = dist;
//        distTable[b - 1][a - 1] = dist;
//    }
//
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b;
//
//        int ret = DFSSearch(a - 1, 0, a - 1, b - 1, distTable, 0);
//        cout << distResult[a - 1][b - 1] << '\n';
//
//        nodes = tempNodes;
//    }
//
//
//    return 0;
//}
//
//int DFSSearch(int first, int fromIdx, int startIdx, int goalIdx, vector<vector<int> >& distTable, int dist) {
//    auto start = &nodes[startIdx];
//    auto from = &nodes[fromIdx];
//
//    if (start->visited)
//        return dist - distTable[from->idx][startIdx];
//
//    start->visited = true;
//
//    if (start->nodes.empty()) {
//        dist -= distTable[from->idx][start->idx];
//    } else {
//        while (!start->nodes.empty()) {
//            int target = start->nodes.front();
//            start->nodes.pop();
//
//            dist = dist + distTable[start->idx][target];
//
//            Node goal = nodes[goalIdx];
//
//            // 탐색 완료
//            if (target == goal.idx) {
//                if (distResult[first][goalIdx] > dist)
//                    distResult[first][goalIdx] = dist;
//            }
//
//            dist = DFSSearch(first, start->idx, target, goalIdx, distTable, dist);
//        }
//    }
//
//    return dist - distTable[from->idx][startIdx];
//}
