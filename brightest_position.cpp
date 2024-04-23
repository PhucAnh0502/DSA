int findBrightestPosition(vector& lights) {

    vector<pair<int, int>> change;

    for (vector& light: lights) {

        int position = light[0], radius = light[1];

        change.push_back({position - radius, 1});

        change.push_back({position + radius + 1, -1});

    }

    

    sort(change.begin(), change.end());

    int ans = 0, curr = 0, brightest = 0;

    for (auto [position, value]: change) {

        curr += value;

        if (curr > brightest) {

            brightest = curr;

            ans = position;

        }

    }

    

    return ans;

}
