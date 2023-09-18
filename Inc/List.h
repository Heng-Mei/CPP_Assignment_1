/*
 * @Date: 2023-09-18 20:12:54
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-18 20:23:18
 * @FilePath: \homework_1\Inc\List.h
 */
#ifndef LIST_H
#define LIST_H

typedef struct List
{
    List *beforeNode;
    List *nextNode;
    int value;
} List;

bool insertNode(List *plist, int nVal);
bool deleteNode(List *plist);
#endif // LIST_H