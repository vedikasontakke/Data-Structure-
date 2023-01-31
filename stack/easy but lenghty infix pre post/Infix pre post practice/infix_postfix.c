#include<stdio.h>

char opr[25] = {'\0'};
char out[25] = {'\0'};

int topopr = -1;
int topout = -1;

void pushopr(char);
char popopr();
char peekopr();

void pushout(char);
void displayout();

int return_priority(char);

void main()
{
    char infix[25] = {'\0'} , popele , ele;
    int i=0 ; 

    printf("enter a infix strng : ");
    scanf("%s",&infix);

    while(infix[i] != '\0')
    {     
         ele = infix[i];
         if(ele == '(') pushopr(ele);
         else if(ele == ')')
         {
            while(peekopr() != '(')
            {
                popele = popopr();
                pushout(popele);
            }
            popopr();
         }else if(ele == '+' || ele == '-' || ele == '/' || ele == '*' || ele == '^')
         {
            if(topopr >= 0){

             while(return_priority(peekopr()) >= return_priority(ele))
             {
                     popele = popopr();
                     pushout(popele);
             }
            }
             pushopr(ele);
         }else{
            pushout(ele);
         }

    displayopr();
     displayout();
         i++;
         
    }
     if(topopr != -1)
    {
        while(topopr != -1)
        {
            popele = popopr();
            pushout(popele);
        }
    }

    printf("postfix is : %s ", out);
    
}

void pushopr(char ele)
{
    if(topopr == 24) printf("stack is full");
    else opr[++topopr] = ele; 
}

int return_priority(char opr)
{
    switch (opr)
    {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-':return 1;
    }

    return -1;
}

char popopr()
{
    if(topopr != -1) return opr[topopr--];
}

void pushout(char ele)
{
    if(topout == 24) printf("stack full");
    else out[++topout] = ele;
}

char peekopr()
{
   if(topopr != -1) return opr[topopr];
}

void displayout()
{
    printf("output stack is : ");
    for(int i=0 ; i<=topout ; i++)  printf("| %c ", out[i]);

}

void displayopr()
{
    printf("\noperator stack is :");
    for(int i=0 ; i<=topopr ; i++) printf("| %c ", opr[i]);
}
