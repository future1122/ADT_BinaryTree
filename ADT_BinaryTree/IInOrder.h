#pragma once
#include <stack>
#include "BIterator.h"
template <class T>
class IInOrder : public BIterator<T> {
public:
	IInOrder(BinaryTree<T> &bt) {
		r = bt.root;
		s = new stack<BTNode<T>* >();
	}
	T *GoFirst(BinaryTree<T> &bt);
	T *Next(void);
private:
	stack<BTNode<T>* > *s;
};

template<class T>
inline T * IInOrder<T>::GoFirst(BinaryTree<T> &bt)
{
	current = bt.root;
	if (!current) return nullptr;
	while (current->lchild) {
		s->push(current);
		current = current->lchild;
	}
	return &current->element;
}

template<class T>
inline T * IInOrder<T>::Next(void)
{
	BTNode < T> *p;
	if (current->rchild != nullptr) {
		p = current->rchild;
		while (p->lchild) {
			s->push(p);
			p = p->lchild;
		}
		current = p;
	}
	else if (!s->empty()) {
		current = s->top();
		s->pop();
	}
	else {
		current = nullptr;
		return nullptr;
	}
	return &current->element;
}
