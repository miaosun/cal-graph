#include <vector>

using namespace std;

//alterado: retorna 0 caso encontre, -1 caso nao
int pesquisaSequencial(const vector<string> &v, string s){
	vector<string>::iterator it = v.begin();
	for(; it < v.end(); it++)
		if((*it) == s)
			return 0;
	return -1;
}
