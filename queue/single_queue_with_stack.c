//write program for the implement queue using stack
#include<stdio.h>
#include<stdlib.h>
#define N 5
//defining s1 , s2 for array and the top1 , top2 are for top pointer of the stack 
//and count is used for the counting the element.

int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;
//write the enqueue operation
void enqueue(){
    int data;
    if(top1 == N-1) printf("overflow\n");
    else{
    printf("Enter the data: ");
    scanf("%d",&data);
    push1(data);
    count++;
    }
}
//write the dequeue operation for the stack
void dequeue(){
    int i;
    int a;
    int b;
    int x;
   if(top1 == -1){
       printf("the queue is empty\n");
   }
   else{
       for(i = 0 ; i<count ; i++ ){
           a = pop1();
           push2(a);
       }
       b = pop2();
       printf("the dequeued element is : %d\n",b);
       count--;
   for(i = 0; i<count ; i++){
       x = pop2();
       push1(x);
   }
   }
}
//write the pop operation 
int pop1(){ 
    return s1[top1--];
}
//write the pop operation
int pop2(){
    return s2[top2--]; 
}
//write the pushw operation for the stack2 
void push2(int a){
    if(top1 == N-1) printf("The queue is full \n");
    else s2[++top2] = a;
    
}
//write the push1 operation for the stack1
void push1(int a){
    if(top1 == N-1) printf("The queue is full \n");
    else  s1[++top1]=a; 
}

//display operation for the queue usig stack 1
void display(){
    int i;
    if(top1==-1) printf("there is no element in the queue\n");
    else{
    for(i = 0 ; i<= top1 ; i++) printf("%d\t", s1[i]);
    
    printf("\n");
    }
}

int main(){
    int choice;
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("invalid choice\n");
            }
        }
    }
    return 0;
}