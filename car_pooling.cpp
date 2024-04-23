class Solution {

public:

    bool carPooling(vector& trips, int capacity) {

        int farthest = 0;

        for (vector& trip: trips) {

            farthest = max(farthest, trip[2]);

        }

        

        vector arr(farthest + 1);

        for (vector& trip: trips) {

            int value = trip[0], left = trip[1], right = trip[2];

            arr[left] += value;

            arr[right] -= value;

        }

        

        int curr = 0;

        for (int i = 0; i < arr.size(); i++) {

            curr += arr[i];

            if (curr > capacity) {

                return false;

            }

        }

        

        return true;

    }

};
