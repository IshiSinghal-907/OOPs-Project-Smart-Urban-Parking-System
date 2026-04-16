#ifndef SLOT_STATE_H
#define SLOT_STATE_H

#include <string>
#include <iostream>
#include <memory>

class ParkingSlot; 

class SlotState {
public:
    virtual void handleVehicle(ParkingSlot& slot) = 0;
    virtual std::string getStatus() = 0;
    virtual ~SlotState() {}
};

class AvailableState : public SlotState {
public:
    void handleVehicle(ParkingSlot& slot) override;
    std::string getStatus() override { return "Available"; }
};

class OccupiedState : public SlotState {
public:
    void handleVehicle(ParkingSlot& slot) override;
    std::string getStatus() override { return "Occupied"; }
};

#endif
