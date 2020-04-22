class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> state;
        if(asteroids.empty())
            return state;
        state.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            if(!state.empty() && state.back()>0 && asteroids[i]<0)
            {
                if(state.back()>abs(asteroids[i]))
                    continue;
                else if(state.back() < abs(asteroids[i]))
                {
                    state.pop_back();
                    i--;
                }
                else
                    state.pop_back();
            }
            else
                state.push_back(asteroids[i]);
        }
        return state;
    }
};