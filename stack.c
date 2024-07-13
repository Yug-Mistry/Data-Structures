#include <stdio.h> 

// Push Operation
void push(void *arr,int max,int *top, void *value, int data_type) {
	if(*top + 1 >= max)
	    printf("Stack Overflow !\n");
	else{
	    switch(data_type)
	    {
	    	case 1:
	    		((int *)arr)[*top + 1] = *((int *)value);
	                *top += 1;
	                break;
      		case 2:
      			((char *)arr)[*top + 1] = *((char *)value);
      			*top += 1;
      			break;
  	    }
	}
}


void* pop(void *arr, int *top, int data_type){
	if(*top >= 0){
		void *r;
		switch(data_type){
			case 1:
				r = ((int*)arr+ *top);
				*top -= 1;
   	  			return r;
			case 2:
				r = ((char*)arr+*top);
				*top -= 1;
				return r;
		}
	}
	else{
		printf("Stack Underflow !\n");
		return NULL;
	}
}

void* peek(void *arr, int *top, int data_type){
	if(*top >= 0){
		switch(data_type){
			case 1:
				return ((int*)arr + *top);
			case 2:
				return ((char*)arr + *top);
		}
	}else{
		printf("Stack is empty\n");
		return NULL;
	}
}
