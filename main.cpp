#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Task {
    string name;
    Task* next;
};

// Head pointer
Task* head = nullptr;

// Function to add task at end
void addTask(const string& taskName) {
    Task* newTask = new Task{taskName, nullptr};

    if (head == nullptr) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newTask;
    }

    cout << "Task \"" << taskName << "\" added.\n";
}

// Function to delete a task by name
void deleteTask(const string& taskName) {
    Task* temp = head;
    Task* prev = nullptr;

    while (temp != nullptr && temp->name != taskName) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Task \"" << taskName << "\" not found.\n";
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Task \"" << taskName << "\" deleted.\n";
}

// Function to display tasks
void displayTasks() {
    if (head == nullptr) {
        cout << "No tasks to show.\n";
        return;
    }

    cout << "Your To-Do List:\n";
    Task* temp = head;
    while (temp != nullptr) {
        cout << "- " << temp->name << '\n';
        temp = temp->next;
    }
}

// Main menu
int main() {
    int choice;
    string taskName;

    do {
        cout << "\n=== To-Do List Menu ===\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear newline from input buffer

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                getline(cin, taskName);
                addTask(taskName);
                break;
            case 2:
                cout << "Enter task name to delete: ";
                getline(cin, taskName);
                deleteTask(taskName);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
