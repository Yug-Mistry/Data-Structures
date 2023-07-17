#include <stdio.h>
#include <stdbool.h>

// Push Operation
void push(void *arr, int *top, void *value, int size, int data_type)
{
  if (*top + 1 == size)
    printf("Stack Overflow !\n");
  else
  {
    switch (data_type)
    {
    case 1:
      *((int *)(arr) + (*top + 1)) = *((int *)value);
      *top += 1;

      // printf("Pushing value %d to the int stack\n", *((int *)value));

      break;
    case 2:
      *((char *)(arr) + (*top + 1)) = *((char *)value);
      *top += 1;

      // printf("Pushing value %c to the char stack\n", *((char *)value));

      break;
    }
  }
}

// Pop Operation
void *pop(void *arr, int *top, int data_type)
{
  if (*top >= 0)
  {
    void *r;
    switch (data_type)
    {
    case 1:
      r = (int *)arr + *top;
      *top -= 1;

      // printf("Popping an element from the int stack\n");
      return r;
    case 2:
      r = (char *)arr + *top;
      *top -= 1;

      // printf("Popping an element from the char stack\n");
      return r;
    }
  }
  else
  {
    printf("Stack Underflow !\n");
    return top;
  }
}

// Peek Operation
void *peek(void *arr, int *top, int data_type)
{
  if (*top >= 0)
  {
    switch (data_type)
    {
    case 1:
      return (int *)arr + *top;
    case 2:
      return (char *)arr + *top;
    }
  }
  else
  {
    printf("Stack Underflow !\n");
    return top;
  }
}

// Peep Operation
void *peep(void *arr, int *top, int index, int max, int data_type)
{
  if (*top >= 0 && index > 0 && index <= *top + 1)
  {
    switch (data_type)
    {
    case 1:
      return (int *)arr + (*top + 1 - index);
    case 2:
      return (char *)arr + (*top + 1 - index);
    }
  }
  else
  {
    printf("Stack is empty or invalid value for index is provided.\n");
    return top;
  }
}

// Display Operation
void display(void *arr, int top, int data_type)
{
  if (top >= 0)
  {
    printf("\nStack\n");
    switch (data_type)
    {
    case 1:
      for (int i = top; i >= 0; i--)
        printf("|_%d_|\n", *((int *)arr + i));
      break;
    case 2:
      for (int i = top; i >= 0; i--)
        printf("|_%c_|\n", *((char *)arr + i));
      break;
    }
  }
  else
  {
    printf("Stack Underflow !\n");
  }
}

// Change Operation
void change(void *arr, int top, void *value, int index, int max, int data_type)
{
  if (top >= 0 && index > 0 && index <= top + 1)
  {
    switch (data_type)
    {
    case 1:
      *((int *)arr + (top + 1 - index)) = *((int *)value);
      break;
    case 2:
      *((char *)arr + (top + 1 - index)) = *((char *)value);
      break;
    }
  }
  else
  {
    printf("Stack is empty or index is invalid !%d\n", index);
  }
}

// Is Full Operation
bool isFull(int top, int max)
{
  return top == (max - 1);
}

// Is Empty Operation
bool isEmpty(int top)
{
  return top == -1;
}
