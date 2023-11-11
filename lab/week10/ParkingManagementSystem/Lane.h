// struct for lane,which is LinkQueue

typedef struct Node
{
    Car *car;
    Node *next;
} laneNode;

typedef struct
{
    laneNode *front;
    laneNode *rear;

} Lane;

void queueInit(Lane *L);
void enQueue(Lane *L, Car *s);
Car *deQueue(Lane *L);
int queueLength(Lane *L);
bool queueEmpty(Lane *L);