#define MAX_PARKING_SLOT 7//ͣ�������λ��
#define MAX_LANE 3//����������ų�����
//struct for car
typedef struct 
{
    
}Car;
// struct for slot,which is the element of the Sqlist and the linkqueue
typedef struct slot{
    Car *car;
    int slot_num;
    slot *next;
}parkingSlot;

//struct for parkinglot,which is a Sqlist
typedef struct{
    parkingSlot *slot[MAX_PARKING_SLOT];
    int num_of_car;

} parkingLot;

//mathod of parkingSlot
void initParkingLot(parkingLot *pl);
void enterParkingLot(parkingLot *pl,Car *car,int slot_num);
void exitParkingLot(parkingLot *pl,int slot_num);
void pay();
bool findSlot(parkingLot *pl);
bool lotFull(parkingLot *pl);

