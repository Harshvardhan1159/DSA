class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    unordered_map<int, int> cancelled; // 0 = active, 1 = cancelled

    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
        cancelled[riderId] = 0;
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // Remove cancelled riders from the front
        while (!riders.empty() && cancelled[riders.front()] == 1) {
            riders.pop();
        }

        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }

        int riderId = riders.front();
        riders.pop();

        int driverId = drivers.front();
        drivers.pop();

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        if (cancelled.count(riderId)) {
            cancelled[riderId] = 1;
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */