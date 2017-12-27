#include <stdlib.h>
#include <string.h>
#include"vector.h"
void new_vector(struct vector* a){
        a->size=0;
        a->memory_size=100;
        a->data=(struct token**)malloc(sizeof(struct token*)*a->memory_size);
}
void vector_push(struct vector* a,char* str,size_t str_size,size_t line,size_t column){
        a->data[a->size]=(struct token*)malloc(sizeof(struct token));

        a->data[a->size]->name=(char*)malloc(str_size+1);
	strncpy(a->data[a->size]->name,str,str_size);
	a->data[a->size]->name[str_size]='\0';

	a->data[a->size]->line=line;
	a->data[a->size]->column=column;

        a->size++;
        if(a->size>=a->memory_size){
                a->memory_size*=2;
                a->data=(struct token**)realloc(a->data,sizeof(struct token*)*a->memory_size);
        }
}
