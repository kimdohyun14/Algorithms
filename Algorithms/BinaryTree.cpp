#include <iostream>
using namespace std;

// �ϳ��� ��� ������ �����Ѵ�.
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ
void preorder(treePointer ptr) {
	if (ptr) { //ptr�� null ���� �ƴ϶��
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[16];
	for (int i = 1; i <= 15; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= 15; i++) { // ��ǻ� 1�� �ǹ̾��Եȴ�.
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]); cout << endl;
	inorder(&nodes[1]); cout << endl;
	postorder(&nodes[1]); cout << endl;
	return 0;
}