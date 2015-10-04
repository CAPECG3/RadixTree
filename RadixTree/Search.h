#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"RadixTree.h"
class Search{
private:
	int prefix(char* x, int n, char* key, int m); //找x和key的公共前缀
	Node* find(Node* t, char* x, int n = 0);
	void split(Node* t, int k); //当前key和当前结点有公共节点,需要分割节点
	Node* insert(Node* t, char* x, int n = 0);
public:
	void trieCheck(FILE *fpStrPool, FILE *fpCheckedStr, FILE *fpResult);

};
#endif
