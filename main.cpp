#include"manager.h"

int main(){
    manager m;
    while(true){
        system("cls"); // 清屏
        std::cout << R"(//  学生成绩管理系统菜单  //
        0.退出系统
        1.添加学生信息
        2.删除学生信息
        3.显示学生信息
        4.根据成绩排序学生信息
        5.根据ID查找学生信息 )" << std::endl;
        int choice = -1;
        std::cin >> choice;        
        switch(choice){
            case 0:
                std::cout << "退出系统，感谢使用！" << std::endl;
                return 0;
            case 1: {
                int id, score;
                std::string name;
                std::cout << "请输入学生ID、姓名和成绩：" << std::endl;
                std::cin >> id >> name >> score;
           //     std::cin.ignore();  清除输入缓冲区
                m.AddStudent(id, name, score);
                break;
            }
            case 2: {
                int id;
                std::cout << "请输入要删除的学生ID：" << std::endl;
                std::cin >> id;
                m.RemoveStudent(id);
                break;
            }
            case 3:
                m.DisplayStudents();
                system("pause");
                break;
            case 4:
                m.SortStudentsByScore();
                break;
            case 5: {
                int id;
                std::cout << "请输入要查找的学生ID：" << std::endl;
                std::cin >> id;
                student* s = m.FindStudentById(id);
                if(s){
                    s->display();
                } else {
                    std::cout << "未找到学生信息。" << std::endl;
                }
                break;
            }
            default:
                std::cout << "无效的选择，请重新输入。" << std::endl;
        }
    }
}