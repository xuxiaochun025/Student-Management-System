#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct student{
	int num;
	char name[15];
	char sex[2];
	int age;
	double score[3];
	double sum;
	double ave;
};

typedef struct node {
	struct student data;
	struct node *next;
}Node;

void menu_select()
{
	printf("\n            Student studio           \n");
	printf("              1.add record             \n");
	printf("              2.delete record          \n");
	printf("              3.print record           \n");
	printf("              4.search record          \n");
	printf("              5.change recor           \n");
	printf("              6.quit                   \n");
}

void add(Node *head)
{
	Node *p, *q, *last;//p是插入结点，q,last指向头结点
	p = (Node *)malloc(sizeof(Node));
	last = head;
	printf("input number:");
	scanf_s("%d", &p->data.num);
	for (q = head; q->next != NULL; q = q->next) {//寻找学号
		if (q->data.num == p->data.num) {
			printf("input number again:");
			break;
		}
	}
	printf("input name:");
	scanf_s("%s", p->data.name,25);
	printf("input sex:");
	scanf_s("%s", p->data.sex,2);
	printf("input age:");
	scanf_s("%d", &p->data.age);
	printf("input score:");
	for (int i = 0; i < 3; i++) {
		scanf_s("%lf", &p->data.score[i]);
	}
	p->data.sum = p->data.score[0]+ p->data.score[1]+ p->data.score[2];
	p->data.ave = p->data.sum / 3;//输入data
	while (last->next != NULL) {  //尾插入
		last = last->next;
	}
	last->next = p;
	//last = p;
	p->next = NULL;
}

void del(Node *head)
{
	Node *p,*q;
	printf("Input a num: ");
	int num;
	scanf_s("%d", &num);
	p = head->next;
	q = head;
	while (p!= NULL) {
		if (p->data.num == num) {
			q->next = p->next;
			free(p);
			break;
		}
		else {
			q = p;
			p = p->next;
		}
	}
	if (p == NULL) {
		printf("No student.\n");
	}
}

void search(Node *head)
{
	int isFound = 0;
	Node *p = head;
	printf("Input a num: ");
	int num;
	scanf_s("%d", &num);
	for (p = head->next; p!= NULL; p = p->next) {
		if (p->data.num == num) {
			isFound = 1;
			break;
		}
	}
	if (isFound == 1) {
		printf("Find!\n");
	}
	else {
		printf("Not find!\n");
	}
}

void print(Node *head)
{
	Node *p;
	p = head->next;
	if (p == NULL) {
		printf("No information.\n");
	}
	while(p) {
		printf("%d\t", p->data.num);
		printf("%s\t", p->data.name);
		printf("%s\t", p->data.sex);
		printf("%d\t", p->data.age);
		printf("%lf\t", p->data.sum);
		printf("%lf\n", p->data.ave);
		p = p->next;
	}
}

void change(Node *head)
{
	Node *p;
	printf("Input a num: ");
	int num;
	scanf_s("%d", &num);
	int isChange = 0;
	for (p = head->next; p!=NULL; p = p->next) {
		if (p->data.num == num) {
			printf("input name:");
			scanf_s("%s", p->data.name, 25);
			printf("input sex:");
			scanf_s("%s", p->data.sex, 2);
			printf("input age:");
			scanf_s("%d", &p->data.age);
			printf("input score:");
			isChange = 1;
			break;
		}
	}
	if (isChange == 1) {
		printf("Changes succeed.\n");
	}
	else {
		printf("Changes fail.\n");
	}
}

int main()
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	while (1) {
		menu_select();
		printf("\nInput your choice: ");
		int i;
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			add(head);
			break;
		case 2:
			del(head);
			break;
		case 3:
			print(head);
			break;
		case 4:
			search(head);
			break;
		case 5:
			change(head);
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}
