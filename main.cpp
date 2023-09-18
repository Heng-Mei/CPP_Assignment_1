/*
 * @Date: 2023-09-18 19:50:57
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-18 23:03:23
 * @FilePath: \homework_1\main.cpp
 */
#include <iostream>
using namespace std;

#include "List.h"

int main()
{
    List *plist = new List;
    setNode(plist, NULL, NULL, 0);
    // List *plist = NULL;
    if (!(insertNode(plist, 10) && insertNode(plist, 5)))
    {
        cout << "首地址为空！" << endl;
    }
    traverse(plist, 0);
    traverse(plist, 1);
    if (!deleteNode(plist))
    {
        cout << "首地址为空！或该链表只有一个节点" << endl;
    }
    traverse(plist, 0);
    traverse(plist, 1);

    return 0;
}