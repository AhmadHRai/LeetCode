class TaskManager {
public:
    priority_queue<pair<int,int>> q;
    unordered_map<int,int> priority;
    unordered_map<int,int> owner;

    TaskManager(vector<vector<int>>& tasks) {
        for(const auto& task: tasks) {
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId, int taskId, int p) {
        q.push({p,taskId});
        priority[taskId] = p;
        owner[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        q.push({newPriority, taskId});
        priority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        priority[taskId] = -1;
    }
    
    int execTop() {
        while(!q.empty()){
            const auto task = q.top();
            q.pop();
            if(task.first == priority[task.second]) {
                priority[task.second] = -1;
                return owner[task.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */