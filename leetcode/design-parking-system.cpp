#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
 private:
    int big, medium, small;

 public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {}

    bool addCar(int carType)
    {
        switch (carType) {
            case 1:
                if (big) {
                    --big;
                    return true;
                }
                break;
            case 2:
                if (medium) {
                    --medium;
                    return true;
                }
                break;
            case 3:
                if (small) {
                    --small;
                    return true;
                }
                break;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
