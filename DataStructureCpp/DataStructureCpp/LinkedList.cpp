#include <iostream>

using namespace std;


class Node {
private:
	Node* link;
	int content;
public:
	Node(int content = NULL, Node* link = NULL) {
		this->content = content;
		this->link = link;
	}

	void SetContent(int content) {
		this->content = content;
	}

	void SetLink(Node* nextNode) {
		this->link = nextNode;
	}

	bool Empty() {
		if (this->content == NULL)return true;
		else return false;
	}

	Node* GetLink() {
		return this->link;
	}

	int GetContent() {
		return this->content;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int count;
public:
	LinkedList() {
		this->head = GenerateNode();
		this->tail = this->head;
	}

	Node* GenerateNode(int content = NULL) {
		Node* temp = new Node(content, NULL);
		return temp;
	}

	void Push(int content) {
		if (head->Empty()) {
			head->SetContent(content);
		}
		else {
			Node* temp = GenerateNode(content);
			tail->SetLink(temp);
			tail = temp;
		}
	}

	bool Find(int content) {
		Node* ptr = head;
		int temp;
		while (ptr != NULL) {
			temp = ptr->GetContent();
			if (temp == content)
				return true;
		}
		return false;
	}

	void Delete(int content) {
		Node* ptr = head;
		Node* prev;
		Node* next;
		int temp;
		while (ptr != NULL) {
			temp = ptr->GetContent();
			prev = ptr;
			ptr = ptr->GetLink();
			if (temp == content) {
				next = ptr->GetLink();
				prev->SetLink(next);
				delete ptr;
				return;
			}	
		}
		return;
	}
};