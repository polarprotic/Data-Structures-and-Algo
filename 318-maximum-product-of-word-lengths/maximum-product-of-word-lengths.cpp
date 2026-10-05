
class Solution {
public:

    bool check(string a, string b) {

        bool present[26] = {};

        for (char c : a) {
            present[c - 'a'] = true;
        }

        for (char c : b) {
            if (present[c - 'a'])
                return true;
        }

        return false;
    }

    int maxProduct(vector<string>& words) {

        vector<pair<string, int>> p;

        for (int i = 0; i < words.size(); i++) {
            p.push_back({words[i], words[i].size()});
        }

        sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int maxi = 0;

        for (int i = p.size() - 1; i >= 0; i--) {

            for (int j = i - 1; j >= 0; j--) {

                // Since sorted by length, smaller j means
                // even smaller product.
                if (p[i].second * p[j].second <= maxi)
                    break;

                if (!check(p[i].first, p[j].first)) {

                    maxi = max(
                        p[i].second * p[j].second,
                        maxi
                    );
                }
            }
        }

        return maxi;
    }
};

