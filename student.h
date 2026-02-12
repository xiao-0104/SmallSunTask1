#ifndef STUDENT
#define STUDENT
#include<string>
#include<iostream>

class student{
public:
    //学生信息：
    int id;
    std::string name;
    int score;

    //构造函数：
    student(int a, std::string b, int c) : id(a), name(b), score(c) {} 

    //显示学生信息：
    void display() const {
        std::cout << "ID: " << id << "  NAME: " << name << "  score: " << score << std::endl;
    }
};

#endif  