#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"RadixTree.h"
class Search{
private:
	int prefix(char* x, int n, char* key, int m); //��x��key�Ĺ���ǰ׺
	Node* find(Node* t, char* x, int n = 0);
	void split(Node* t, int k); //��ǰkey�͵�ǰ����й����ڵ�,��Ҫ�ָ�ڵ�
	Node* insert(Node* t, char* x, int n = 0);
public:
	void trieCheck(FILE *fpStrPool, FILE *fpCheckedStr, FILE *fpResult);

};
#endif
