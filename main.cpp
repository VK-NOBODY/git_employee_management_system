#include "worker_manager.h"
#include "worker.h"
#include "general_staff.h"
#include "manager.h"
#include "boss.h"

int main() {
//    Worker *worker_general_staff = new GeneralStaff(1, "Nobody", 1);
//    worker_general_staff->show_info();
//    delete worker_general_staff;
//    worker_general_staff = nullptr;
//    Worker *worker_manager = new Manager(2, "Somebody", 2);
//    worker_manager->show_info();
//    delete worker_manager;
//    worker_manager = nullptr;
//    Worker *worker_boss = new Boss(3, "Anybody", 3);
//    worker_boss->show_info();
//    delete worker_boss;
//    worker_boss = nullptr;
    int choice = 0;
    while (true) {
        WorkerManager worker_manager;
        worker_manager.show_menu();
        cout << "请输入你的选项: " << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                worker_manager.exit_system();
                return 0;
            case 1:
                worker_manager.add_employee();
                break;
            case 2:
                worker_manager.show_employee();
                break;
//            case 3:
//                worker_manager.delete_worker();
//                break;
//            case 4:
//                worker_manager.modify_worker();
//                break;
//            case 5:
//                worker_manager.find_worker();
//                break;
//            case 6:
//                worker_manager.sort_worker();
//                break;
//            case 7:
//                worker_manager.clear_worker();
//                break;
            default:
                cout << "請輸入正確的選項" << endl;
        }
    }
    return 0;
}
