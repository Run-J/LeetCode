class Solution {
public:
    int getSum(int integer)
    {
        // Take the sum of the singular numbers in each place of its digits.
        int sum = 0;
        while (integer)
        {
            sum += (integer % 10) * (integer % 10);
            integer /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        
        unordered_set<int> set;

        while (1)
        {
            int sum = getSum(n);

            if (sum ==1)
            {
                return true;
            }

            // If this sum ever occurs, we are in an infinite loop, return false.
            if (set.find(sum) != set.end()) 
            {
                return false;
            }
            else 
            {
                set.insert(sum);
            }

            n = sum;
        }

    }

};