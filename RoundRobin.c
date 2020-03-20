#include<stdio.h> 

struct Node

{
    
int PID,at,bt,bt1,wt;
   
 struct Node *next;

};


struct Node *f=NULL,*r=NULL,*temp;

int cnt=1;
int tbt=0;

void createQueue()

{
    
int count=0;
    int n,i;
  
  printf("Please tell me how many processes do you have \n");
   
 scanf("%d",&n);
    for (i=0; i<n; i++)
   
 {
      
  temp=(struct Node*)malloc(sizeof(struct Node));
       
 temp->PID=count++;
        
printf("Input the burst time of process %d\n",count);
        
scanf("%d",&temp->bt);
       
 tbt+=temp->bt;
       
 temp->wt=0;
       
 temp->bt1=temp->bt;
       
 temp->next=NULL;
        
temp->at=0;
        
if (f==NULL)
        
{
           
 r=f=temp;
       
 }
       
 else
       
 {
            
r->next=temp;
           
 r=temp;
       
 }
     
   temp=NULL;
   
 }
  
  printf("Created %d processes\n",count);
   
 cnt=count;

}

void schedule()

{
    
while (f!=NULL && tbt>0)
   
 {
       
 struct Node *temp;
        
for(temp=f; temp!=NULL; temp=temp->next)
       
 {
            
if(temp->bt > 0)
          
  {
        
printf("P%d ",temp->PID);
              
  temp->bt--;
             
   tbt--;
                
struct Node *t1=f;
               
 while(t1!=NULL)
             
   {
                    
if(t1!=temp)
                  
  {
                       
 if(t1->bt>0)
                            
t1->wt++;
                   
 }
                  
  t1=t1->next;
             
   }
          
  }
       
 }

    
}
   
 struct Node *t2=f;
   
 printf("\n");
   
 printf("PID\tWT\tAT\n");
   
 int ttat=0;
  
  int twt=0;
   
 while(t2!=NULL)
  
  {

       
 printf("P%d \t %d \t %d \n",t2->PID,t2->wt,t2->wt+t2->bt1);
       
 ttat+=(t2->wt+t2->bt1);
        
twt+=t2->wt;
       
 t2=t2->next;
  
  }
   
 printf("\n");
 
   printf("Total Turn-Around time= %d\n",ttat);
  
  printf("Total waiting time= %d\n",twt);
    
printf("Average Turn-Around time= %f\n",(float)ttat/cnt);
   
 printf("Average Waiting time= %f\n",(float)twt/cnt);

}
int main()

{
    
createQueue();
   
 schedule();
  
  return 0;

}
