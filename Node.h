#pragma once
class Node
{
private:
	int value;
	int dData;
	Node* leftChild = NULL;
	Node* rightChild = NULL;
	Node* parent = NULL;
public:
	Node(const int data, const int dData);
	Node();
	int getValue();
	int getData();
	Node*& getParent();
	Node*& getLeftChild();
	Node*& getRightChild();
	void setLeftChild(Node* node);
	void setRightChild(Node* node);
	void setParent(Node* node);
	void deleteNode();
	~Node();
};
