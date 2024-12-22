typedef struct {
    int* _arr;    // 线性存储
    int _front;   // 队头下标
    int _rear;    // 队尾
    int _maxSize; // 最大空间有效数据位为_maxSize-1

} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cirQueue =
        (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (cirQueue == NULL) {
        printf("初始化失败，内存不足\n");
        exit(-1);
    }
    cirQueue->_maxSize = k + 1; // 有效数据为K个
    cirQueue->_arr = (int*)malloc(sizeof(int) * cirQueue->_maxSize);
    if (cirQueue->_arr == NULL) {
        printf("初始化失败，内存不足\n");
        exit(-1);
    }
    cirQueue->_front = cirQueue->_rear = 0;
    return cirQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        // 队列满插入失败
        printf("队列满插入失败\n");
        return 0;
    } else {
        // 队列不满插入成功
        obj->_arr[obj->_rear] = value;
        obj->_rear = (obj->_rear + 1) % obj->_maxSize;
        return 1;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        // 队列为空删除失败
        printf("队列为空删除失败\n");
        return 0;
    } else {
        // 队列非空删除成功
        obj->_front = (obj->_front + 1) % obj->_maxSize;
        return 1;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj) == 1) {
        return -1;
    } else {
        return obj->_arr[obj->_front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj) == 1) {
        return -1;
    } else {
        int ret = 0;
        if (obj->_rear - 1 == -1) {
            ret = obj->_maxSize - 1;
        } else {
            ret = obj->_rear - 1;
        }
        return obj->_arr[ret];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->_rear == obj->_front) {
        // 🈳队
        return 1;
    } else {
        // 非空
        return 0;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->_rear + 1) % obj->_maxSize == obj->_front) {
        return 1;
    } else {
        // 非空
        return 0;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/