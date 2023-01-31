#include<stdio.h>

// operator stack
void pushopr(char);
char popopr();
char peepopr();
void displayopr();

//output stack
void pushout(char);
void displayout();

int getpriority(char);

char opr[25] = {'\0'};
char out[25] = {'\0'};
int topopr = -1;
int topout = -1;

void main()
{
   char infix[25] = {'\0'} , ele , pop_ele;
   int i=0;

   printf("enter infix expression : \n");
   scanf("%s",&infix);
   printf("infix expression is : %s\n" , infix);
   
   while(infix[i] != '\0')
   {
     ele = infix[i];
     if(ele == '(') pushopr(ele);
     else if(ele == ')'){
        while(peepopr() != '('){
            pop_ele = popopr();
            pushout(pop_ele);
        }
        popopr();
     }
     else if(ele == '^' || ele == '*' || ele == '/' || ele == '+' || ele == '-')
     {
         if(topopr >= 0) {
            while(getpriority(peepopr()) >= getpriority(ele)) {
                pop_ele = popopr();
                pushout(pop_ele);
            }
         }
         pushopr(ele);
     }
     else
         pushout(ele);

     displayopr();
     displayout();

     i++;
   }
   if(topopr != -1){
     while(topopr != -1) {
        pop_ele = popopr();
        pushout(pop_ele);
     }
   }
   printf("\n Postfix expression is : %s \n", out);
}

void pushopr(char ele){
    if(topopr == 24) printf("\n operator stack is full\n");
    else opr[++topopr] = ele;
}

char popopr()
{
    if(topopr != -1) return opr[topopr--];
}

char peepopr()
{
   if(topopr != -1) return opr[topopr];

}

void displayopr()
{
    printf("\noperator stack is :");
    for(int i=0 ; i<=topopr ; i++) printf("| %c ", opr[i]);
}

int getpriority(char ele)
{
   switch(ele)
   {
     case '^' : return 3;
     case '*' :
     case '/' : return 2;
     case '+' :
     case '-' : return 1;
   }
   return -1;
}

void pushout(char ele)
{
    if(topout == 24) printf("output stack is full\n");
    else out[++topout] = ele;
}

void displayout()
{
    printf("\noutput stack is :");
    for(int i=0 ; i<=topout ; i++)  printf("| %c ", out[i]);
}
