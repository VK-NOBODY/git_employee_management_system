//
// Created by VULCA on 13/6/2024.
//
#pragma once

#include "iostream"
#include "worker.h"
#include "general_staff.h"
#include "manager.h"
#include "boss.h"

using namespace std;

class WorkerManager {
public:
    void show_menu();

    void exit_system();

    //记录职工人数
    int employee_count = 0;
    //职工数组指针
    Worker **employee = nullptr;

    //添加职工
    void add_employee();

//    virtual ~WorkerManager() {
//    }
};