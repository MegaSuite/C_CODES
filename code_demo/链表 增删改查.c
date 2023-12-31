/*
* ==================================================================

* Description: 链表 增删改查.c
* Author: Konrad Locas.
* (C)Copyright Konrad Locas.
* All rights reserved.
* Date: 2023/04/03 21:28:52

* ===================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkNode{
    int data;
    struct LinkNode *pNext;
};
typedef struct LinkNode node;//简化类型

void init(node *phead);//初始化
node * addback(node *phead,int data);//尾部添加节点
void addhead(node **pphead,int data);//头部添加节点
void showall(node *phead); //显示 遍历
void reshowall(node *phead);//反转显示
node *searchFirst(node *phead,int finddata);//查找第一个出现的数据
node *changeFirst(node *phead,int finddata,int newdata);//修改查找第一个出现的数据
node *deleteFirst(node *phead,int finddata);//查找第一个出现的数据,并将它删除
node *insertFirstHead(node *phead,int finddata,int newdata);//插入第一个出现的数据前面一个新数据
node *insertFirstBack(node *phead,int finddata,int newdata);//插入第一个出现的数据后面一个新数据
void sortLists(node *phead);//链表的排序

int main(int argc, const char * argv[])
{
    
//    node *phead = NULL;  //头结点不分配内存
//    node *tail= NULL;
    node *phead = NULL;
//    tail = phead;
//    init(phead);//不能初始化的头结点
    phead = addback(phead, 10);
    phead = addback(phead, 11);
    phead = addback(phead, 12);
    phead = addback(phead, 13);
    showall(phead);
    printf("====================\n");
    reshowall(phead);
    
    printf("====================\n");
 
    addhead(&phead,20);
    addhead(&phead,21);
    addhead(&phead,22);
    addhead(&phead,23);
    showall(phead);
    printf("====================\n");
    
//    reshowall(phead);
    
    node *pfind = searchFirst(phead, 13);
    pfind->data = 99;
    
    showall(phead);
    
    printf("====================\n");
    node *pchange = changeFirst(phead, 10, 100);
    printf("====================\n");
    showall(phead);
    printf("====================\n");
   
    
    phead = deleteFirst(phead, 23);
    phead = deleteFirst(phead, 20);
    phead = deleteFirst(phead, 99);
    printf("====================\n");
    showall(phead);
    printf("====================\n");
    
    phead = insertFirstHead(phead, 22, 220);
    phead = insertFirstHead(phead, 100, 1000);
    phead = insertFirstHead(phead, 12, 120);
    
    printf("====================\n");
    showall(phead);
    printf("====================\n");
   
    phead = insertFirstBack(phead, 120, 1200);
    phead = insertFirstBack(phead, 1000, 10000);
    phead = insertFirstBack(phead, 12, 121212);
    phead = insertFirstBack(phead, 220, 220220);

    printf("====================\n");
    showall(phead);
    printf("====================\n");
   
    sortLists(phead);
    
    printf("====================\n");
    showall(phead);
    printf("====================\n");
    return 0;
}
void init(node *phead)//初始化
{
    phead->data = 0;
    phead->pNext = NULL;
}

//尾部添加节点,指针作为参数，尾插，改变一个指针，需要指针的地址，用返回值给指针赋值
node *addback(node *phead,int data)
{
    node *pNew = malloc(sizeof(node));//重新的创建一个新的节点 data = 这里的data，pnext 为 空
    pNew->data = data;
    pNew->pNext = NULL; //赋值
    
    if (phead == NULL) {
        phead = pNew; //如果指针为空，直接连接，也就是第一个
    }else{
        node *ptemp = phead; //备份头结点，因为phead的值随着下面的循环在不停的改变，我们最终要返回phead,所以要备份phead的值
        while (ptemp->pNext != NULL) { //找出最后一个点
            ptemp = ptemp->pNext; //循环前进
        }
        ptemp->pNext = pNew;//找到了最后一个节点，把pNew链接上去
    }
    return phead;

}

//头部添加节点，指针的地址作为参数，所以，必须得用二级指针
void addhead(node **pphead,int data)
{
    node *pNew = malloc(sizeof(node));//重新的创建一个新的节点 data = 这里的data，pnext 为 空
    pNew->data = data;
    pNew->pNext = NULL;
    
    if (*pphead == NULL) {
        *pphead = pNew; //如果指针为空，直接连接，就是第一个
    }else{
        pNew->pNext = *pphead;
        *pphead = pNew;
    }
}

void showall(node *phead) //显示 遍历链表
{
//    if (phead == NULL) {
//        return;
//    }else{
//        printf("%p\t%d\t%p\t\n",phead,phead->data,phead->pNext);
//        showall(phead->pNext);//方法一：递归的方法
//   }

//        while (phead != NULL) {  //方法二
//            printf("%d\t%p\t%p\t\n",phead->data,phead,phead->pNext);
//            phead = phead->pNext;
//        }
        
    for (node *p1=phead; p1!=NULL; p1=p1->pNext) { //方法三
            printf("%d\t%p\t%p\t\n",p1->data,p1,p1->pNext);
        }
    
}
void reshowall(node *phead)//反转显示
{
    if (phead == NULL) {
        return;
    }else{
        reshowall(phead->pNext);
        printf("%d\t%p\t%p\t\n",phead->data,phead,phead->pNext);
    }
}


node *searchFirst(node *phead,int finddata)
{
    for (node *p = phead; p != NULL; p = p->pNext) {
        if (p->data == finddata) {
            return p;
//            break;//此处不能用break，执行不到
        }
    }
    return NULL;
}

node *changeFirst(node *phead,int finddata,int newdata)
{
    for (node *p = phead; p != NULL; p = p->pNext) {
        if (p->data == finddata) {
            //找到data的基础上，修改data为newdata
            p->data = newdata;
            return p;
        }
    }
    return NULL;
}

node *deleteFirst(node *phead,int finddata) //删除找到的节点
{
    node *p1 = NULL;
    node *p2 = NULL;
    p1 = phead; //保存phead的值
    
    while (p1 != NULL) {
        if (p1->data != finddata) { //继续往下面找，找到符合的p1
            p2 = p1; //保存p1的上一个节点
            p1 = p1->pNext;//向前移动
        }else{
            break; //找到啦！
        }
    }
    if (p1 != phead) {
        p2->pNext = p1->pNext;
        free(p1);
        
    }else{ //p1=phead 此时找到的p1为头指针，第一个
        phead = p1->pNext;//也可以 phead = phead -> pNext;
        free(p1);
    }
    return phead;
    
}

node *insertFirstHead(node *phead,int finddata,int newdata)
{
    node *p1 = NULL;
    node *p2 = NULL;
    p1 = phead; //保存phead的值
    
    while (p1 != NULL) {
        if (p1->data != finddata) { //继续往下面找，找到符合的p1
            p2 = p1; //保存p1的上一个节点
            p1 = p1->pNext; //向前移动
        }else{
            break; //找到啦！
        }
    }
        
    node *pNew = malloc(sizeof(node));//重新的创建一个新的节点 data = 这里的data，pnext 为 空
    pNew->data = newdata;
    pNew->pNext = NULL;
    
        
    if (p1 == phead) { //头部
        pNew->pNext = phead;
        phead = pNew;
        
    }else{  //中间任意值
        p2->pNext = pNew;
        pNew->pNext = p1;
    }
        return phead;
    
}

node *insertFirstBack(node *phead,int finddata,int newdata)//插入第一个出现的数据后面一个新数据
{
    node *p1 = NULL;
    node *p2 = NULL;
//    node *p3 = NULL;
    p1 = phead; //保存phead的值
    
    while (p1 != NULL) {
        if (p1->data != finddata) { //继续往下面找，找到符合的p1
           
            p1 = p1->pNext; //向前移动
//            p2 = p1; //此处错误
           
        }else{
            break; //找到啦！
        }
    }
    p2 = p1->pNext;
    
    node *pNew = malloc(sizeof(node));//重新的创建一个新的节点 data = 这里的data，pnext 为 空
    pNew->data = newdata;
    pNew->pNext = NULL; //赋值
    
    if (p2 != NULL ) {
        p1->pNext = pNew;
        pNew->pNext = p2;
    }else{
        p1->pNext = pNew;
    }
    
    return phead;
    
}

void sortLists(node *phead) //链表的排序
{
    node *p1 = NULL;
    node *p2 = NULL;
    int t;
    for(p1= phead;p1!=NULL;p1=p1->pNext)
        for(p2=p1->pNext;p2!=NULL;p2=p2->pNext)
            if(p1->data > p2->data){
                t=p1->data;                     /* 交换数据域,不改变指向关系 */
                p1->data = p2->data;
                p2->data = t;
            }
}
