//Trung tố sang hậu tố, và tính biểu thức hậu tố
#include <stdio.h>
#include <string.h>
typedef struct node{
    char info;
	int  info2;
    struct node* next;
}Node;
Node* CreateNode(char x)
{
	Node* p = new node;
	p->info = x;
	p->info2 = NULL;
	p->next = NULL;
	return p;
}
Node* CreateNode2(int x)
{
	Node* p = new node;
	p->info = NULL;
	p->info2 = x;
	p->next = NULL;
	return p;
}
void Init(Node* &pHead)
{
	 pHead = NULL;
}
int IsEmpty(Node* p)
{
	if(p == NULL)
		return 1;
	else return 0;
}
void Push(Node* &pHead, char x)
{
    Node* p = CreateNode(x);
    if(IsEmpty(pHead) == 1)
        pHead = p;
	else 
		{  
            p->next = pHead;
            pHead = p;
        }
}
void Push2(Node* &pHead, int x)
{
    Node* p = CreateNode2(x);
    if(IsEmpty(pHead) == 1)
        pHead = p;
	else 
		{  
            p->next = pHead;
            pHead = p;
        }
}
Node* Pop(Node* &pHead)
{
    Node* p = pHead;
    pHead = p->next;
    return p;
}
int Priority( char x)
{
	if (x == '-' || x == '+')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	if (x == '^')
		return 3;
	if (x == '(')
		return 0;
}
int Lenght(char Arr[])
{
    int count = 0;
    int i = 0;
    while(Arr[i] != NULL)
    {
        count++;
        i++;
    }
    return count;
}
void Delete(char Arr[], int i)
{
    for ( i ; i < Lenght(Arr) ; i++ )
    {
    	Arr[i] = Arr[i+1];
	}

}
void Postfix(Node* &pHead, char Arr[100])
{
	for(int  i = 0 ; i < Lenght(Arr) ; i++)
	{
        if (Arr[i] == '(' )
            {
                Push(pHead,Arr[i]);
            }
        if (Arr[i] >= '0' && Arr[i] <= '9')
        	{
        		printf("%c",Arr[i]);;
			}
		if (Arr[i] == ')' )
			{
				while(pHead->info != '(')
				{
					printf("%c",Pop(pHead)->info);
				}
				Pop(pHead);
			}
		if (Arr[i] == '+' || Arr[i] == '-' || Arr[i] == '/' || Arr[i] == '*' )
			{
				if(pHead != NULL)
					{
						if( Priority(Arr[i]) <= Priority(pHead->info))
						{
							printf("%c",Pop(pHead)->info);
							Push(pHead,Arr[i]);
						}
						else Push(pHead,Arr[i]);
					}
				else Push(pHead,Arr[i]);
				
			}
	}
	
	while(pHead != NULL)
	{
		printf("%c",Pop(pHead)->info);
	}
}
int CalcPostfix(Node* &pHead, char Arr[])
{
	for(int i = 0 ; i < Lenght(Arr) ; i++ )
		{
			if (Arr[i] >= '0' && Arr[i] <= '9')
				{
					Push2(pHead,Arr[i] - '0');
				}
			if (Arr[i] == '+' || Arr[i] == '-' || Arr[i] == '/' || Arr[i] == '*')
				{
					int a,b;
					switch (Arr[i])
					{
						case '+':
							 a = Pop(pHead)->info2;
							 b = Pop(pHead)->info2;
							Push2(pHead, b+a);
						break;
						case '-':
							 a = Pop(pHead)->info2;
							 b = Pop(pHead)->info2;
							Push2(pHead, b-a);
						break;
						case '/':
							 a = Pop(pHead)->info2;
							 b = Pop(pHead)->info2;
							Push2(pHead, b/a);
						break;
						case '*':
							 a = Pop(pHead)->info2;
							 b = Pop(pHead)->info2;
							Push2(pHead, b*a);
						break;
					}
				}
		}
	printf("Gia tri hau to : %d",Pop(pHead)->info2);
}
int main()
{
    Node* pHead;
    Init(pHead);
    char Arr[100];	
    printf("Nhap mang trung to: ");
    fflush(stdin);
    gets(Arr);
	printf("Mang chuyen doi sang hau to: ");
    Postfix(pHead,Arr);
	char ArrPostFix[100];
	printf("\nNhap mang hau to can tinh: ");
    fflush(stdin);
    gets(ArrPostFix);
	CalcPostfix(pHead,ArrPostFix);	

}

