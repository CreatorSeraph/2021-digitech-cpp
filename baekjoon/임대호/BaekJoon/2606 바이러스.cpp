#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
    int value;
    list<Node*> nodes;
};

set<int> inflectedNodes;
void inflecting(Node* node) {
    if (inflectedNodes.find(node->value) != inflectedNodes.end())
        return;

    inflectedNodes.insert(node->value);

    for (auto iter = node->nodes.begin(); iter != node->nodes.end(); ++iter) {
        inflecting(*iter);
    }

    node->nodes.clear();
}

int 바이러스() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Node*> nodes(n);

    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
        nodes[i]->value = i + 1;
    }

    int m;
    cin >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        nodes[a - 1]->nodes.push_back(nodes[b - 1]);
        nodes[b - 1]->nodes.push_back(nodes[a - 1]);
    }

    Node* node = nodes[0];
    inflecting(node);

    cout << inflectedNodes.size() - 1;

    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        delete *iter;
    }
    nodes.clear();

    return 0;
}
