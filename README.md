<!--
 * @Date: 2023-09-20 15:18:25
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-09-20 16:00:00
 * @FilePath: \homework_1\README.md
-->
# 1.    作业要求
## 1.1  函数
- [x] 链表添加节点功能  
-   `bool addNode(list* plist,int nVal)`  
-   参数：`plist`，要追加节点的链表指针，`nVal`，节点值 
-   返回值：是否成功    
-   要求内部有合法性验证    
-   节点添加于链表尾部  

- [x] 链表删除节点功能    
-   `bool delNode(list* plist)`
-   参数：`plist`，链表指针   
-   返回值：是否成功    
-   要求内部有合法性验证    
-   删除尾部节点 

- [x] 链表遍历功能  
-   `void traverse(list* plist,int nDir)`    
-   参数：`plist`，链表指针，`nDir`，遍历方向：0-正向，1-反向   
-   要求内部有合法性验证    
-   遍历时打印每个节点值   

- [x] 链表保存到文件
-   `void savelist(list* plist)`
-   参数：`plist`，链表指针
-   要求内部有合法性验证
-   仅保存节点值，保存的数据文件是1列多行，数据文件名为`data.txt` 

- [x] 从数据文件读取数据并创建链表    
-   `void readlist(list* plist)` 
-   参数：`plist`，链表指针   
-   数据文件名称默认为`data.txt`，若文件中包含有效数据，则创建链表，依次读出每个节点的值，并添加到链表中；否则返回。  

- [x] （附加，可选做）节点删除功能（指定索引）    
-   `bool delNode(list* plist,int nIdx)` 
-   参数：`plist`，链表指针，`nIdx`，要删除的节点索引   
-   返回值：是否成功    
-   要求内部有合法性验证    
-   头节点索引认为是0，依次增加 

- [x] （附加，可选做）节点插入功能（指定索引）    
-   `bool insertNode(list* plist,int nVal,int nIdx)` 
-   参数：`plist`，链表指针，`nVal`,节点值，`nIdx`，节点插入索引  
-   返回值：是否成功    
-   要求内部有合法性验证    
-   头节点索引认为是0，依次增加。若指定位置不合法，则返回`false`。    

##  1.2 测试流程
```c++
int main()
{
	//1.
	//随机生成10个整型数，并逐一添加到链表中
    //2.
	//删除节点
	//3.
	//删除节点（指定索引）
	//4.
	//追加节点
	//5
	//追加节点（指定索引）
	//6
	//6遍历当前链表
	//7
	//保存链表到数据文件
	//8
	//读取数据文件，并遍历
}
``` 
##  1.3 结构体声明
```c++
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
``` 

#   2.  文件目录
-   Inc
    -   List.h
    >   结构体及其函数声明 
-   Src
    -   List.cpp
    >   函数定义
-   Res
    -   data.txt
    >   数据文件   
-   main.cpp
>   测试主程序
-   README.md
