// Speed: 92.85%
// Memory: 71.13%

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;

        for (int i = 0; i < groupSizes.size(); i++) {
            auto it = mp.find(groupSizes[i]);
            if (it == mp.end()) {
                mp.insert(pair<int, vector<int>>(groupSizes[i], vector<int>(1, i)));
            } else {
                it->second.push_back(i);
            }
        }

        vector<vector<int>> v;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() > it->first) {
                vector<int> subv;
                for (int i = 0; i < it->second.size(); i++) {
                    subv.push_back(it->second[i]);
                    if ((i + 1) % it->first == 0) {
                        if (!subv.empty()) {
                            v.push_back(subv);
                        }
                        subv.clear();
                    }
                }
            } else {
                v.push_back(it->second);
            }
        }

        return v;
    }
};