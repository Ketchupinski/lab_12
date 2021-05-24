#include <iostream>
using namespace std;
typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
};
Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
void PrefixOrder(Node* root, Info x, bool& answ);

int main()
{
	int N;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	PrintTree(root, 0);
	int k;
	cout << "Input k: "; cin >> k;
	bool answ = false;
	PrefixOrder(root, k, answ);
	if (answ == true) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}
Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;
		cout << " Enter node value: ";
		cin >> newNode->info;
		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
		cout << root->info << endl;
		PrintTree(root->left, level + 1);
	}
}

void PrefixOrder(Node* root, Info x, bool& answ)
{
	if (root != NULL)
	{
		if (root->info == x) {
			answ = true;
			return;
		}
		PrefixOrder(root->left, x, answ);
		PrefixOrder(root->right, x, answ);
	}
}