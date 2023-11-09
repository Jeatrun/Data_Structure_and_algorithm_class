#include"ParkingLot.h"
#include <stdio.h>
#include <stdlib.h>

void initParkingLot(parkingLot *pl){
    pl=(parkingLot*)malloc(typeof(parkingLot));
    pl->num_of_car=0;
}

void enterParkingLot(parkingLot *pl, Car *car, int slot_num){
    if(!findSlot(pl))
    { return;} 
    



}

bool lotFull(parkingLot *pl){
    return pl->num_of_car==MAX_PARKING_SLOT;
}

bool findSlot(parkingLot *pl){
    if(lotFull(pl)){
        printf("This Lot is Full!please queue ");
        return false;
    }else {
        //print the empty slot out
    }
}