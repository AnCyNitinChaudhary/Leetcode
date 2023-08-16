class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //This is a good question and understood by me from the striver.
        // deque<int>dq;
        // vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //     if(!dq.empty()&&i>=k&&dq.front()==nums[i-k])dq.pop_front();//if go out of window
        //     while(!dq.empty()&&dq.back()<nums[i])dq.pop_back();//to maintain the decreasing order
        //     dq.push_back(nums[i]);//to put in deque as all smaller than this are removed
        //     //If first window hits, answer have to be updated for each iteration because in each iteration we will encounter with the new window.
        //     if(i>=k-1)ans.push_back(dq.front());
        // }
        // return ans;





























        //Solving this question again using dequeue.
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty()&&i>=k&&dq.front()==nums[i-k])dq.pop_front();
            while(!dq.empty()&&dq.back()<nums[i])dq.pop_back();
            dq.push_back(nums[i]);
            if(i>=k-1)ans.push_back(dq.front());
        }
        return ans;
    }
};