/*
 * @Date: 2023-09-18 20:12:54
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 18:40:48
 * @FilePath: \homework_1\Inc\List.h
 */
#ifndef LIST_H
#define LIST_H

#define status bool

typedef struct Node
{
    Node *beforeNode;
    Node *nextNode;
    int value;
}Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

void setNode(Node *node, Node *beforeNode, Node *nextNode, int value);
status addNode(List *plist, int nVal);
status delNode(List *plist);
void traverse(List *plist, int dir);
status savelist(List *plist, const char *fileName);
List *readlist(const char *fileName);
status insertNode(List *plist, int value, int index);
status deleteNode(List *plist, int index);
Node *findIndex(List *plist, int index);
#endif // LIST_H