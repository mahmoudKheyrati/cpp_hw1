#include "DataBaseRepository.h"

DataBase *DataBaseRepository::getDataBase() {

    if (dataBase == nullptr) {
        dataBase = new DataBase();
    }
    return dataBase;
}

DataBaseRepository::~DataBaseRepository() {
    delete dataBase;
}
