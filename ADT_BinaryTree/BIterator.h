#pragma once
#include "BinaryTree.h"
template <class T>
class BIterator {
public:
	virtual T* GoFirst(BinaryTree<T> &bt) = 0;
	virtual T* Next(void) = 0;
	virtual void Traverse(void (*Visit)(T& x),BinaryTree<T> &bt);	
protected:
	BTNode<T> *r, *current;
};

template<class T>
inline void BIterator<T>::Traverse(void (*Visit)(T &x),BinaryTree<T> &bt)
{
	T *p = GoFirst(bt);
	while (p) {
		Visit(*p);
		p = Next();
	}
}
template <class T>
void Visit(T& x) {
	cout << x << " ";
}
