#include <vector>

class MyCalendar {
    private:
    vector<vector<int>> schedule;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(schedule.empty()) {
            schedule.push_back({start, end});
            return true;
        }

        for(int i = 0; i < schedule.size(); i++) {
            if(start == schedule[i][0] || end == schedule[i][1]) return false;
            if(start > schedule[i][0] && start < schedule[i][1]) return false;
            if(end > schedule[i][0] && end < schedule[i][1]) return false;
            if(start < schedule[i][0] && end > schedule[i][1]) return false;
        }

        schedule.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */