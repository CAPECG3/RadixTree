#include <cstdlib>
#include <cstdio>
#include <cstring>
#include"RadixTree.h"
#include"Search.h"
#define CHAR_BIT 8
#define STR_LEN 320
int Search::prefix(char* x, int n, char* key, int m) {
	//找x和key的公共前缀
	for (int k = 0; k<n; k++)
		if (k == m || x[k] != key[k])
			return k;
	return n;
}
Node* Search::find(Node* t, char* x, int n) {
	if (!n) n = strlen(x);
	if (!t) return NULL;
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) return find(t->brother, x, n); //继续寻找兄弟节点
	if (k == n && k == t->len) return t;
	if (k == t->len) return find(t->child, x + k, n - k); // 前缀匹配成功,寻找孩子节点
	return NULL;
}
void Search::split(Node* t, int k) {
	//当前key和当前结点有公共节点,需要分割节点
	Node* p = new Node(t->key + k, t->len - k);
	p->child = t->child;
	t->child = p;
	char* a = new char[k];
	strncpy(a, t->key, k);
	delete[] t->key;
	t->key = a;
	t->len = k;
}
Node* Search::insert(Node* t, char* x, int n) {
	if (!n) n = strlen(x) ;
	if (!t) return new Node(x, n);
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) t->brother = insert(t->brother, x, n);
	else if (k<n)
	{
		if (k < t->len) {
			split(t, k);
		}
		t->child = insert(t->child, x + k, n - k);
	}
	return t;
}
void Search::trieCheck(ifstream &fpStrPool, ifstream &fpCheckedStr, ofstream &fpResult) {
	Node *root = new Node();
	char s[STR_LEN];
	char binary[CHAR_BIT * STR_LEN + 1] = { 0 };
	while (fpStrPool >> s) {
		int len = strlen(s);
		fill(binary, binary + CHAR_BIT*STR_LEN + 1, 0);
		for (int j = 0; j < len; j++) {
			for (int i = 0; i < CHAR_BIT; ++i) {
				binary[j*CHAR_BIT + 7 - i] = ((s[j] >> i) & 1) + '0';
			}
		}
		insert(root, binary, len*CHAR_BIT);
	}
	int yesCount = 0; //统计yes的个数
	while (fpCheckedStr >> s) {
		char binary[CHAR_BIT * STR_LEN + 1] = { 0 };
		int len = strlen(s);
		for (int j = 0; j < len; j++) {
			for (int i = 0; i < CHAR_BIT; ++i) {
				binary[j*CHAR_BIT + 7 - i] = ((s[j] >> i) & 1) + '0';
			}
		}
		if (!find(root, binary, CHAR_BIT*len)) {
			fpResult << "no" << endl;
		}
		else {
			yesCount++;
			fpResult << "yes" << endl;
		}
	}
	fpResult << "nums of 'yes':" << yesCount << endl;
}