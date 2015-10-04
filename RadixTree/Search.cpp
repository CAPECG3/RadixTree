#include <cstdlib>
#include <cstdio>
#include <cstring>
#include"RadixTree.h"
#include"Search.h"
int Search::prefix(char* x, int n, char* key, int m) {
	//找x和key的公共后缀
	int k = 0;
	for ( ;k<n && k<m; k++) {
		if (*(x - k - 1) != *(key - k - 1)) {
			return k;
		}
	}
	return k;
}
Node* Search::find(Node* t, char* x, int n) {
	if (!t) return NULL;
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) return find(t->brother, x, n); //继续寻找兄弟节点
	if (k == n && k == t->len && t->leaf) return t;
	if (k == t->len) return find(t->child, x - k, n - k); // 前缀匹配成功,寻找孩子节点
	return NULL;
}
void Search::split(Node* t, int k) {
	//当前key和当前结点有公共后缀,需要分割节点
	Node* p = new Node();
	p->key = t->key - k;
	p->len = t->len - k;
	//Node* p = new Node(t->key - k, t->len - k);
	p->child = t->child;
	t->child = p;
	t->len = k;
	t->leaf = false;
}
Node* Search::insert(Node* t, char* x, int n) {
	if (!t) return new Node(x, n);
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) t->brother = insert(t->brother, x, n);
	else if (k<=n)
	{
		if (k < t->len) {
			split(t, k);
		}
		if (k == n) {
			//此判断的意思是新加入string即是trie树已经存在的非叶节点
			t->leaf = true;
		}
		else {
			t->child = insert(t->child, x - k, n - k);
		}
	}
	return t;
}
void Search::trieCheck(ifstream &fpStrPool, ifstream &fpCheckedStr, ofstream &fpResult) {
	Node *root = new Node();
	char s[320];
	while (fpStrPool >> s) {
		int len = strlen(s);
		insert(root, s+len, len);
	}
	int yesCount = 0; //统计yes的个数
	while (fpCheckedStr >> s) {
		int len = strlen(s);
		if (!find(root, s + len, len)) {
			fpResult << "no" << endl;
		}
		else {
			yesCount++;
			fpResult << "yes" << endl;
		}
	}
	fpResult << "nums of 'yes':" << yesCount << endl;
}