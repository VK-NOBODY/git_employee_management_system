//
// Created by VULCA on 14/6/2024.
//
#pragma once
#include "worker.h"
class Manager:public Worker {
public:
    Manager(int temp_worker_id, string temp_worker_name, int temp_department_id);
    void show_info();
    string get_dept_name();
};