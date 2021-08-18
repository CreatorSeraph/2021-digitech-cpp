#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

using ll = long long;
using ul = unsigned long;
using mc_cp = map<char, char*>;
using mc_pc_c = map<char, pair<char, char>>;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void Pr(mc_pc_c& tree, char node)
{
	if (tree.find(node) != tree.end())
	{
		if (node != '.')
			cout << node;
		Pr(tree, tree[node].first);
		Pr(tree, tree[node].second);
	}
}

void In(mc_pc_c& tree, char node)
{
	if (tree.find(node) != tree.end())
	{
		In(tree, tree[node].first);
		if (node != '.')
			cout << node;
		In(tree, tree[node].second);
	}
}

void Po(mc_pc_c& tree, char node)
{
	if (tree.find(node) != tree.end())
	{
		Po(tree, tree[node].first);
		Po(tree, tree[node].second);
		if (node != '.')
			cout << node;
	}
}

int main()
{
	int N;
	cin >> N;

	mc_pc_c tree;

	char node, l_node, r_node;

	for (size_t i = 0; i < N; i++)
	{
		cin >> node >> l_node >> r_node;
		tree[node] = { l_node,r_node };
	}

	Pr(tree, 'A');
	cout << "\n";
	In(tree, 'A');
	cout << "\n";
	Po(tree, 'A');
	cout << "\n";

	return 0;
}