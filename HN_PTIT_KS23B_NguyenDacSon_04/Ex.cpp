#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

Node* createNode(int data) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void initialQueue(Queue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

int isEmpty(Queue *queue) {
	return queue->front == NULL;
}

void enqueue(Queue *queue, int value) {
	Node* newNode = createNode(value);
	if(isEmpty(queue)) {
		queue->front = newNode;
	} else {
		queue->rear->next = newNode;
	}
	queue->rear = newNode;
}

void dequeue(Queue *queue) {
	if(!isEmpty(queue)) {
		Node *temp = queue->front;
		int value = temp->data;
		queue->front = queue->front->next;
		free(temp);
		printf("Phan tu duoc lay ra: %d", value);
		return;
	}
	printf("Hang doi rong!\n");
}

void peek(Queue* queue){
	if(isEmpty(queue)){
		queue->front = 0;
	}
	printf("Phan tu o dau hang doi co gia tri: %d\n", queue->front->data);
}

int size(Queue* queue){
	if (queue->front == NULL) {
        printf("Hang doi rong!\n");
        return 0;
    }
	int count = 0;
    Node* current = queue->front;
    while (current != NULL) {
    	count++;
        current = current->next;
    }
    return count;
}

void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong!\n");
        return;
    }

    Node* current = queue->front;
	printf("Hang doi:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
	int value, choice;
	Queue queue;
	initialQueue(&queue);
	do {
		printf("\n============== MENU ===============\n");
		printf("1. Them phan tu vao hang doi (enqueue)\n");
		printf("2. Lay phan tu khoi hang doi (dequeue)\n");
		printf("3. Kiem tra phan tu dau hang doi (peek)\n");
		printf("4. Kiem tra hang doi co rong khong (isEmpty)\n");
		printf("5. Lay kich thuoc hang doi (size)\n");
		printf("6. In toan bo hang doi (display)\n");
		printf("7. Xoa toan bo hang doi (clear)\n");
		printf("8. Kiem tra phan tu cuoi cung (rear)\n");
		printf("9. Thoat");
		printf("\n===================================\n");
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Nhap gia tri muon them: ");
				scanf("%d", &value);
				enqueue(&queue, value);
				break;
			case 2:
				dequeue(&queue);
				break;
			case 3:
				peek(&queue);
				break;
			case 4:
				if(isEmpty(&queue)) printf("Hang doi rong!\n");
				else printf("Hang doi khong rong.\n");
				break;
			case 5:
				printf("Kich thuoc hang doi: %d", size(&queue));
				break;
			case 6:
				displayQueue(&queue);
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				exit(0);
			default:
				printf("Khong co chuc nang ban chon, moi ban chon lai!");
		}
	} while (1 == 1);
	return 0;
}

