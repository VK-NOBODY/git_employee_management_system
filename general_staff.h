//
// Created by VULCA on 14/6/2024.
//
#pragma once
#include "worker.h"
class GeneralStaff : public Worker
{
public:
    GeneralStaff(int temp_worker_id, string temp_worker_name, int temp_department_id);
    virtual void show_info();
    virtual string get_dept_name();
};
