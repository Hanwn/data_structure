#include <iostream>

using namespace std;

#ifndef _HEADER_H_

#define _HEADER_H_

#define MAX 100

class MatrixUDG{
public:
	MatrixUDG();
	MatrixUDG(char vexs[],int vlen,char edges[][2],int elen);
	~MatrixUDG();
public:
	void print();
private:
	char readChar();
	int getPosition(char ch);
private:
	char Vexs[MAX];
	int VexNum;
	int EdgeNum;
	int Matrix[MAX][MAX];
};

MatrixUDG::MatrixUDG(){
	cout<<"please input vertex number:";
	cin>>VexNum;
	cout<<"please input edges number:";
	cin>>EdgeNum;
	if(VexNum<1||EdgeNum<1||(EdgeNum>(VexNum*(VexNum - 1)))){
		cout<<"invalid Graph";
		return ;
	}
	for (int i = 0; i < VexNum; i++){
		cout<<"vertex:("<<i<<"):";
		Vexs[i] = readChar();
	}

	for (int i = 0; i < EdgeNum; i++){
		cout<<"edge("<<i<<"):";
		char c1 = readChar();
		char c2 = readChar();

		int p1 = getPosition(c1);
		int p2 = getPosition(c2);

		if(p1 == -1||p2 == -1){
			cout<<"invalid Edge";
			return;
		}

		Matrix[p1][p2] = 1;
		Matrix[p2][p1] = 1;
	}
}

MatrixUDG::MatrixUDG(char vexs[],int vlen,char edges[][2],int elen){
	VexNum = vlen;
	EdgeNum = elen;
	for (int i = 0; i < VexNum ;i++){
		Vexs[i] = vexs[i];
	}

	for (int i = 0; i < EdgeNum; i++){
		int p1 = getPosition(edges[i][0]);
		int p2 = getPosition(edges[i][1]);

		Matrix[p1][p2] = 1;
		Matrix[p2][p1] = 1;
	}
}

MatrixUDG::~MatrixUDG(){
}

int MatrixUDG::getPosition(char ch){
	for (int i = 0; i < VexNum; i++){
		if(Vexs[i] == ch){
			return i;
		}
	}
	return -1;
}

char MatrixUDG::readChar(){
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

void MatrixUDG::print(){
	cout<<"   ";
	for( int i = 0 ; i < VexNum ; i++){
		cout<<Vexs[i]<<"  ";
	}
	cout<<endl;
	for (int i = 0; i < VexNum; i++){
		cout<<Vexs[i]<<"  ";
		for (int j = 0; j < VexNum; j++){
			cout<<Matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
}

#endif