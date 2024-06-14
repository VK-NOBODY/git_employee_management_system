//
// Created by VULCA on 13/6/2024.
//
#include "worker_manager.h"

void WorkerManager::show_menu() {
    cout << "********************************************************************************" << endl;
    cout << "*****************************欢迎使用职工管理系统*****************************" << endl;
    cout << "*****************************0.退出管理程序***********************************" << endl;
    cout << "*****************************1.添加职工信息***********************************" << endl;
    cout << "*****************************2.显示职工信息***********************************" << endl;
    cout << "*****************************3.删除职工信息***********************************" << endl;
    cout << "*****************************4.修改职工信息***********************************" << endl;
    cout << "*****************************5.查找职工信息***********************************" << endl;
    cout << "*****************************6.排序职工信息***********************************" << endl;
    cout << "*****************************7.清空职工信息***********************************" << endl;
    cout << "********************************************************************************" << endl;
}

void WorkerManager::exit_system() {
    cout << "欢迎下次使用职工管理系统" << endl;
    exit(0);
}

void WorkerManager::add_employee() {
    cout << "请输入添加职工的数量：" << endl;
    int add_number = 0;
    cin >> add_number;
    if (add_number > 0) {
        //添加数组
        //计算添加新空间大小
        int new_size = this->employee_count + add_number;
        //开辟新空间
        Worker **new_space = new Worker *[new_size];
        //遍历原空间，将数据拷贝到新空间
        if (this->employee != nullptr) {
            for (int i = 0; i < this->employee_count; i++) {
                new_space[i] = this->employee[i];
            }
        }
        for (int i = 0; i < add_number; ++i) {
            int worker_id;//职工编号
            string worker_name;//职工姓名
            int department_select;//岗位选择
            cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
            cin >> worker_id;
            cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
            cin >> worker_name;
            cout << "请选择职工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> department_select;
            Worker *worker = nullptr;
            switch (department_select) {
                case 1: {
                    worker = new GeneralStaff(worker_id, worker_name, 1);
                    break;
                }
                case 2: {
                    worker = new Manager(worker_id, worker_name, 2);
                    break;
                }
                case 3: {
                    worker = new Boss(worker_id, worker_name, 3);
                    break;
                }
                default: {
                    cout << "输入有误，请重新输入" << endl;
                    break;
                }
            }
            new_space[this->employee_count + i] = worker;//创建职工职责,保存到数组中
        }
        delete[]this->employee;//释放原有空间
        this->employee = new_space;//更改新空间指向
        this->employee_count = new_size;//更新新的职工人数
        cout << "成功添加" << add_number << "名职工" << endl;//提示成功添加了多少名职工
        system("pause");
        system("cls");
    } else {
        cout << "输入有误，请重新输入" <<
             endl;
        WorkerManager::add_employee();
    }
}



