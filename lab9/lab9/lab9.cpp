#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <queue>

#define MAX_SIZE 10000
//#define NO_PRINT

struct node {
	int vertex;
	struct node *next;
};

struct node* createNode(int v) {
	struct node *newNode = (node*) malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph {
	int numVertices;
	struct node **adjLists;
};

struct Graph* createGraph(int vertices) {
	struct Graph *graph = (Graph*) malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = (node**) malloc(vertices * sizeof(struct node*));

	int i;
	for (i = 0; i < vertices; i++)
		graph->adjLists[i] = NULL;

	return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
	struct node *newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph) {
	#ifdef NO_PRINT
	return;
	#endif

	int v;
	printf("\n");
	for (v = 0; v < graph->numVertices; v++) {
		struct node *temp = graph->adjLists[v];
		printf("\nvertex: %d\n ", v + 1);
		while (temp) {
			printf("%d ", temp->vertex + 1);
			temp = temp->next;
		}
	}
}

void BFSD(int **G, int size_G, int v, int **DIST) {
	bool visited[MAX_SIZE] = {false};
	visited[v] = true;
	DIST[0][v] = 0;

	int queue[MAX_SIZE] = {0};
	int front = 0, rear = 0;
	queue[rear++] = v;
	int n = 1;

	while (front != rear) {
		int current_vertex = queue[front++];
		#ifndef NO_PRINT
		printf("%d ", current_vertex);
		#endif

		n = 1;

		for (int i = 0; i < size_G; i++) {
			if (G[current_vertex][i] == 1 && !visited[i]) {
				queue[rear++] = i;
				visited[i] = true;
				DIST[n][current_vertex] = i;
				DIST[0][i] = DIST[0][current_vertex] + 1;
				n++;
			}
		}
	}
}


int DFS(int **vertex, int first, int **matrix, int count, int clearVertex, int dst) {
	vertex[1][first] = false;
	#ifndef NO_PRINT
	printf("vertex: %d", vertex[0][first]);
	printf(" dst: %d\n", dst);
	#endif

	for (int i = 0; i < count; i++)
		if (matrix[first][i] == 1 and vertex[1][i] == true)
			DFS(vertex, i, matrix, count, clearVertex, ++dst);

	for (int i = 0; i < count; i++)
		if (vertex[1][i] == 0)
			clearVertex--;

	return clearVertex;
}

void POG(int **matrix, int count, int i) {
	int **NUM = (int**) malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; i++)
		NUM[i] = (int*) malloc(count * sizeof(int));

	for (int i = 0; i < count; i++) {
		NUM[0][i] = i + 1;
		NUM[1][i] = true;
	}

	int clearVertex = count;

	while (clearVertex > 0) {
		while (NUM[1][i] == false) {
			i++;
		}
		clearVertex = DFS(NUM, i, matrix, count, clearVertex, 0);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, NULL);

	int size, v = 0;
	printf("Enter a count of headers: ");
	scanf(" %d", &size);

	srand(time(NULL)); //    

	int **matrix = (int**) calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*) calloc(size, sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int random = rand() % 2; //    0  1
			matrix[i][j] = random;
			matrix[j][i] = random; //      
		}
	}
	#ifndef NO_PRINT
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	#endif

	printf("Enter the source vertex: ");
	scanf("%d", &v);

	int** DIST = (int**)calloc(size + 1, sizeof(int*));
	for (int i = 0; i < size; i++) {
		DIST[i] = (int*)calloc(size, sizeof(int));
	}

	for (size_t i = 0; i < size; i++) {
		DIST[0][i] = -1;
	}
	clock_t time_start = clock();
	BFSD(matrix, size, v, DIST);
	clock_t time_end = clock();

	double diff = time_end - time_start;

	printf("\nDIST vector:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", DIST[0][i]);
	}
	for (int i = 1; i < size; i++) {
		printf("\n%d - %d ", v, i);
		for (int j = 0; j < size; j++)
		{
			if(DIST[i][j] != 0)
				printf("%d ", DIST[i][j]);
		}
	}
	printf("\n");
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
				printf("%d ", DIST[i][j]);
		}
		printf("\n");
	}

	// 1.3
	struct Graph *graph = createGraph(size);
	srand(time(NULL));
	int *vertex = (int*) calloc(size, sizeof(int));
	bool edge;

	for (int i = 0; i < size; i++) {
		vertex[i] = i;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			edge = matrix[i][j];
			if (edge == true) {
				addEdge(graph, i, j);
			}
		}
	}
	printGraph(graph);
	printf("\ndistances:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", DIST[i]);
	}

	// 2
	printf("\n\n--TASK 2--\n\n");
	clock_t time_start2 = clock();
	POG(matrix, size, v);
	clock_t time_end2 = clock();
	double diff2 = time_end2 - time_start2;

	printf("\ntime elapsed : %fms\n", diff);
	printf("time elapsed2: %fms\n", diff2);


}

