/*
 * @Date: 2023-09-18 19:50:57
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-18 20:50:03
 * @FilePath: \homework_1\main.cpp
 */
#include <iostream>
using namespace std;

#include "List.h"

int main()
{
    List *plist = new List;
    plist->value = 0;
    // List *plist = NULL;
    if (!insertNode(plist, 10))
    {
        cout << "首地址为空！" << endl;
    }

    return 0;
}