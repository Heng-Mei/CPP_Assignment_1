/*
 * @Date: 2023-09-18 19:53:12
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 19:30:12
 * @FilePath: \homework_1\Src\List.cpp
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "List.h"

/**
 * @description: 设置一个新节点的属性
 * @param {Node} *node 传入新节点地址
 * @param {Node} *beforeNode 新节点的上一个节点地址
 * @param {Node} *nextNode 新节点的下一个节点地址
 * @param {int} value 新节点的值
 * @return {*} 无
 */
void setNode(Node *node, Node *beforeNode, Node *nextNode, int value)
{
    if (node == NULL)
        return;

    node->beforeNode = beforeNode;
    node->nextNode = nextNode;
    node->value = value;
}

/**
 * @description: 尾部添加节点
 * @param {List} *plist 链表指针
 * @param {int} nVal 添加的节点的值
 * @return {status} 返回状态，false代表链表指针为空
 */
status addNode(List *plist, int nVal)
{
    if (plist == NULL)
        return false;

    Node *newNode = new Node;
    Node *node = plist->tail;
    setNode(newNode, node, NULL, nVal);
    node->nextNode = newNode;
    plist->tail = newNode;
    return true;
}

/**
 * @description: 删除尾部节点
 * @param {List} *plist 链表指针
 * @return {status} 返回状态，false代表链表指针为空
 */
status delNode(List *plist)
{
    if (plist == NULL || plist->head->nextNode == NULL)
        return false;

    Node *node = plist->tail;
    node->beforeNode->nextNode = NULL;
    plist->tail = node->beforeNode;
    delete node;
    return true;
}

/**
 * @description: 双向遍历
 * @param {List} *plist 链表指针
 * @param {int} nDir 控制遍历方向，0正向，1反向
 * @return {*} 无
 */
void traverse(List *plist, int nDir)
{
    if (plist == NULL)
    {
        cout << "首节点地址为空!" << endl;
        return;
    }

    if (nDir == 0)
    {
        for (Node *node = plist->head; node != NULL; node = node->nextNode)
        {
            cout << node->value;
            if (node->nextNode != NULL)
                cout << ",";
        }
        cout << endl;
    }
    else if (nDir == 1)
    {
        for (Node *node = plist->tail; node != NULL; node = node->beforeNode)
        {
            cout << node->value;
            if (node->beforeNode != NULL)
                cout << ",";
        }
        cout << endl;
    }
    else
    {
        cout << "dir参数不正确!" << endl;
        return;
    }
}

/**
 * @description: 将链表写入文件
 * @param {const char} *fileName 写入的文件名
 * @return {*} 返回写入状态
 */
status savelist(List *plist, const char *fileName)
{
    if (plist == NULL)
        return false;
    fstream outfile;
    outfile.open(fileName, ios::out);
    Node *node = plist->head;
    while (node != NULL)
    {
        outfile << node->value << endl;
        node = node->nextNode;
    }
    outfile.close();
    return true;
}

/**
 * @description: 从文件读入链表
 * @param {const char} *fileName 读入的文件名
 * @return {List *} 返回读入的链表地址
 */
List *readlist(const char *fileName)
{
    fstream infile;
    int value;
    infile.open(fileName, ios::in);

    infile >> value;

    List *plist = new List;
    Node *node = new Node;
    setNode(node, NULL, NULL, value);
    plist->head = node;
    while (true)
    {
        infile >> value;
        if (infile.eof())
            break;
        Node *newNode = new Node;
        setNode(newNode, node, NULL, value);
        node->nextNode = newNode;
        node = newNode;
    }
    plist->tail = node;
    infile.close();
    return plist;
}

/**
 * @description: 在指定位置后插入节点
 * @param {List} *plist 链表指针
 * @param {int} value 插入的值
 * @param {int} index 插入值的索引
 * @return {status} 返回状态，false代表首地址为空
 */
status insertNode(List *plist, int value, int index)
{
    if (plist == NULL || index < 0)
        return false;
    if (index == 0)
    {
        Node *newNode = new Node;
        setNode(newNode,NULL,plist->head,value);
        plist->head->beforeNode = newNode;
        plist->head = newNode;
        return true;
    }
    Node *node = findIndex(plist, index - 1);
    if (node == NULL)
        return false;
    if (node->nextNode == NULL)
    {
        Node *newNode = new Node;
        setNode(newNode,node,NULL,value);
        node->nextNode = newNode;
        plist->tail = newNode;
    }
    else
    {
        Node *newNode = new Node;
        setNode(newNode,node,node->nextNode,value);
        newNode->beforeNode->nextNode = newNode;
        newNode->nextNode->beforeNode = newNode;
    }
    return true;
}

/**
 * @description: 删除指定位置的节点
 * @param {List} *plist 链表指针
 * @param {int} index 索引
 * @return {status *} 返回状态，false代表链表指针为空或索引非法
 */
status deleteNode(List *plist, int index)
{
    if (plist == NULL || index < 0)
        return false;

    Node *node = findIndex(plist, index);
    if (node == NULL)
        return false;
    if (node->beforeNode == NULL)
    {
        plist->head = node->nextNode;
        plist->head->beforeNode = NULL;
        delete node;
    }
    else if (node->nextNode == NULL)
    {
        plist->tail = node->beforeNode;
        node->beforeNode->nextNode == NULL;
        delete node;
    }
    else
    {
        node->beforeNode->nextNode = node->nextNode;
        node->nextNode->beforeNode = node->beforeNode;
        delete node;
    }
    return true;
}

/**
 * @description: 查找指定索引的地址
 * @param {List} *plist 链表指针
 * @param {int} index 索引
 * @return {Node *} 索引节点地址
 */
Node *findIndex(List *plist, int index)
{
    int curIndex = 0;
    for (Node *node = plist->head; node != NULL; node = node->nextNode, curIndex++)
        if (curIndex == index)
            return node;
    return NULL;
}
