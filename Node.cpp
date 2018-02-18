#include "stdafx.h"
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(const int data, const int dData)
{
	this->value = data;
	this->dData = dData;
}
Node::Node()
{
	int val;
	cout << "Введите значение узла двоичного дерева: ";
	cin >> val;
	cout << "\n";
	int dData;
	cout << "Введите какое-нибудь дополнительное значение узла: ";
	cin >> dData;
	cout << "\n";
}

int Node::getValue()
{
	if (this != NULL)
	{
		return value;
	}
	return NULL;
}

int Node::getData()
{
	if (dData)
	{
		return dData;
	}
	return -100001;
}

Node *& Node::getParent()
{
	return parent;
}

Node *& Node::getLeftChild()
{
	return this->leftChild;
}

Node *& Node::getRightChild()
{
	return this->rightChild;
}

void Node::setLeftChild(Node * node)
{
	this->leftChild = node;
}

void Node::setRightChild(Node * node)
{
	this->rightChild = node;
}

void Node::setParent(Node * node)
{
	parent = node;
}

void Node::deleteNode()
{
	setLeftChild(NULL);
	setRightChild(NULL);
	value = NULL;
	dData = NULL;
}

Node::~Node()
{
}
