class ParkingSystem {
public:
    vector<int> slot;
    ParkingSystem(int big, int medium, int small) {
        slot.resize(3);
        slot[0] = big, slot[1] = medium, slot[2] = small;
    }
    
    bool addCar(int carType) {
        if (slot[carType - 1] == 0) return false;
        slot[carType - 1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */