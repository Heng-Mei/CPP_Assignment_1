/*
 * @Date: 2023-09-18 20:12:54
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-18 23:17:55
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
status listToFile(List *plist, char *fileName);
List *fileToList(char *fileName);

#endif // LIST_H