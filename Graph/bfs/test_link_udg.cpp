#include <iostream>
#include "header_link_udg.h"

int main(){
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'}, 
        {'A', 'D'}, 
        {'A', 'F'}, 
        {'B', 'C'}, 
        {'C', 'D'}, 
        {'E', 'G'}, 
        {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    Udg_link* d = new Udg_link(vexs,vlen,edges,elen);
    d->print();
    cout<<endl;
    d->bfs();
	return 0;
}