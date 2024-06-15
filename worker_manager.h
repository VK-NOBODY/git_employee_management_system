//
// Created by VULCA on 13/6/2024.
//
#pragma once

#include "iostream"
#include "worker.h"
#include "general_staff.h"
#include "manager.h"
#include "boss.h"
#include "fstream"

#define FILE_NAME "employee_file.txt"

using namespace std;

class WorkerManager {
public:
    WorkerManager();

    void show_menu();

    void exit_system();

    //记录职工人数
    int employee_count = 0;
    //职工数组指针
    Worker **employee = nullptr;

    //添加职工
    void add_employee();

    //保存文件
    void save();

    //判断文件是否为空
    bool is_file_empty;

    //统计文件中的人数
    int get_employee_count();

    ~WorkerManager();

};