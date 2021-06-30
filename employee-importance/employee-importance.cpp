/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &graph, unordered_map<int, int> &imp, vector<bool> &visited, int emp, int &res){
        
        visited[emp] = true;
        res += imp[emp];
        for(auto nbr: graph[emp]){
            if(!visited[nbr])
                dfs(graph, imp, visited, nbr, res);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> imp;
        
        for(int i=0; i<employees.size(); i++){
            imp[employees[i]->id] = employees[i]->importance;
            for(int j=0; j<employees[i]->subordinates.size(); j++)
                graph[employees[i]->id].push_back(employees[i]->subordinates[j]);
        }
        int res =0 ;
        vector<bool> visited(2001, false);
        dfs(graph, imp, visited, id, res);
        return res;
    }
};