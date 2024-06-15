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

    //初始化员工
    void initialization_employee();

    //显示职工信息
    void show_employee();

    //判斷職工信息是否存在
    bool is_employee_exist(int temp_worker_id);

    //刪除职工信息
    void delete_employee();

    //修改职工信息
    void modify_employee();

    //查找职工信息
    void find_employee();

    //排序职工信息
    void sort_employee();

    //清空职工信息
    void clear_employee();

    //析构函数
    ~WorkerManager();
};