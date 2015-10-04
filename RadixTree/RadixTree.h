#ifndef _RADIX_TREE_
#define _RADIX_TREE_
#include<iostream>
using namespace std;
struct Node {
	int len; //��ǰ���string�ĳ���+1��+1�����ж�
	char *key; //��ǰ����string
	Node* child; //���ӽڵ�
	Node* brother; //��һ���ֵܽڵ�
	bool leaf;
	Node() :key(NULL), len(0), child(NULL), brother(NULL),leaf(true) {};
	Node(char *x, int n) :len(n), child(NULL), brother(NULL),leaf(true) {
		key = x;
	}
};
#endif