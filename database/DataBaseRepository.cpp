#include "DataBaseRepository.h"

DataBase *DataBaseRepository::getDataBase() {
    static DataBase* dataBase;
    if (dataBase == nullptr) {
        dataBase = new DataBase();
    }
    return dataBase;
}
