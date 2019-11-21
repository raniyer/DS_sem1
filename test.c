#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printGraph(int V, int graph[V][V]);

// A structure to represent a stack 
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

// function to create a stack of given capacity. It initializes size of stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

void printGraph(int V, int graph[V][V])
{
	int i, j;
	for(i = 0; i < V; i++)
	{
		for(j = 0; j < V; j++)
		{
			printf("\t%d", graph[i][j]);
		}
		printf("\n");
	}
	return;
}

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for(int i = 0; i < V; i++)
		if(graph[v][i] && c == color[i];
			return false;
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[],int v)
{
	if(v==V)
		return true;
	for(int c = 1; c <= m; c++))
	{
		if (isSafe(v, graph, color, c)) 
	        { 
        		color[v] = c; 
           		if (graphColoringUtil (graph, m, color, v+1) == true) 
             			return true;
		        color[v] = 0; 
        	} 
    	} 
	return false; 
} 

void graphColoring(int graph[V][V], int m) 
{ 
	int color[V]; 
	for (int i = 0; i < V; i++) 
		color[i] = 0; 
	if (graphColoringUtil(graph, m, color, 0) == false) 
	{ 
		printf("Solution does not exist"); 
		return; 
	}   
	printSolution(color); 
	return; 
}

int main() 
{ 
	int V, i, j;
	printf("\n\nEnter numer of vertix of the graph: ");
	scanf("%d", &V);
	int graph[V][V];
	for(i = 0; i < V; i++)
	{
		for(j = 0; j < V; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	printGraph(graph);
	printf("\nnumber of colours available: ");
	scanf("%d" &m);
	graphColoring(graph, m);   
	return 0; 
}
