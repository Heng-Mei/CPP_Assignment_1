/*
 * @Date: 2023-09-18 19:53:12
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 13:20:04
 * @FilePath: \homework_1\Src\List.cpp
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "List.h"

/**
 * @description: 设置一个新节点的属性
 * @param {List} *node 传入新节点地址
 * @param {List} *beforeNode 新节点的上一个节点地址
 * @param {List} *nextNode 新节点的下一个节点地址
 * @param {int} value 新节点的值
 * @return {*} 无
 */
void setNode(List *node, List *beforeNode, List *nextNode, int value)
{
    if (node == NULL)
        return;

    node->beforeNode = beforeNode;
    node->nextNode = nextNode;
    node->value = value;
}

/**
 * @description: 在链表中的首节点后插入节点
 * @param {List} *plist 首节点地址
 * @param {int} nVal 插入的节点的值
 * @return {status} 返回状态，false代表首节点地址为空
 */
status insertNode(List *plist, int nVal)
{
    if (plist == NULL)
        return false;

    List *newNode = new List;
    setNode(newNode, plist, plist->nextNode, nVal);

    if (plist->nextNode != NULL)
        plist->nextNode->beforeNode = newNode;

    plist->nextNode = newNode;

    return true;
}

/**
 * @description: 删除链表首节点后的一个节点
 * @param {List} *plist 首节点地址
 * @return {status} 返回状态，false代表首节点地址为空
 */
status deleteNode(List *plist)
{
    if (plist == NULL || plist->nextNode == NULL)
        return false;

    List *delNode = plist->nextNode;

    plist->nextNode = plist->nextNode->nextNode;
    if (plist->nextNode != NULL)
    {
        plist->nextNode->beforeNode = plist;
    }

    delete delNode;
    return true;
}

/**
 * @description: 双向遍历
 * @param {List} *plist 遍历首地址
 * @param {int} dir 控制遍历方向，0正向，1反向
 * @return {*} 无
 */
void traverse(List *plist, int dir)
{
    if (plist == NULL)
    {
        cout << "首节点地址为空!" << endl;
        return;
    }

    if (dir == 0)
    {
        List *node = plist;
        while (node != NULL)
        {
            cout << node->value << endl;
            node = node->nextNode;
        }
        cout << endl;
    }
    else if (dir == 1)
    {
        List *node = plist;
        while (node->nextNode != NULL)
            node = node->nextNode;

        while (node != NULL)
        {
            cout << node->value << endl;
            node = node->beforeNode;
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
 * @param {char} *fileName 写入的文件名
 * @return {*} 返回写入状态
 */
status listToFile(List *plist, const char *fileName)
{
    if (plist == NULL)
        return false;
    fstream outfile;
    outfile.open(fileName, ios::out);
    List *node = plist;
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
 * @param {char} *fileName 读入的文件名
 * @return {List *} 返回读入的链表首节点地址
 */
List *fileToList(const char *fileName)
{
    List *plist = new List;
    setNode(plist, NULL, NULL, 0);

    List *node = plist;
    fstream infile;
    int value;
    infile.open(fileName, ios::in);

    infile >> value;
    plist->value = value;
    while (true)
    {
        infile >> value;
        if (infile.eof())
            break;
        List *newNode = new List;
        setNode(newNode, node, NULL, value);
        node->nextNode = newNode;
        node = newNode;
    }
    return plist;
}

/**
 * @description: 在指定位置后插入节点
 * @param {List} *plist 链表首节点地址
 * @param {int} value 插入的值
 * @param {int} index 索引
 * @return {status} 返回状态，false代表首地址为空
 */
status insertIndexNode(List *plist, int value, int index)
{
    if (plist == NULL || index <= 0)
        return false;
    List *node = findIndex(plist, index);
    if (node == NULL)
        return false;
    insertNode(node, value);
    return true;
}

/**
 * @description: 删除指定位置的节点
 * @param {List} *plist 链表首节点地址
 * @param {int} index 索引
 * @return {List *} 返回删除后的首地址，NULL代表传入首地址为空或索引非法
 */
List *deleteIndexNode(List *plist, int index)
{
    if (plist == NULL || index <= 0)
        return NULL;
    List *node = findIndex(plist, index);
    if (node == NULL)
        return NULL;
    List *newList = plist;
    if (node->beforeNode == NULL)
    {
        newList = newList->nextNode;
        newList->beforeNode = NULL;
        delete node;
    }
    else if (node->nextNode == NULL)
    {
        node->beforeNode->nextNode == NULL;
        delete node;
    }
    else
    {
        node->beforeNode->nextNode = node->nextNode;
        node->nextNode->beforeNode = node->beforeNode;
        delete node;
    }
    return newList;
}

/**
 * @description: 查找指定索引的地址
 * @param {List} *plist 首地址
 * @param {int} index 索引
 * @return {List *} 索引节点地址
 */
List *findIndex(List *plist, int index)
{
    int curIndex = 1;
    for (List *node = plist; node != NULL; node = node->nextNode, curIndex++)
        if (curIndex == index)
            return node;
    return NULL;
}
