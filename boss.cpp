//
// Created by VULCA on 14/6/2024.
//
#include "boss.h"

Boss::Boss(int temp_worker_id, std::string temp_worker_name, int temp_department_id) {
    this->worker_id = temp_worker_id;
    this->worker_name = temp_worker_name;
    this->department_id = temp_department_id;
    this->department_name = this->get_dept_name();
}

void Boss::show_info() {
    cout << "职工编号:" << this->worker_id << ";" << "\t职工名字:" << this->worker_name << ";" << "\t部门编号:"
         << this->department_id << "\t岗位:" << this->department_name << "\t岗位职责:" << "管理公司所有事务,并下发任务给经理" << endl;
}

string Boss::get_dept_name() {
    return "老板";
}