// ADT_BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"BinaryTree.h"

int main()
{
	BinaryTree<char> a, b, x, y, z;
	y.MakeTree('E', a, b);
	x.MakeTree('F', a, b);
	z.MakeTree('Z', x, y);
	x.MakeTree('x', a, b);
	a.MakeTree('a', z, x);
	a.InOrder(Visit);
    return 0;
}


