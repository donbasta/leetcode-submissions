class FoodRatings {
public:
    map<string, set<pair<int, string>>> mp;
    map<string, int> rating;
    map<string, string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            rating[foods[i]] = ratings[i];
            cui[foods[i]] = cuisines[i];
            mp[cui[foods[i]]].emplace(-rating[foods[i]], foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        mp[cui[food]].erase(make_pair(-rating[food], food));
        rating[food] = newRating;
        mp[cui[food]].emplace(-rating[food], food);
    }

    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */