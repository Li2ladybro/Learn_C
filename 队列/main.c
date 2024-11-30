#include "Queue.h"

void QueueTest()
{
	Queue queue;
	QueueInint(&queue);

	QueuePush(&queue, 1);
	/*QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);*/

	printf("%d\n", QueueBack(&queue));
	while (!QueueEmpty(&queue))
	{
		printf("%d ", QueueBack(&queue));
		QueuePop(&queue);
	}
	printf("\n");	

	printf("%d\n", QueueLength(&queue));

	QueueDestroy(&queue);



}
int main()
{
	QueueTest();
	return 0;
}