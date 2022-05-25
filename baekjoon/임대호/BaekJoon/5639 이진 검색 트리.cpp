//#include <iostream>
//using namespace std;
//
//class Node
//{
//private:
//
//public:
//	Node() { value = 0; }
//	Node(Node* parent, int value) : parent(parent), value(value) {}
//
//	int value;
//
//	Node* left = nullptr;
//	Node* right = nullptr;
//	Node* parent;
//
//	void SetLeftChild(Node* left)
//	{
//		this->left = left;
//	}
//	void SetRightChild(Node* right)
//	{
//		this->right = right;
//	}
//};
//
//class BinaryTree
//{
//public:
//	Node* root;
//};
//
//void InsertNode(Node* node, int value);
//void PrintAllNode(Node* node);
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	BinaryTree* tree = new BinaryTree();
//	int n;
//
//	while (true)
//	{
//		cin >> n;
//		if (cin.eof()) break;
//
//		if ((*tree).root == nullptr)
//			(*tree).root = new Node(nullptr, n);
//		else
//		{
//			InsertNode((*tree).root, n);
//		}
//	}
//
//	PrintAllNode((*tree).root);
//	cout << (*tree).root->value;
//
//	return 0;
//}
//
//void InsertNode(Node* node, int value)
//{
//	if (value > node->value)
//	{
//		if (node->right != nullptr)
//		{
//			InsertNode(node->right, value);
//			return;
//		}
//		else
//			node->right = new Node(node, value);
//	}
//	else
//	{
//		if (node->left != nullptr)
//		{
//			InsertNode(node->left, value);
//			return;
//		}
//		else
//			node->left = new Node(node, value);
//	}
//}
//
//void PrintAllNode(Node* node)
//{
//	if (node->left && (node->left->left != nullptr || node->left->right != nullptr)) PrintAllNode(node->left);
//
//	if (node->left)
//		cout << node->left->value << '\n';
//
//	if (node->right && (node->right->left != nullptr || node->right->right != nullptr)) PrintAllNode(node->right);
//
//	if (node->right)
//		cout << node->right->value << '\n';
//}