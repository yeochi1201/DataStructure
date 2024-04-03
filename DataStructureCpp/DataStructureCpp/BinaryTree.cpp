#include <iostream>
#include <stack>
using namespace std;

class node {
private:
	int content;
	node* rightChild;
	node* leftChild;
public:
	node() {
		SetContent(NULL);
		SetLeftChild(NULL);
		SetRightChild(NULL);
	}
	void SetRightChild(node* child) {
		rightChild = child;
	}

	void SetLeftChild(node* child) {
		leftChild = child;
	}

	void SetContent(int data) {
		content = data;
	}

	node* GetRightChild() {
		return rightChild;
	}

	node* GetLeftChild() {
		return leftChild;
	}

	int GetContent() {
		return content;
	}
};

class BinaryTree {
private:
	node* root;
	int depth;

public:
	BinaryTree(){
		root = new node();
	}

	int size(node* node) {
		if (node->GetContent() == NULL)return 0;
		return size(node->GetLeftChild()) + size(node->GetRightChild()) + 1;
	}

	int height(node* node) {
		if (node->GetContent() == NULL)return -1;
		return max(height(node->GetLeftChild()), height(node->GetRightChild())) + 1;
	}

	void Push(int content) {
		if (root->GetContent() == NULL) {
			root->SetContent(content);
			return;
		}
		node* temp = new node();
		temp->SetContent(content);

		int maxNode = 0;
		for (int i = 0; i < height(root); i++) {
			maxNode += pow(2, i);
		}
		int curNode = size(root);

		if (maxNode - curNode == 0) {
			node* ptr = root;
			while (ptr->GetLeftChild()==NULL) {
				ptr = ptr->GetLeftChild();
			}
			ptr->SetLeftChild(temp);
			return;
		}

		float pt = maxNode - curNode;
		float maxLeafNode = pow(2, height(root));
		node* ptr = root;
		for (int h = height(root); h > 1; h--) {
			if (maxLeafNode / 2 <= pt) {
				ptr = ptr->GetLeftChild();
				pt -= pow(2, height(ptr) - 1);
			}
			else {
				ptr = ptr->GetRightChild();
			}
			maxLeafNode /= 2;
		}
		if (pt == 2)ptr->SetLeftChild(temp);
		else ptr->SetRightChild(temp);
		return;
	}


};