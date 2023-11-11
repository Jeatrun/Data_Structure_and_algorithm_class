#define MAX_PARKING_SLOT 7 // 停车场最大车位数
#define MAX_LANE 3         // 出入道最大可排车辆数
// struct for car
typedef struct
{

} Car;
// struct for slot,which is the element of the Sqlist and the linkqueue
typedef struct slot
{
    Car *car;
    int slot_num;
    bool slotEmpty;
} parkingSlot;

// struct for parkinglot,which is a Sqlist
typedef struct
{
    parkingSlot *slot[MAX_PARKING_SLOT];
    int num_of_car;

} parkingLot;

// mathod of parkingSlot
void initParkingLot(parkingLot *pl);
// enter the lot,
void enterParkingLot(parkingLot *pl, Car *car, int slot_num);
// exit the lot then to pay, return false if there is no car
void exitParkingLot(parkingLot *pl, Car *&car, int slot_num);

// print out empty slot and return the num of them
int findEmptySlot(parkingLot *pl, int &SlotNumTheOnly);

bool lotFull(parkingLot *pl);
bool lotEmpty(parkingLot *pl);