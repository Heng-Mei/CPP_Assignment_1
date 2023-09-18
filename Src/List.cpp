/*
 * @Date: 2023-09-18 19:53:12
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-18 20:52:13
 * @FilePath: \homework_1\Src\List.cpp
 */
#include <iostream>
#include "List.h"

bool insertNode(List *plist, int nVal)
{
    if (plist == NULL)
    {
        return false;
    }
    List *newNode = new List;
    newNode->value = nVal;
    newNode->beforeNode = plist;
    newNode->nextNode = plist->nextNode;
    plist->nextNode = newNode;
    return true;
}
bool deleteNode(List *plist)
{
    //TODO  删除节点操作
    return true;
}