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
	int len; //��ǰ���string�ĳ���+1��+1�����ж�
	char *key; //��ǰ����string
	Node* child; //���ӽڵ�
	Node* brother; //��һ���ֵܽڵ�
	bool leaf;
	Node() :key(NULL), len(0), child(NULL), brother(NULL),leaf(true) {};
	Node(char *x, int n) :len(n), child(NULL), brother(NULL),leaf(true) {
		key = new char[n];
		strncpy(key, x - n, n);
		key = key + n;
	}
	~Node() {
		delete[] key;
	}
};
#endif