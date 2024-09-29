#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Task {
public:
    Task(const std::string& description) : description(description) {}
    std::string getDescription() const { return description; }

private:
    std::string description;
};

class ToDoList {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }
        std::cout << "Current tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription() << "\n";
        }
    }

    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task deleted successfully.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

private:
    std::vector<Task> tasks;
};

void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---\n";
    std::cout << "1. Add a task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete a task\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                todoList.viewTasks();
                std::cout << "Enter the number of the task to delete: ";
                size_t taskNumber;
                std::cin >> taskNumber;
                todoList.deleteTask(taskNumber);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}