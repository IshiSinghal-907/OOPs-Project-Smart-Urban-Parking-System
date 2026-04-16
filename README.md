# Smart Urban Parking Simulation (OOPS Project)
A high-performance urban parking management simulation implemented in C++. This project demonstrates the application of advanced Object-Oriented Programming (OOP) design patterns to solve real-world logic complexities.

## 1. Problem Statement
Urban environments face significant traffic congestion due to inefficient parking management. Traditional systems rely on rigid `if-else` logic or simple boolean flags to track availability, making them hard to scale or modify (e.g., adding a "Maintenance" or "Reserved" status). There is a need for a dynamic, event-driven simulation that handles real-time state transitions, various pricing strategies, and automated dashboard updates.

## 2. Objective
* Implement a scalable parking system using the **State Design Pattern** to manage slot transitions.
* Use the **Observer Pattern** to update a central dashboard whenever a slot status changes.
* Apply the **Strategy Pattern** for dynamic fee calculation based on vehicle type and time of day.
* Adhere to **SOLID principles**, specifically the **Open-Closed Principle**.

## 3. Data (Data Fields)
* **ParkingSlot:** `id`, `currentState` (Pointer to SlotState).
* **Vehicle:** `licensePlate`, `type` (Car, Bike, Truck), `entryTime`.
* **ParkingDashboard:** `totalAvailable`, `totalOccupied`.
* **FeeCalculator:** `Strategy` (Peak, Weekend, Member).

## 4. Data Structures Used
* **`std::vector<ParkingSlot*>`**: To store the collection of slots in the parking lot.
* **`std::map<string, ParkingSlot*>`**: For $O(1)$ lookup of occupied slots by license plate during exit.
* **Smart Pointers (`std::unique_ptr`)**: To ensure automatic memory management and prevent leaks in polymorphic hierarchies.

## 5. Algorithm Design
1.  **Entry:** The `ParkingManager` (Singleton) searches for a slot in `AvailableState`.
2.  **State Transition:** When a vehicle enters, the slot's `process()` method is called. The `AvailableState` object transitions the slot to `OccupiedState`.
3.  **Notification:** The slot notifies the `ParkingDashboard` (Observer) to update the real-time count of free spots.
4.  **Exit:** The system identifies the slot via the license plate, triggers the `FeeCalculator` (Strategy), and transitions the state back to `Available`.

## 6. Optimization Techniques
* **Elimination of Conditional Logic:** By using the State Pattern, we replace complex `if-else` blocks with polymorphic calls, fulfilling the **Open-Closed Principle**.
* **Decoupled Pricing:** The Strategy Pattern allows swapping pricing logic (e.g., Peak vs. Normal) at runtime without modifying the `ParkingSession` class.
* **Memory Safety:** Implementation uses RAII principles and smart pointers to manage object lifetimes efficiently.

## 7. Implementation
The project is implemented in **C++** utilizing:
- Polymorphism and Virtual Functions.
- Interface-based design for States and Strategies.
- Encapsulation of state-specific behavior.

## 🚀 Key Features
- **State Design Pattern:** Manages parking slot transitions (Available, Occupied, Reserved) without messy conditional logic.
- **Strategy Design Pattern:** Implements pluggable pricing models (Peak Hour, Weekend, Member Discount) that can be swapped at runtime.
- **Observer Design Pattern:** Provides real-time updates to a central dashboard when slot statuses change.
- **SOLID Principles:** Built with the Open-Closed Principle in mind, allowing for new states or vehicle types to be added with zero changes to existing core logic.

## 🛠️ Tech Stack
- **Language:** C++
- **Concepts:** Polymorphism, Dynamic Dispatch, Smart Pointers (Memory Management).

## 📂 Project Structure
- `main.cpp`: Entry point and simulation logic.
- `SlotState.h`: Abstract interface and concrete implementations for the State pattern.
- `PricingStrategy.h`: Interface for the Strategy pattern implementations.

## 9. Time and Space Complexity
* **Time Complexity:** * State Transition: $O(1)$
    * Fee Calculation: $O(1)$
    * Slot Lookup: $O(\log N)$ (using Map) or $O(N)$ (using Vector).
* **Space Complexity:** $O(N)$ where $N$ is the number of parking slots.

## 10. Conclusion
This simulation proves that applying Design Patterns like **State**, **Observer**, and **Strategy** creates a robust and flexible system. Adding a new state (like "Blocked for Cleaning") now requires zero changes to the existing code, demonstrating high-quality software architecture.
