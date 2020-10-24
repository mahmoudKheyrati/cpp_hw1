#pragma once

#include "data/Database.h"

class DataBaseRepository {

public:
    static DataBase *getDataBase() ;

    virtual ~DataBaseRepository();

};

