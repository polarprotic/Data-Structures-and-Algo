class Solution {
public:

    vector<int> next(vector<vector<int>> & store){


        


        vector<int> ans;


        for(int i = 0;i<store.back().size()-1;i++){
            int a = store.back()[i] + store.back()[i+1];
            ans.push_back(a);
        }

        ans.insert(ans.begin(), 1);
        ans.push_back(1);
        return ans;
    }

    vector<vector<int>> generate(int numRows) {


        if(numRows == 2){
            return {{1},{1,1}};
        }

        if(numRows == 1){
            return {{1}};
        }

        vector<vector<int>> store;

        store.push_back({1});
        store.push_back({1,1});


        for(int i = 1; i < numRows - 1; i++){
            store.push_back(next(store));
        }


        return store;
    }
};