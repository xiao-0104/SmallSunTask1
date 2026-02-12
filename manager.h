#ifndef MANAGER
#define MANAGER
#include"student.h"
#include<algorithm>
#include<vector>

class manager{
public:
    //学生vector容器：
    std::vector<student> students;

    //功能实现函数：
    //1.添加学生信息
    void AddStudent(int id, std::string name, int score){
        students.emplace_back(id, name, score);
    }

    //2.删除学生信息
    void RemoveStudent(int id){
        students.erase(std::remove_if(students.begin(), students.end(), [id](const student& s){
            return s.id == id;
        }), students.end());
    }

    //3.显示学生信息
    void DisplayStudents(){
        for(const auto& s : students){
            s.display();
        }
    }

    //4.根据成绩排序学生信息
    void SortStudentsByScore(){
        std::sort(students.begin(), students.end(), [](const student& a, const student& b){
            return a.score > b.score; // 降序排序
        });
    }
    
    //5.根据ID查找学生信息
    student* FindStudentById(int id){
        for(auto& s : students){
            if(s.id == id){
                return &s; // 返回学生对象的指针
            }
        }
        return nullptr; // 未找到返回nullptr
    }
};

#endif