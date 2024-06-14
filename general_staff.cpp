//
// Created by VULCA on 14/6/2024.
//
#include "general_staff.h"

GeneralStaff::GeneralStaff(int temp_worker_id, string temp_worker_name, int temp_department_id) {
    this->worker_id = temp_worker_id;
    this->worker_name = temp_worker_name;
    this->department_id = temp_department_id;
    this->department_name = this->get_dept_name();
}

void GeneralStaff::show_info() {
    cout << "职工编号:" << this->worker_id << ";" << "\t职工名字:" << this->worker_name << ";" << "\t部门编号:"
         << this->department_id << "\t岗位:" << this->department_name << "\t岗位职责:" << "完成经理分配的任务" << endl;
}

string GeneralStaff::get_dept_name() {
    return "普通员工";
}