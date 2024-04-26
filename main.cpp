#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

struct Student {
    size_t id_;
    std::string name_;
    size_t age_;

    Student(size_t id, std::string_view name, size_t age)
        : id_{ id }, name_{ name }, age_{ age } {}
};

class StudentDB {
public:
    void Add(size_t id, const std::string_view name, size_t age) {
        students.push_back(std::make_shared<Student>(id, name, age));
    }

    void Delete(size_t id) {
        students.erase(std::remove_if(students.begin(), students.end(), [id](const auto& student) {
            return student->id_ == id;
        }), students.end());
    }

    std::shared_ptr<Student> Get(size_t id) {
        auto it{ std::find_if(students.begin(), students.end(), [id](const auto& student) {
            return student->id_ == id;
        })};

        if (it != students.end()) {
            return *it;
        }
        else {
            return nullptr;
        }
    }

    void PrintAllNames() {
        for (auto student : students) {
            std::cout << student->name_ << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<std::shared_ptr<Student>> students;
};


int main() {
    StudentDB db;

    db.Add(1, "Alex", 24);
    db.Add(2, "Amir", 22);
    db.Add(3, "Angel", 22);
    db.Add(4, "Alexa", 19);

    db.PrintAllNames();

    std::shared_ptr<Student> student = db.Get(3);

    if (student) {
        std::cout << "ID: " << student->id_ << std::endl;
        std::cout << "Name: " << student->name_ << std::endl;
        std::cout << "Age: " << student->age_ << std::endl;
    }
    else {
        std::cout << "Error\n";
    }

    db.Delete(1);

    db.PrintAllNames();
}