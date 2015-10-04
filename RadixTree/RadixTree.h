#ifndef _RADIX_TREE_
#define _RADIX_TREE_
#include<iostream>
using namespace std;
struct Node {
	int len; //当前结点string的长度+1，+1可以判断
	char *key; //当前结点的string
	Node* child; //孩子节点
	Node* brother; //下一个兄弟节点
	bool leaf;
	Node() :key(NULL), len(0), child(NULL), brother(NULL),leaf(true) {};
	Node(char *x, int n) :len(n), child(NULL), brother(NULL),leaf(true) {
		key = x;
	}
};
#endif