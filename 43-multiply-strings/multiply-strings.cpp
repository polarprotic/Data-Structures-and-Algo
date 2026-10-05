class Solution {
public:
    string multiply(string num1, string num2) {
        // If either number is zero, the result is zero
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        // The maximum possible length of the product is n1 + n2
        vector<int> res(n1 + n2, 0);
        
        // Multiply each digit starting from the end
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Add the multiplication result to the current position
                int sum = mul + res[i + j + 1];
                
                // Store the single digit at the current position
                res[i + j + 1] = sum % 10;
                
                // Add the carry to the next position to the left
                res[i + j] += sum / 10;
            }
        }
        
        // Convert the integer vector back to a string, skipping leading zeros
        string result = "";
        for (int num : res) {
            if (!(result.empty() && num == 0)) {
                result.push_back(num + '0');
            }
        }
        
        return result;
    }
};