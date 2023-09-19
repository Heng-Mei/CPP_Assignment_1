/*
 * @Date: 2023-09-18 20:12:54
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 13:12:27
 * @FilePath: \homework_1\Inc\List.h
 */
#ifndef LIST_H
#define LIST_H

#define status bool
typedef struct List
{
    List *beforeNode;
    List *nextNode;
    int value;
} List;

void setNode(List *node, List *beforeNode, List *nextNode, int value);
status insertNode(List *plist, int nVal);
status deleteNode(List *plist);
void traverse(List *plist, int dir);
status listToFile(List *plist, const char *fileName);
List *fileToList(const char *fileName);
status insertIndexNode(List *plist, int value, int index);
List *deleteIndexNode(List *plist, int index);
List *findIndex(List *plist, int index);
#endif // LIST_H