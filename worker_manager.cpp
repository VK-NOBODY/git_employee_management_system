//
// Created by VULCA on 13/6/2024.
//
#include "worker_manager.h"

WorkerManager::WorkerManager() {
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->employee_count = 0;
        this->employee = nullptr;
        this->is_file_empty = true;
        ifs.close();
        return;
    }
    //2.文件存在,数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->employee_count = 0;
        this->employee = nullptr;
        this->is_file_empty = true;
        ifs.close();
        return;
    }
    //3.文件存在,数据不为空
    this->employee_count = get_employee_count();
    cout << "职工人数为:" << this->employee_count << endl;
    this->employee = new Worker *[this->employee_count];
    this->initialization_employee();
//    this->show_employee();
    ifs.close();
    return;
}

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
//    ofstream ofs;
//    ofs.open(FILE_NAME, ios::out);
//    ofs.close();
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
        int k = 0;
        for (int i = 0; i < add_number; ++i) {
            int worker_id;//职工编号
            string worker_name;//职工姓名
            int department_select;//岗位选择
            cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
            cin >> worker_id;
            if (this->employee_count + i > 0) {
                bool exist = true;
                while (exist) { //判断职工编号是否重复
                    for (int j = 0; j < (this->employee_count) + i; ++j) {
                        if (new_space[j]->worker_id == worker_id) {
                            cout << "该职工编号已存在，请重新输入：" << endl;
                            cin >> worker_id;
                            exist = true;
                            break;
                        } else {
                            exist = false;
                        }
                    }
                }
            }
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
        this->save();
        system("pause");
        system("cls");
    } else {
        cout << "输入有误，请重新输入" <<
             endl;
        WorkerManager::add_employee();
    }
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILE_NAME, ios::out);
    if (!ofs.is_open()) {
        cout << "文件打开失败" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < this->employee_count; ++i) {
        ofs << this->employee[i]->worker_id << " " << this->employee[i]->worker_name << " "
            << this->employee[i]->department_id << endl;
    }
    ofs.close();
    cout << "保存成功" << endl;
}

int WorkerManager::get_employee_count() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    int worker_id;
    string worker_name;
    int department_id;
    int number = 0;
    while (ifs >> worker_id && ifs >> worker_name && ifs >> department_id) {
        ++number;
    }
    return number;
}

void WorkerManager::initialization_employee() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    int worker_id;
    string worker_name;
    int department_id;
    int number = 0;
    while (ifs >> worker_id && ifs >> worker_name && ifs >> department_id) {
        Worker *worker = nullptr;
        switch (department_id) {
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
                cout << "初始化员工列表失败" << endl;
                break;
            }
        }
        this->employee[number] = worker;
        ++number;
    }
    ifs.close();
}

void WorkerManager::show_employee() {
    if (this->employee_count == 0) {
        cout << "当前没有职工信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < this->employee_count; ++i) {
        this->employee[i]->show_info();
    }
    system("pause");
    system("cls");
}

bool WorkerManager::is_employee_exist(int temp_worker_id) {
    bool is_exist = false;
    for (int i = 0; i < this->employee_count; ++i) {
        if (this->employee[i]->worker_id == temp_worker_id) {
            is_exist = true;
            break;
        }
    }
    return is_exist;
}

void WorkerManager::delete_employee() {
    if (this->employee_count == 0) {
        cout << "当前没有职工信息" << endl;
        return;
    } else {
        this->show_employee();
    }
    cout << "请输入要删除的职工编号：" << endl;
    int worker_id;
    cin >> worker_id;
    if (is_employee_exist(worker_id)) {
        Worker **new_space = new Worker *[this->employee_count - 1];
        for (int i = 0; i < this->employee_count; ++i) {
            if (this->employee[i]->worker_id != worker_id) { new_space[i] = this->employee[i]; }
            else if (this->employee[i]->worker_id == worker_id) {
                continue;
            } else {
                new_space[i] = this->employee[i + 1];
            }
        }
        delete[]this->employee;
        this->employee = new_space;
        this->employee_count--;
        this->save();
        cout << "删除成功" << endl;
    } else {
        cout << "该职工不存在" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::modify_employee() {
    if (this->employee_count == 0) {
        cout << "当前没有职工信息" << endl;
        system("pause");
        system("cls");
        return;
    } else {
        this->show_employee();
    }
    cout << "请输入要修改的职工编号：" << endl;
    int worker_id;
    cin >> worker_id;
    if (is_employee_exist(worker_id)) {
        int new_worker_id;
        int new_department_id;
        string new_worker_name;
        cout << "请输入新的职工编号：" << endl;
        cin >> new_worker_id;
        bool exist = true;
        while (exist) {//判断职工编号是否重复
            for (int i = 0; i < this->employee_count; ++i) {
                if (this->employee[i]->worker_id == new_worker_id) {
                    cout << "该职工编号已存在，请重新输入：" << endl;
                    cin >> new_worker_id;
                    exist = true;
                    break;
                } else {
                    exist = false;
                }
            }
        }
        cout << "请输入新的职工姓名：" << endl;
        cin >> new_worker_name;
        cout << "请输入新的职工岗位：" << endl;
        cout << "1.普通职工" << endl;
        cout << "2.经理" << endl;
        cout << "3.老板" << endl;
        cin >> new_department_id;
        Worker *worker = nullptr;
        switch (new_department_id) {
            case 1: {
                worker = new GeneralStaff(new_worker_id, new_worker_name, 1);
                break;
            }
            case 2: {
                worker = new Manager(new_worker_id, new_worker_name, 2);
                break;
            }
            case 3: {
                worker = new Boss(new_worker_id, new_worker_name, 3);
                break;
            }
            default: {
                cout << "修改职工信息失败" << endl;
                return;
            }
        }
        for (int i = 0; i < this->employee_count; ++i) {
            if (this->employee[i]->worker_id == worker_id) {
                this->employee[i] = worker;
                break;
            }
        }
        cout << "修改职工信息成功" << endl;
        this->save();
    } else {
        cout << "该职工编号不存在,请重新输入" << endl;
        this->modify_employee();
    }
//    system("pause");
//    system("cls");
}

void WorkerManager::find_employee() {
    if (this->employee_count == 0) {
        cout << "当前没有职工信息" << endl;
        system("pause");
        return;
    }
    cout << "请输入查找方式(1.按照职工编号查找;2.按照职工名字查找;3.返回上一级菜单)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        int worker_id;
        cout << "请输入职工编号：" << endl;
        cin >> worker_id;
        if (is_employee_exist(worker_id)) {
            for (int i = 0; i < this->employee_count; ++i) {
                if (this->employee[i]->worker_id == worker_id) {
                    this->employee[i]->show_info();
                }
            }
        } else {
            cout << "该职工编号不存在,请重新开始查找" << endl;
            system("pause");
            system("cls");
            this->find_employee();
        }
    } else if (choice == 2) {
        string worker_name;
        cout << "请输入职工名字：" << endl;
        cin >> worker_name;
        bool is_exist = false;
        for (int i = 0; i < this->employee_count; ++i) {
            if (this->employee[i]->worker_name == worker_name) {
                this->employee[i]->show_info();
                is_exist = true;
            }
        }
        if (!is_exist) {
            cout << "该职工名字不存在,请重新开始查询" << endl;
            system("pause");
            system("cls");
            this->find_employee();
            return;
        }
    } else if (choice == 3) {
        return;
    } else {
        cout << "输入错误，请重新输入" << endl;
        this->find_employee();
    }
}

void WorkerManager::sort_employee() {
    if (this->employee_count == 0) {
        cout << "当前没有职工信息" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请选择排序方式(1.按照职工编号升序排序;2.按照职工编号降序排序;3.返回上一级菜单)" << endl;
    int choice;
    cin >> choice;
    if (choice == 2) {
        for (int i = 0; i < this->employee_count; ++i) {
            for (int j = i + 1; j < this->employee_count; ++j) {
                if (this->employee[j]->worker_id > this->employee[i]->worker_id) {
                    Worker *temp = this->employee[j];
                    this->employee[j] = this->employee[i];
                    this->employee[i] = temp;
                }
            }
        }
        this->save();
        this->initialization_employee();
        this->show_employee();
        system("cls");
    } else if (choice == 1) {
        for (int i = 0; i < this->employee_count; ++i) {
            for (int j = i + 1; j < this->employee_count; ++j) {
                if (this->employee[j]->worker_id < this->employee[i]->worker_id) {
                    Worker *temp = this->employee[j];
                    this->employee[j] = this->employee[i];
                    this->employee[i] = temp;
                }
            }
        }
        this->save();
        this->initialization_employee();
        this->show_employee();
        system("cls");
    } else if (choice == 3) {
        return;
    }
}

void WorkerManager::clear_employee() {
    cout << "是否确认清空所有职工信息(y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        ofstream ofs;
        ofs.open(FILE_NAME, ios::trunc);
        ofs.close();
        if (this->employee != nullptr) {
            for (int i = 0; i < this->employee_count; ++i) {
                delete this->employee[i];
                this->employee[i] = nullptr;
            }
            delete[] this->employee;
            this->employee = nullptr;
        }
        this->employee_count = 0;
        cout << "清空成功" << endl;
        system("pause");
        system("cls");
    }
}

WorkerManager::~WorkerManager() {

}





