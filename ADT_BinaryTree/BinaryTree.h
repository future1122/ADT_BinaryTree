#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BTNode {
	BTNode() { lchild = nullptr; rchild = nullptr; }
	BTNode(const T &x) {
		element = x;
		lchild = nullptr;
		rchild = nullptr;
	}
	BTNode(const T &x, BTNode<T> *l, BTNode<T> *r) {
		element = x;
		lchild = l;
		rchild = r;
	}
	T element;
	BTNode<T>* lchild;
	BTNode<T>* rchild;
};

template <class T>
class BinaryTree {
public:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {
		Clear(root);
	}
	bool MakeTree(const T &x, BinaryTree<T> & left, BinaryTree<T>& right);
	bool BreakTree(T& x, BinaryTree<T>& left, BinaryTree<T> & right);
	bool IsEmpty() const;
	bool Root(T& x)const;
	void PreOrder(void(*Visit)(T& x)) { PreOrder(Visit, root); }
	void InOrder(void(*Visit)(T& x)) { InOrder(Visit, root); }
	void PostOrder(void(*Visit)(T& x)) { PostOrder(Visit, root); }
protected:
	BTNode<T>* root;
private:
	void Clear(BTNode<T> *& t);
	void PreOrder(void(*Visit)(T& x), BTNode<T> *t);
	void InOrder(void(*Visit)(T& x),BTNode<T> *t);
	void PostOrder(void(*Visit)(T& x),BTNode<T> *t);

};

template<class T>
inline bool BinaryTree<T>::MakeTree(const T & x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (root || &left == &right) return false;
	root = new BTNode<T>(x, left.root, right.root);
	left.root = nullptr;
	right.root = nullptr;
	return true;
}

template<class T>
inline bool BinaryTree<T>::BreakTree(T & x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (!root || &left == &right || left.root || left.root) return false;
	x = root->element;
	left.root = root->lchild;
	right.root = root->rchild;
	delete root;
	root = nullptr;
	return true;
}

template<class T>
inline bool BinaryTree<T>::IsEmpty() const
{
	if (root) return true;
	return false;
}

template<class T>
inline bool BinaryTree<T>::Root(T & x) const
{
	if (root) {
		x = root->element;
		return true;
	}
	return false;
}
template<class T>
inline void BinaryTree<T>::Clear(BTNode<T>*& t)
{
	if (t) {
		Clear(t->lchild);
		Clear(t->rchild);
		delete t;
		t = nullptr;
	}
}
template<class T>
inline void BinaryTree<T>::PreOrder(void(*Visit)(T &x), BTNode<T>* t)
{
	if (t) {
		Visit(t->element);
		PreOrder(Visit, t->lchild);
		PreOrder(Visit, t->rchild);
	}
}
template<class T>
inline void BinaryTree<T>::InOrder(void(*Visit)(T &x), BTNode<T>* t)
{
	if (t) {
		InOrder(Visit, t->lchild);
		Visit(t->element);
		InOrder(Visit, t->rchild);
	}
}
template<class T>
inline void BinaryTree<T>::PostOrder(void(*Visit)(T &x), BTNode<T>* t)
{
	if (t) {
		PostOrder(Visit, t->lchild);
		PostOrder(Visit, t->rchild);
		Visit(t->element);
	}
}

template <class T>
void Visit(T& x) {
	cout << x << " ";
}
