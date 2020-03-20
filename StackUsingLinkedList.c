 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {     
	int data;     
	struct node *next;
 };
 struct node *n;
 struct stack
 {    
	struct node *top;
 };
 struct stack *s;
 void push(int x)
 {    
	n=(struct node *)malloc(sizeof(struct node));    
	if(n==NULL)        
		printf("Stack overflow\n");    
	else    
	{       
		n->data=x;       
		n->next=s->top;       
		s->top=n;    
	}
 }
 int isempty()
 {   
	if(s->top==NULL)     
		return 1;   
	else 
		return 0;
 }
 int pop()
 {
    int x;    
	if(isempty())           
		return -1;    
	else    
	{       
		x=s->top->data;       
		n=s->top;       
		s->top=s->top->next;       
		free(n);       
		return x;     
	}
 }
 void display()
 {   
	if(isempty())      
		printf("Stack underflow\n");   
	else   
	{      
		n=s->top;      
		while(n!=NULL)      
		{         
			printf("%d ",n->data);         
			n=n->next;      
		}     
		printf("\n");    
	}
 }   
 void main()
 {   
 int x,ch;   
 s->top=NULL;   
 do   
 {      
	printf("1:Push 2:Pop 3:Display 4:Exit\n");      
	scanf("%d",&ch);      
	switch(ch)      
	{         
		case 1: printf("enter a value\n");                      
				scanf("%d",&x);                      
				push(x);                      
				break;         
		case 2: x=pop();                      
				printf("Popped value=%d\n",x)                      
				break;         
		case 3: display();
                break;         
		case 4: printf("Exit\n");                      
				break;        
	}    
 } 
 while(ch!=4);
}