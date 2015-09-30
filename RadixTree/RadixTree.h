#ifndef _RADIX_TREE_
#define _RADIX_TREE_
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <map>
using namespace std;
struct Node {
	int len; //当前结点string的长度+1，+1可以判断
	char *key; //当前结点的string
	Node* child; //孩子节点
	Node* brother; //下一个兄弟节点
	Node() :key(NULL), len(0), child(NULL), brother(NULL) {};
	Node(char *x, int n) :len(n), child(NULL), brother(NULL) {
		key = new char[n];
		strncpy(key, x, n);
	}
	~Node() {
		delete[] key;
	}
};
#endif