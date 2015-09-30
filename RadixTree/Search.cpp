#include <cstdlib>
#include <cstdio>
#include <cstring>
#include"RadixTree.h"
#include"Search.h"
int Search::prefix(char* x, int n, char* key, int m) {
	//��x��key�Ĺ���ǰ׺
	for (int k = 0; k<n; k++)
		if (k == m || x[k] != key[k])
			return k;
	return n;
}
Node* Search::find(Node* t, char* x, int n) {
	if (!n) n = strlen(x);
	if (!t) return NULL;
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) return find(t->brother, x, n); //����Ѱ���ֵܽڵ�
	if (k == n) return t;
	if (k == t->len) return find(t->child, x + k, n - k); // ǰ׺ƥ��ɹ�,Ѱ�Һ��ӽڵ�
	return NULL;
}
void Search::split(Node* t, int k) {
	//��ǰkey�͵�ǰ����й����ڵ�,��Ҫ�ָ�ڵ�
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
	char s[320];
	while (fpStrPool >> s) {
		insert(root, s);
	}
	int yesCount = 0; //ͳ��yes�ĸ���
	while (fpCheckedStr >> s) {
		if (!find(root, s)) {
			fpResult << "no" << endl;
		}
		else {
			yesCount++;
			fpResult << "yes" << endl;
		}
	}
	fpResult << "nums of 'yes':" << yesCount << endl;
}