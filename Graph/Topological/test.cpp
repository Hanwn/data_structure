#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'G'}, 
        {'B', 'A'}, 
        {'B', 'D'}, 
        {'C', 'F'}, 
        {'C', 'G'}, 
        {'D', 'E'}, 
        {'D', 'F'}}; 
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    Graph* pG = nullptr;
    pG = new Graph(vexs, vlen, edges, elen);

    pG->print();   // 打印图
    pG->topological_sort();     // 拓扑排序

    return 0;
}