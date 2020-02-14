#include <iostream>
#include <cstdlib>
using namespace std;

// ����Ʈ��
typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}BTreeNode;

// ���� Ʈ�� ��带 �����ؼ� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* MakeBTreeNode()
{
	BTreeNode* tree_node = (BTreeNode*)malloc(sizeof(BTreeNode));
	tree_node->left = NULL;
	tree_node->right = NULL;
	return tree_node;
}

// �ش� Ʈ���� �Ҹ�
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	cout << "free data: " << bt->data << endl;
	free(bt);
}

// ���� ����Ʈ�� �ּ� ��ȯ
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

// ������ ����Ʈ�� �ּ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

// ���� ����Ʈ�� �̾� ���̱�
void MakeLeftSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->left != NULL)
	{
		DeleteTree(root->left);
	}

	root->left = sub;
}

// ������ ����Ʈ�� �̾� ���̱�.
void MakeRightSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->right != NULL)
	{
		DeleteTree(root->right);
	}

	root->right = sub;
}

// ��忡 ����� �����͸� ��ȯ�Ѵ�.
int GetData(BTreeNode* bt)
{
	return bt->data;
}

// ��忡 data�� ���޵� ���� �����Ѵ�.
void SetData(BTreeNode* bt, int data)
{
	bt->data = data;
}

// ������ȸ
void inorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		inorder_traversal(bt->left);
		cout << bt->data << ' ';
		inorder_traversal(bt->right);
	}
}

// ������ȸ
void preorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		cout << bt->data << ' ';
		preorder_traversal(bt->left);
		preorder_traversal(bt->right);
	}
}

// ������ȸ
void postorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		postorder_traversal(bt->left);
		postorder_traversal(bt->right);
		cout << bt->data << ' ';
	}
}

int main()
{
	BTreeNode* root = MakeBTreeNode();
	SetData(root, 0);
	BTreeNode* node1 = MakeBTreeNode();
	SetData(node1, 1);
	BTreeNode* node2 = MakeBTreeNode();
	SetData(node2, 2);
	BTreeNode* node3 = MakeBTreeNode();
	SetData(node3, 3);
	BTreeNode* node4 = MakeBTreeNode();
	SetData(node4, 4);

	MakeLeftSubTree(root, node1);
	MakeRightSubTree(root, node2);
	MakeLeftSubTree(node1, node3);
	MakeRightSubTree(node1, node4);

	cout << "���� ��ȸ: "; inorder_traversal(root); cout << endl;
	cout << "���� ��ȸ: "; preorder_traversal(root); cout << endl;
	cout << "���� ��ȸ : "; postorder_traversal(root); cout << endl;

	BTreeNode* node5 = MakeBTreeNode();
	BTreeNode* node6 = MakeBTreeNode();
	BTreeNode* node7 = MakeBTreeNode();
	SetData(node5, 7);
	SetData(node6, 8);
	SetData(node7, 9);

	MakeLeftSubTree(node5, node6);
	MakeRightSubTree(node5, node7);

	// ������ root�� ���� ����Ʈ���� �ٲ۴�.
	MakeLeftSubTree(root, node5);

	cout << "���� ��ȸ: "; inorder_traversal(root); cout << endl;
	cout << "���� ��ȸ: "; preorder_traversal(root); cout << endl;
	cout << "���� ��ȸ : "; postorder_traversal(root); cout << endl;
	return 0;
}