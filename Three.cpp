#include "stdafx.h"
#include "Three.h"
#include <iostream>

using namespace std;

Three::Three()
{
	cout << "Дерево создано!!!" << endl;
}


Three::~Three()
{
}

void Three::addNode(int value, int dData)
{
	if (countNodes == 0)
	{
		root = new Node(value, dData);
		root->setParent(NULL);
		countNodes++;
		return;
	}
	Node* current = root;
	int c = 0;
	while (true)
	{
		Node* tmp = current;
		if (value > tmp->getValue())
		{
			if (current->getRightChild() == NULL)
			{
				cout << value << " - правый потомок родителя " << current->getValue() << endl;
				Node* newNode = new Node(value, dData);
				current->setRightChild(newNode);
				current->getRightChild()->setParent(current);
				current = current->getRightChild();
				countNodes++;
				return;
			}
			current = current->getRightChild();
			c++;
		}
		if (value < tmp->getValue())
		{	
			if (current->getLeftChild() == NULL)
			{
				cout << value << " - левый потомок родителя " << current->getValue() << endl;
				Node* newNode = new Node(value, dData);
				current->setLeftChild(newNode);
				current->getLeftChild()->setParent(current);
				current = current->getLeftChild();
				countNodes++;
				return;
			}
			current = current->getLeftChild();
			c++;
		}
	}
}

void Three::display(Node * node)
{
	cout << (node != NULL ? node->getValue() : 0) << endl;
	if (node->getLeftChild() != NULL)
	{
		display(node->getLeftChild());
	}
	if (node->getRightChild() != NULL)
	{
		display(node->getRightChild());
	}
}

Node * Three::search(int value)
{
	if (countNodes == 0)
	{
		return NULL;
	}
	Node* current = root;
	while (true)
	{
		if (value < current->getValue())
		{
			current = current->getLeftChild();
		}
		if (value > current->getValue())
		{
			current = current->getRightChild();
		}
		if (value == current->getValue())
		{
			return current;
		}
	}
	return NULL;
}

void Three::deleteNode(int value)
{
	Node* current = search(value);
	if (current == root)
	{
		cout << "ERROR001: Нельзя удалять корень дерева, для этого выйдите из программы и занова её запустите!!!" << endl;
		return;
	}
	int isLeft = current->getLeftChild() != NULL ? 1 : 0;
	int countChild = isLeft + (current->getRightChild() != NULL ? 1 : 0);
	cout << countChild << endl;
	if (countChild == 0)
	{
		if (current->getParent() != NULL)
		{
			current->getParent()->getLeftChild() != NULL ? current->getParent()->setLeftChild(NULL) : current->getParent()->setRightChild(NULL);
		}
		return;
	}
	else if (countChild == 1)
	{
		if (isLeft)//если имеет одного левого потомка, то
		{
			Node* leftChild = current->getLeftChild();
			leftChild->setParent(current->getParent());
			current->setLeftChild(NULL);
			if (current->getParent()->getLeftChild()->getValue() == current->getValue())
			{
				current->getParent()->setLeftChild(leftChild);
				current->setParent(leftChild->getParent());
			}
			else
			{
				current->getParent()->setRightChild(leftChild);
				current->setParent(leftChild->getParent());
			}
			return;
		}
		else // иначе, если имеет одного правого потомка
		{
			Node* rightChild = current->getRightChild();
			current->setLeftChild(NULL);
			rightChild->setParent(current->getParent());
			if (current->getParent()->getLeftChild()->getValue() == current->getValue())
			{
				current->getParent()->setLeftChild(rightChild);
				current->setParent(rightChild->getParent());
			}
			else
			{
				current->getParent()->setRightChild(rightChild);
				current->setParent(rightChild->getParent());
			}
			return;
		}
	}
	else if (countChild == 2)//если удаляемый узел имеет два потомка(можно вешатся, потому как здесь будет адски дох@@я говнокода)
	{
		Node* receiver = current->getRightChild();
		if (receiver->getLeftChild() == NULL)
		{
			Node* tmp = current->getRightChild();
			tmp->setParent(current->getParent());
			tmp->setLeftChild(current->getLeftChild());
			current->setRightChild(NULL);
			//current->getParent()->setRightChild(tmp);
			if (current->getParent()->getLeftChild()->getValue() == current->getValue())
			{
				current->getParent()->setLeftChild(tmp);
			}
			else
			{
				current->getParent()->setRightChild(tmp);
			}
			return;
		}
		Node* tmp = receiver;
		while (tmp->getLeftChild() != NULL)
		{
			tmp = tmp->getLeftChild();
		}
		Node* tmps = tmp->getParent()->getLeftChild();
		tmp->getParent()->setLeftChild(NULL);
		tmps->setParent(current->getParent());
		tmps->setRightChild(current->getRightChild());
		//current->getParent()->setRightChild(tmps);
		if (current->getParent()->getLeftChild()->getValue() == current->getValue())
		{
			current->getParent()->setLeftChild(tmps);
		}
		else
		{
			current->getParent()->setRightChild(tmps);
		}
		return;
	}
}

