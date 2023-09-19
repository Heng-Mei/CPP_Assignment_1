/*
 * @Date: 2023-09-18 19:50:57
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 13:28:00
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
    if (!(insertNode(plist, 10) && insertNode(plist, 5))) // 测试头插法
        cout << "首地址为空！" << endl;

    traverse(plist, 0);                    // 头插后正序输出
    traverse(plist, 1);                    // 头插后逆序输出
    listToFile(plist, ".\\Res\\data.txt"); // 测试写入文件

    if (!deleteNode(plist)) // 测试删除节点
        cout << "首地址为空！或该链表只有一个节点" << endl;

    traverse(plist, 0); // 删除节点后正序输出
    traverse(plist, 1); // 删除节点后逆序输出

    List *rlist = fileToList(".\\Res\\data.txt"); // 测试读文件
    traverse(rlist, 0);                           // 读文件后正序输出
    traverse(rlist, 1);                           // 读文件后逆序输出

    if (!(insertIndexNode(rlist, 1, 2) && insertIndexNode(rlist, 2, 4))) // 测试在指定索引后插入节点
        cout << "首地址为空！或索引非法" << endl;

    traverse(rlist, 0); // 插入节点后正序输出
    traverse(rlist, 1); // 插入节点后逆序输出

    List *tempList = deleteIndexNode(rlist, 1); // 测试删除指定索引（删除头节点）
    if (tempList == NULL)
        cout << "首地址为空！或索引非法" << endl;
    rlist = tempList;

    traverse(rlist, 0); // 删除头节点后正序输出
    traverse(rlist, 1); // 删除头节点后逆序输出

    tempList = deleteIndexNode(rlist, 3); // 测试删除指定索引（删除中间节点）
    if (tempList == NULL)
        cout << "首地址为空！或索引非法" << endl;
    rlist = tempList;
    traverse(rlist, 0); // 删除中间节点后正序输出
    traverse(rlist, 1); // 删除中间节点后逆序输出

    return 0;
}