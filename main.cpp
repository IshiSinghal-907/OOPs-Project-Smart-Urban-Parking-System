#include <iostream>
#include <vector>
#include <memory>
#include "SlotState.h"
#include "PricingStrategy.h"

using namespace std;

class ParkingSlot {
private:
    int id;
    unique_ptr<SlotState> state;
public:
    ParkingSlot(int _id) : id(_id), state(make_unique<AvailableState>()) {}
    
    void setState(unique_ptr<SlotState> newState) {
        state = move(newState);
    }
    
    void process() {
        state->handleVehicle(*this);
    }
    
    int getId() { return id; }
};

// State Transition logic
void AvailableState::handleVehicle(ParkingSlot& slot) {
    cout << "Vehicle entering Slot " << slot.getId() << ". Status: OCCUPIED" << endl;
    slot.setState(make_unique<OccupiedState>());
}

void OccupiedState::handleVehicle(ParkingSlot& slot) {
    cout << "Vehicle exiting Slot " << slot.getId() << ". Status: AVAILABLE" << endl;
    slot.setState(make_unique<AvailableState>());
}

int main() {
    // Initialize 5 slots
    vector<unique_ptr<ParkingSlot>> lot;
    for(int i = 1; i <= 5; ++i) lot.push_back(make_unique<ParkingSlot>(i));

    unique_ptr<PricingStrategy> peakPricing = make_unique<PeakHourStrategy>();
    unique_ptr<PricingStrategy> normalPricing = make_unique<NormalStrategy>();

    // Test Set 1: Entry
    lot[0]->process(); 
    lot[1]->process();

    // Test Set 2: Exit with Peak Pricing
    lot[0]->process();
    cout << "Slot 1 Fee (2 hrs, Peak): $" << peakPricing->calculate(2) << "\n" << endl;

    // Test Set 3: Entry for multiple slots
    lot[2]->process();
    lot[3]->process();
    lot[4]->process();

    // Test Set 4: Exit with Normal Pricing
    lot[2]->process();
    cout << "Slot 3 Fee (3 hrs, Normal): $" << normalPricing->calculate(3) << "\n" << endl;

    // Test Set 5: Sequential Exit
    lot[3]->process();
    lot[4]->process();

    return 0;
}
