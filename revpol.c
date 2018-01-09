#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

int token_priority(char c){
        switch(c){
		case '*' :
		case '/' :  
                return 3;
		case '+' :
		case '-' :  
                return 2;
		case '=' :
		case '(' :
                return 1;
		case ')' :
                default:
                return 0;
        }
}

int main(){
        char* inputstring;
        scanf("%ms",&inputstring);


	for(int i=0;i<strlen(inputstring);i++){
		printf("%c ",inputstring[i]);
	}
	printf("\n");

        struct stack parsestack;
        new_stack(&parsestack);

        char* outstring=(char*)malloc(strlen(inputstring)+1);//NULL文字分+1

	for(int i=0;i<strlen(inputstring);i++){
		//scanf("%d",&j);
		if(inputstring[i]>='A' && inputstring[i]<='Z'){
                        printf("%c",inputstring[i]);
		}else if(inputstring[i]=='('){
                        stack_push(&parsestack,inputstring[i]);
		}else if(inputstring[i]==')'){
                        /*while(1){
                                if(stack_peek(&parsestack)){
                                }
                                printf("%c\n",inputstring[i]);
                        };*/
		}else{
			if(parsestack.size==0){  //スタックが空の場合無条件にプッシュ
				stack_push(&parsestack,inputstring[i]);
			}else if(token_priority(inputstring[i])>token_priority(stack_peek(&parsestack))){   //inputstringの優先>topの優先
                                printf("%c",stack_pop(&parsestack));
			}else{                       //inputstringの優先<=topの優先
                                while(1){
                                        char c=stack_pop(&parsestack);
                                        printf("%c",c);
                                        if(inputstring[i]>c){
                                                break;
                                        }
                                }
			}
		}
	}

	/*for(int i=stptr-1;i>=0;i--){
		strcpy(outstring[onum],stack[i]);
		onum++;
	}*/
        puts("\n");

	//printf("outstring : %s\n",outstring);
}
