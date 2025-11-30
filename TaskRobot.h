#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ======= Task 类 =======
class Task {
private:
    int id;
    string desc;
    string state; // "待执行" 或 "已执行"

public:
    Task(int _id = 0, string _desc = "")
        : id(_id), desc(_desc), state("待执行") {}

    void execute() { state = "已执行"; }

    int getId() const { return id; }
    string getDesc() const { return desc; }
    string getState() const { return state; }
};

// ======= Robot 类 =======
class Robot {
private:
    string name;
    vector<Task> tasks;

public:
    Robot(string _name = "") : name(_name) {}

    void addTask(int id, const string& desc) {
        tasks.emplace_back(id, desc);
    }

    void undoTask() {
        if (!tasks.empty()) tasks.pop_back();
    }

    void executeTasks() {
        for (auto& t : tasks) t.execute();
    }

    void showTasks() const {
        for (const auto& t : tasks) {
            cout << "任务ID: " << t.getId()
                 << ", 描述: " << t.getDesc()
                 << ", 状态: " << t.getState() << endl;
        }
    }
};
