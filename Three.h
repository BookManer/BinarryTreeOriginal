#pragma once
#include "Node.h" 
class Three
{
public:
	Node* root;
	int countNodes = 0;
	Three();
	~Three();
	void addNode(int value, int dData);
	void display(Node* node);
	Node* search(int value);
	void deleteNode(int value);
};
