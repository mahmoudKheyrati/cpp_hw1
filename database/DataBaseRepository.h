#pragma once

#include "data/Database.h"

class DataBaseRepository {
    static DataBase* dataBase;

public:
    static DataBase *getDataBase() ;

     ~DataBaseRepository();

};

