/*Simple Calculator*/
/*TharinduRamanayake*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


void splitExpression(char *str, int *v1, int *v2, char *op);

int main(int argc,char **argv)
{
    char str[30];
    int v1,v2,res;
    char op;
while(1)
    {
    printf("Enter equation Value :");
    scanf("%s",&str);
    if(strcmp(str,"exit")==0){
    printf("\nGood Bye see you again...\n");
        return 0;
    }

    splitExpression(str,&v1,&v2,&op);

     switch(op) {
  case '+' :
    res = v1 + v2;
    break;
  case '-':
     res = v1 - v2;
     break;
  case '*' :
     res = v1 * v2;
    break;
  case '/':
    res = v1 / v2;
    break;
    case '0':
    printf("Equation Invalid Try again...\n"); //if wrong equation print this
    continue;
  default:
    printf("Unknown operation!!!\n"); //if wrong operation print this
    continue;
  }
  printf("%s = %d\n",str, res);
 }

}

void splitExpression(char *str, int *v1, int *v2, char *op)
{
     int i,found;
  char buff[20];
  int j=0;
  for(i=0, found=0; i < strlen(str); i++) {
    if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      *op     = str[i];     // found the operator
      buff[j] = '\0';       // terminate the string

      if (strlen(buff)==0||found==1) {
            *op='0';
            return;
            /*TharinduRamanayake*/
      }
      j       = 0;
      *v1      = atoi(buff);
      assert(!found);
      found = 1;
    }

    else {
      buff[j++] = str[i];
    }
  }

  buff[j] = '\0';
  *v2 = atoi(buff);
}
