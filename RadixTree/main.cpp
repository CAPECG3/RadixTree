#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include"Search.h"
#include"RadixTree.h"
using namespace std;



int main(int argc, char *argv[]) {
	ifstream fpStrPool(argv[1]);
	ifstream fpCheckedStr(argv[2]);
	ofstream fpResult(argv[3]);
	clock_t begin = clock();
	Search t;
	t.trieCheck(fpStrPool,fpCheckedStr,fpResult);
	clock_t end = clock();
	fpResult << (double)(end - begin) / CLOCKS_PER_SEC;
	fpResult << "s" << endl;
	fpResult << "------------------trieend---------------------- " ;

}
