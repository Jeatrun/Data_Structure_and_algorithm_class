#include "ParkingLot.h"
#include <stdio.h>
#include <stdlib.h>

void initParkingLot(parkingLot *pl)
{
    pl = (parkingLot *)malloc(sizeof(parkingLot));
    pl->num_of_car = 0;
}

void enterParkingLot(parkingLot *pl, Car *car, int slot_num)
{
    /*this code below should be realize in the enter function
    *******************************************************


    int SlotNumTheOnly; // Slot num of the only one slot
    int numChoice;


    // find empty slot first.if those slots are full,then return
    if (findSlot(pl, SlotNumTheOnly) == 0)
    {
        return false;
    }

    // else if there is only 1 slot,then just enter the slot without choosing
    else if (findSlot(pl, SlotNumTheOnly) == 1)
    {
        // find the empty slot
        //this could be moved to the find function,since we already know that there must be one slot which is empty
        for (int i = 0; i < MAX_PARKING_SLOT; i++)
        {
            if (pl->slot[i]->slot_num == SlotNumTheOnly)
            {
                pl->slot[i]->car = car;
                pl->num_of_car++;
                break;
            }
        }
        return true;
    }
    // otherwise we choose which slot to park
    *******************************************************
    */

    // find the slot
    for (int i = 0; i < MAX_PARKING_SLOT; i++)
    {
        if (pl->slot[i]->slot_num == slot_num)
        {
            pl->slot[i]->car = car;
            pl->num_of_car++;
            return;
        }
    }
}

void exitParkingLot(parkingLot *pl, Car *&car, int slot_num)
{

    // find the slot
    for (int i = 0; i < MAX_PARKING_SLOT; i++)
    {
        if (pl->slot[i]->slot_num == slot_num)
        {
            // return the car to pay
            car = pl->slot[i]->car;
            pl->slot[i]->car = NULL;
            pl->slot[i]->slotEmpty = true;
            pl->num_of_car--;
            return ;
        }
    }
}

bool lotFull(parkingLot *pl)
{
    return pl->num_of_car == MAX_PARKING_SLOT;
}
bool lotEmpty(parkingLot *pl)
{
    return pl->num_of_car == 0;
}

int findEmptySlot(parkingLot *pl, int &SlotNumTheOnly)
{
    if (lotFull(pl))
    {
        printf("This Lot is Full! please queue \n");
        return 0;
    }
    else
    {
        // print the empty slot out
        int count;
        int slotNum;
        printf("The empty slot is:\n");
        for (int i = 0; i < MAX_PARKING_SLOT; i++){
            if(pl->slot[i]->slotEmpty == true){
                count++;
                slotNum = pl->slot[i]->slot_num;
                printf("%d\t", pl->slot[i]->slot_num);
            }
        }
        //if there is only one car,return the slot number to make enterParkingLot()  park without choosing
        if(count == 1){
            SlotNumTheOnly =slotNum;
        }
        return count;
    }
}