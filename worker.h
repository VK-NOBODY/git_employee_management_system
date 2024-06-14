//
// Created by VULCA on 14/6/2024.
//
#pragma once

#include "iostream"
#include "string"

using namespace std;

class Worker {
public:
    //显示个人信息
    virtual void show_info() = 0;

    //获取岗位名称
    virtual string get_dept_name() = 0;

    //职工编号
    int worker_id;
    //职工姓名
    string worker_name;
    //岗位名称
    string department_name;
    //部门编号
    int department_id;
//    virtual ~Worker(){
//    }
};