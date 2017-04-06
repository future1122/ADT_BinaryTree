// ADT_BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"BinaryTree.h"
#include "IInOrder.h"
int main()
{
	BinaryTree<char> a, b, x, y, z;
	y.MakeTree('E', a, b);
	x.MakeTree('F', a, b);
	z.MakeTree('Z', x, y);
	x.MakeTree('x', a, b);
	a.MakeTree('a', z, x);
	a.InOrder(Visit);
	cout << endl;
	IInOrder<char> order(a);
	order.Traverse(Visit,a);
    return 0;
}




