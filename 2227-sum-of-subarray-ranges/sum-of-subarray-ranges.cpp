// class Solution {
// public:
//     // Next Smaller Element
//     vector<int> findNSE(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for(int i = n - 1; i >= 0; i--) {
//             while(!st.empty() && arr[st.top()] >= arr[i]) {
//                 st.pop();
//             }
//             nse[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return nse;
//     }

//     // Previous Smaller or Equal Element
//     vector<int> findPSEE(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> psee(n);
//         stack<int> st;
//         for(int i = 0; i < n; i++) {
//             while(!st.empty() && arr[st.top()] > arr[i]) {
//                 st.pop();
//             }
//             psee[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return psee;
//     }

//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int mod = 1e9 + 7;
//         long long mins = 0;

//         vector<int> nse = findNSE(arr);
//         vector<int> psee = findPSEE(arr);

//         for(int i = 0; i < n; i++) {
//             long long left = i - psee[i];
//             long long right = nse[i] - i;
//             mins = (mins + (left * right % mod) * arr[i] % mod) % mod;
//         }

//         return mins;
//     }

//     // ---------------- SUM OF SUBARRAY MAX ----------------
//     vector<int> findNGE(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nge(n);
//         stack<int> st;
//         for(int i = n - 1; i >= 0; i--) {
//             while(!st.empty() && arr[st.top()] <= arr[i]) {
//                 st.pop();
//             }
//             nge[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return nge;
//     }

//     vector<int> findPGEE(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pgee(n);
//         stack<int> st;
//         for(int i = 0; i < n; i++) {
//             while(!st.empty() && arr[st.top()] < arr[i]) {
//                 st.pop();
//             }
//             pgee[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return pgee;
//     }

//     int sumSubarrayMaxs(vector<int>& arr) {
//         int n = arr.size();
//         int mod = 1e9 + 7;
//         long long maxs = 0;

//         vector<int> nge = findNGE(arr);
//         vector<int> pgee = findPGEE(arr);

//         for(int i = 0; i < n; i++) {
//             long long left = i - pgee[i];
//             long long right = nge[i] - i;
//             maxs = (maxs + (left * right % mod) * arr[i] % mod) % mod;
//         }

//         return maxs;
//     }

//     long long subArrayRanges(vector<int>& nums) {
//         return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums) );
//     }
// };
class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller(n), prevSmaller(n);
        stack<int> st;

        // Next Smaller (>= for duplicates)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Prev Smaller (strict >)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            res += left * right * 1LL * arr[i];
        }
        return res;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextGreater(n), prevGreater(n);
        stack<int> st;

        // Next Greater (<= for duplicates)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // Prev Greater (strict <)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            res += left * right * 1LL * arr[i];
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
