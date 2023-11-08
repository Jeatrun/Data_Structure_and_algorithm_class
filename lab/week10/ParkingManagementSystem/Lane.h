#include "ParkingLot.h"

// struct for lane,which is LinkQueue
typedef struct
{
    parkingSlot *front;
    parkingSlot *rear;

} Lane;

void queueInit(Lane *L);
void enQueue(Lane *L, Car *s);
Car *deQueue(Lane *L);
int queueLength(Lane *L);
bool queueEmpty(Lane *L);