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
    int dfs(unordered_map<int, Employee*>& mp, int id) {
        Employee* emp = mp[id];
        int totImportance = emp->importance;

        // Recursively visit all direct subordinates
        for (int subId : emp->subordinates) {
            totImportance += dfs(mp, subId);
        }
        return totImportance;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for (int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = employees[i];
        }
        return dfs(mp, id);
    }
};
// We use a Hash Map (unordered_map) to store each employee's ID as the key and
// a pointer to their Employee object as the value.

//Map Population: It iterates through the input employees vector and populates the hash map mp so that mp[employee_id] instantly returns the Employee* pointer.

//Initiation: It calls the dfs function starting from the target id requested by the problem and returns the final calculated sum.