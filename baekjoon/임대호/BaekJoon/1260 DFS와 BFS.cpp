#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>

using namespace std;

class Node {
public:
    int idx;
    priority_queue<int, vector<int>, greater<int> > nodes;
    bool visited;
};

vector<Node> nodes;
vector<Node> tempNodes;
list<int> visitList;

void DfsSearch(int start);
void BfsSearch(int start);
void PrintVisitList();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, v;

    cin >> n >> m >> v;

    nodes.resize(n + 1);
    tempNodes.resize(n + 1);

    for (int i = 0; i < n + 1; i++) {
        Node node;
        node.idx = i;
        node.visited = false;

        nodes[i] = node;
        tempNodes[i] = node;
    }

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        nodes[temp1].nodes.push(temp2);
        nodes[temp2].nodes.push(temp1);

        tempNodes[temp1].nodes.push(temp2);
        tempNodes[temp2].nodes.push(temp1);
    }

    DfsSearch(v);
    PrintVisitList();
    BfsSearch(v);
    PrintVisitList();

    return 0;
}

void DfsSearch(int start) {
    if (nodes[start].visited)
        return;

    nodes[start].visited = true;
    visitList.push_back(start);

    while (!nodes[start].nodes.empty()) {
        int next = nodes[start].nodes.top();
        nodes[start].nodes.pop();

        if (nodes[next].visited) {
            continue;
        }

        DfsSearch(next);
    }
}

void BfsSearch(int start) {
    queue<int> searchList;
    searchList.push(start);

    while (!searchList.empty()) {
        int next = searchList.front();
        searchList.pop();

        if (nodes[next].visited)
            continue;

        nodes[next].visited = true;
        visitList.push_back(next);

        while (!nodes[next].nodes.empty()) {
            int child = nodes[next].nodes.top();
            nodes[next].nodes.pop();

            if (nodes[child].visited)
                continue;

            searchList.push(child);
        }
    }
}

void PrintVisitList() {
    for (auto iter : visitList)
        cout << iter <<' ';
    cout << '\n';

    visitList.clear();

    nodes = tempNodes;
}