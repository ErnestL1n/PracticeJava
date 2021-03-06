// O(nlogn) sort
class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary),end(salary));
        return (double)accumulate(begin(salary)+1,end(salary)-1,0)/(salary.size()-2);
    }
};


// with std::min_element and std::max_element
class Solution {
public:
    double average(vector<int>& salary) {
        return (accumulate(begin(salary),end(salary),0.0)-*max_element(begin(salary),end(salary))-*min_element(begin(salary),end(salary)))/(salary.size()-2);
    }
};


// O(n)
class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0.0;
        int mins=INT_MAX,maxs=INT_MIN;
        for(auto s:salary){
            mins=min(mins,s);
            maxs=max(maxs,s);
            sum+=s;
        }
        return (sum-mins-maxs)/(salary.size()-2);
    }
};