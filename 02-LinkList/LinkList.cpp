/*
* link list (数据结构-单链表)
*
* @author ideallove
* @since 2022-09-01
*/
#include <iostream>
#define ElemType int    // 可以根据需求自定义
using namespace std;

typedef struct LNode {  // 定义单链表结点类型
    ElemType data;      // 数据域
    struct LNode* next; // 指针域
}LNode, *LinkList;



int main()
{
    std::cout << "Hello World!\n";
}
