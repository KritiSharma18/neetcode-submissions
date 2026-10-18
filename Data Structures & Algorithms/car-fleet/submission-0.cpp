class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double lastTime = 0;
        // Start from the car closest to the target
        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (time > lastTime) {
                // Can't catch the fleet ahead, so it's a new fleet
                fleets++;
                lastTime = time;
            }
            // else: it catches up and joins the fleet ahead
        }
        return fleets;
    }
};
