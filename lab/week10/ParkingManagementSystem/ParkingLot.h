#define MAX_PARKING_SLOT 7
#define MAX_LANE 3
//struct for car
typedef struct 
{
    
}Car;
// struct for slot,which is the element of the Sqlist and the linkqueue
typedef struct {
    Car *car;
    int slot_num;
    parkingSlot *next;
}parkingSlot;

//struct for parkinglot,which is a Sqlist
typedef struct{
    parkingSlot *slot[MAX_PARKING_SLOT];
    int num_of_car;

} parKingLot;


