#include <iostream>

struct Student {
    size_t id_;
    std::string name_;
    uint8_t age_;

    Student(int id, std::string_view name, uint8_t age)
        : id_{ id }, name_{ name }, age_{ age } {}
};