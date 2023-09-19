/*
 * @Date: 2023-09-18 19:50:57
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-19 19:30:51
 * @FilePath: \homework_1\main.cpp
 */
#include <iostream>
#include <time.h>
using namespace std;

#include "List.h"

int main()
{
    /* List *plist = new List;
    setNode(plist, NULL, NULL, 0);
    // List *plist = NULL;
    if (!(addNode(plist, 10) && addNode(plist, 5))) // 测试头插法
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
    traverse(rlist, 1); // 删除中间节点后逆序输出 */

    // 1.
    // 随机生成10个整型数，并逐一添加到链表中
    srand(time(NULL));
    List *plist = new List;
    Node *node = new Node;
    setNode(node, NULL, NULL, rand() * 10 / RAND_MAX);
    plist->head = node;
    plist->tail = node;
    for (int i = 0; i < 9; i++)
    {
        int value = rand() * 10 / RAND_MAX; // 生成0-10的随机整数
        if (!addNode(plist, value))         // 尾插节点
            cout << "链表指针为空！" << endl;
    }
    cout << "随机生成链表正逆序:" << endl;
    traverse(plist, 0); // 随机生成链表后正序输出
    traverse(plist, 1); // 随机生成链表后逆序输出

    // 2.
    // 删除节点
    if (!delNode(plist)) // 删除尾部节点
        cout << "链表指针为空！或该链表只有一个节点" << endl;

    cout << "删除尾部节点后正逆序:" << endl;
    traverse(plist, 0); // 删除尾部节点后正序输出
    traverse(plist, 1); // 删除尾部节点后逆序输出

    // 3.
    // 删除节点（指定索引）
    if (!deleteNode(plist, 2)) // 删除索引为2的节点
        cout << "链表指针为空！或索引非法" << endl;

    cout << "删除索引为2的节点后正逆序:" << endl;
    traverse(plist, 0); // 删除索引为2的节点后正序输出
    traverse(plist, 1); // 删除索引为2的节点后逆序输出

    if (!deleteNode(plist, 0)) // 删除索引为0节点
        cout << "链表指针为空！或该链表只有一个节点" << endl;

    cout << "删除索引为0节点后正逆序:" << endl;
    traverse(plist, 0); // 删除索引为0节点后正序输出
    traverse(plist, 1); // 删除索引为0节点后逆序输出

    // 4.
    // 追加节点
    if (!addNode(plist, 0)) // 追加尾部节点
        cout << "链表指针为空！" << endl;
    cout << "追加尾部节点后正逆序:" << endl;
    traverse(plist, 0); // 追加尾部节点后正序输出
    traverse(plist, 1); // 追加尾部节点后逆序输出

    // 5
    // 追加节点（指定索引）
    if (!insertNode(plist, 0, 0)) // 在索引0处增加节点
        cout << "链表指针为空！或索引非法" << endl;
    cout << "在索引0处增加节点后正逆序:" << endl;
    traverse(plist, 0); // 在索引0处增加节点后正序输出
    traverse(plist, 1); // 在索引0处增加节点后逆序输出

    if (!insertNode(plist, 0, 5)) // 在索引5处增加节点
        cout << "链表指针为空！或索引非法" << endl;
    cout << "在索引5处增加节点后正逆序:" << endl;
    traverse(plist, 0); // 在索引5处增加节点后正序输出
    traverse(plist, 1); // 在索引5处增加节点后逆序输出

    // 6
    // 遍历当前链表
    cout << "遍历当前链表正逆序:" << endl;
    traverse(plist, 0); // 遍历当前链表正序输出
    traverse(plist, 1); // 遍历当前链表逆序输出

    // 7
    // 保存链表到数据文件
    savelist(plist, ".\\Res\\data.txt"); // 测试写入文件

    // 8
    // 读取数据文件，并遍历
    List *rlist = readlist(".\\Res\\data.txt"); // 测试读文件
    cout << "读文件后正逆序:" << endl;
    traverse(rlist, 0); // 读文件后正序输出
    traverse(rlist, 1); // 读文件后逆序输出

    return 0;
}