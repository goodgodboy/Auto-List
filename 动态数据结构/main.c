#include <stdio.h>
#include <stdlib.h>
#define long 10
#define file "D:\\动态数据链表.txt"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int N = long;

typedef struct node
{
	int num;
	struct node *next;
}NODE;

NODE *creatlist(int *a);		//创建链表数据 ，返回头地址 
void outlist(NODE *h);		//输出链表 
NODE *swaplist(NODE *h);		//逆置链表 
NODE *insert(NODE *h,int x);		//插入数据,仅加入链尾 
void tofile(NODE *h);		//写入文件 ，将文件写入D盘 
NODE *dele(NODE *h,int x);			// 删除链表
void sortlist(NODE *h);		//数据排序 

int main(int argc, char *argv[]) {
	int a[10]={5,3,7,4,8,2,1,12,6,10};
	NODE *head;
	head = creatlist(a);
	outlist(head);
	head = swaplist(head);
	outlist(head);
	head = dele(head,10);
	outlist(head);
	head = dele(head,2);
	outlist(head);
	insert(head,2);
	outlist(head);
	insert(head,10);
	outlist(head);
	sortlist(head);
	outlist(head);
	tofile(head);
	return 0;
}

NODE *creatlist(int *a)
{
	NODE *h,*p_now,*p_next;
	int i;
	if(a[0]!='\0')
	{
		h = p_now = (NODE *)calloc(sizeof(NODE),1);
		h->num = a[0]; 
	}else{
		return NULL;
	}
	for(i=1;i<N&&a[i]!='\0';i++)
	{
		p_next = (NODE *)calloc(sizeof(NODE),1);
		p_next->num = a[i];
		p_now->next = p_next;
		p_now = p_next;
	}
	p_next = NULL;
	return (h);
}

void outlist(NODE *h)
{
	NODE *p;
	p=h;
	while(p!=NULL)
	{
		printf("%d ",p->num);
		p = p->next;
	 }
	 printf("\n"); 
}

NODE *swaplist(NODE *h)
{
	NODE *p,*p_next,*p_pre;
	p = h;
	int i;
	if(p != NULL)
	{
		p_next = p->next;
		p->next = NULL;
		p = p_next;
		p_pre = h;
	}
	for(i=1;i<N&&p!=NULL;i++)
	{
		p_next = p->next;
		p->next = p_pre;
		p_pre = p;
		p = p_next;
	}
	return p_pre;
}

NODE *insert(NODE *h,int x)
{
	/*非特殊位置插入*/
	NODE *p_new = h,*p;
	while(p_new != NULL)
	{
		p = p_new;
		p_new = p_new->next;
	}
	p_new = (NODE *)calloc(sizeof(NODE),1);
	p_new->num = x;
	N+=1;
	p->next = p_new;
	p_new->next = NULL;
	/*非特殊位置插入*/
	/*特殊位置插入*/
	return h;	
	/*特殊位置插入*/
}

void tofile(NODE *h)
{
	int i,fg;
	NODE *p_node = h;
	FILE *fp = 0;
	if((fp = fopen(file,"w+")) == NULL)
	{//若以写的方式打开源文件“动态数据链表.txt”打开失败，结束程序。
		printf("File could not be open!\n");
		exit(0); 
	}
	for(i=0;i<N&&(fg>=0);i++)
	{
		fg = fprintf(fp,"%d ",p_node->num);
		p_node = p_node->next;
	}
	fclose(fp);
}

NODE *dele(NODE *h,int x)		//返回删除头节点的情况 
{
	NODE *p = h,*p_pre;
	if(h == NULL)
	{
		printf("List is NULL!\n");
	}else{
		while(p != NULL&&p->num != x)		//查找要删除的节点 
		{
			p_pre = p;
			p = p->next;
		}
		if(p->num == x)
		{
			if(p == h)
			{
				h = p->next;
			}else{
				p_pre->next = p->next;
			}
			free(p);
			N-=1;
		}else{
			printf("%d not been found!\n",x);
		}
	}
	return (h);
}

void sortlist(NODE *h)		//改变数据，不必返回地址 
{
	/*交换数据域排序*/ 
	NODE *p_pre,*p;
	int t;
	p_pre = h;
	while(p_pre)
	{
		p = p_pre->next;
		while(p)
		{
			if(p_pre->num > p->num)
			{
				t = p_pre->num;
				p_pre->num = p->num;
				p->num = t;
			}
			p = p->next;
		}
		p_pre = p_pre->next;
	}
	/*交换数据域排序*/ 
	
	
	/*交换指针域排序*/ 
	/*NODE *p=h,*p_next,*p_pre=h,p_tem;
	p_next = p->next;
	if((p->num<p_next->num)&&p == h)
	{
		p = p_next->next;
		p_next->next = h;
		h = p_next;
		p = h;
		p_next = p->next;
		p_next = p_next->next;
	}
	while(p!=NULL)
	{
		p_next = p->next;
		while(p_next!=NULL)
		{
			if(p->num<p_next->num)
			{
				p_tem.next = p->next;
				p_pre->next = p;
				p->next = p_next->next;
				p_next->next = p_tem.next;
			}
			p_pre = p_next;
			p_next = p_next->next;
		}
		p = p->next;
	}
	return (h); */ 
	/*交换指针域排序*/
}
