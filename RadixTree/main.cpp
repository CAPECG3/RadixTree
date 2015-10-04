#include<cstdio>
#include<string>
#include<fstream>
#include<ctime>
#include"Search.h"
#include"RadixTree.h"
using namespace std;



int main(int argc, char *argv[]) {
	FILE *fpStrPool = fopen(argv[1], "r");
	FILE *fpCheckedStr = fopen(argv[2], "r");
	FILE *fpResult = fopen(argv[3], "w");
	clock_t begin = clock();
	Search t;
	t.trieCheck(fpStrPool,fpCheckedStr,fpResult);
	clock_t end = clock();
	fprintf(fpResult, "%fs\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
