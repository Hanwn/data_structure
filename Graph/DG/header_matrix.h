#include <iostream>

using namespace std;

#ifndef _HEADER_MATRIX_H_
#define _HEADER_MATRIX_H_

#define MAX 100	

class DG{
public:
	DG();
	DG(char v[],int vlen,char e[][2],int elen);
	~DG(){};
public:
	char getChar();
	void print();
	int getPosition(char ch);
private:
	int Matrix[MAX][MAX];
	char varr[MAX];
	int vsum;
	int esum;
};

DG::DG(){

}

DG::DG(char v[],int vlen,char e[][2],int elen){
	Matrix[0][0] = 0;
	vsum = vlen;
	esum = elen;
	for (int i = 0; i < vlen; i++){
		varr[i] = v[i];
	}

	for(int i = 0; i < elen ; i++){
		char c1 = e[i][0];
		char c2 = e[i][1];

		int p1 = getPosition(c1);
		int p2 = getPosition(c2);

		Matrix[p1][p2] = 1;
	}
}

char DG::getChar(){
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

int DG::getPosition(char ch){
	for (int i = 0; i < vsum ; i++){
		if(varr[i] == ch){
			return i;
		}
	}
	return -1;
}
void DG::print(){
	//cout<<Matrix[0][0];
	for(int i = 0 ; i < vsum ;i++){
		for(int j = 0; j < vsum ;j++){
			cout<<Matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
#endif