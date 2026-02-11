// Logic:
//
// This problem asks for the number of days until a warmer temperature.
// We use a MONOTONIC DECREASING STACK.
//
// Why decreasing?
// - We are looking for the "next greater element" to the right.
// - If today's temperature is higher than the temperature at the index
//   stored at the top of the stack, then we have found the answer
//   for that previous day.
//
// Stack property:
// - The stack stores INDICES, not values.
// - Temperatures of indices in the stack are strictly decreasing
//   from bottom to top.
// - Each index in the stack is waiting to find its next warmer day.
//
// Algorithm:
// 1. Iterate through the array from left to right.
// 2. While the stack is not empty AND the current temperature
//    is higher than the temperature at stack top:
//        - Pop the index.
//        - Compute the difference in days.
// 3. Push current index into the stack.
// 4. Any index left in the stack has no warmer future day,
//    and remains 0 (default initialized).
//
// Time Complexity: O(n)
// Each index is pushed and popped at most once.
//

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;  // store indices
        vector<int> result(temperatures.size(), 0); // default 0

        for (int i = 0; i < temperatures.size(); i++) {

            // If current temperature is warmer,
            // resolve previous colder days
            while (!st.empty() && 
                   temperatures[i] > temperatures[st.top()]) {

                int prevIndex = st.top();
                st.pop();

                // number of days waited
                result[prevIndex] = i - prevIndex;
            }

            // push current index as a candidate
            // waiting for a warmer temperature
            st.push(i);
        }

        // After traversing the entire temeratures array,
        // Any index left in the stack has no warmer future day, and remains 0 (already default initialized).
      
        return result;
    }
};
