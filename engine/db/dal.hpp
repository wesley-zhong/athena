//
// Created by zhongweiqi on 2025/10/18.
//

#ifndef ATHENA_DAL_HPP
#define ATHENA_DAL_HPP
#include <string>
#include "DB_Interface.h"
#include "DB_Interface_mysql.h"
#include "DB_Interface_redis.h"

namespace Dal {
    template<typename T>
    T *initDB(const char *host, const char *dbname, const char *user, const char *pswd,
              unsigned int port) {
        T *obj = new T(host, dbname, user, pswd);
        obj->connect();
        return obj;
    }

    namespace DB {
        DB_Interface *mysql;

        void init(const std::string &ip, const unsigned int port, const std::string &dbname, const std::string username,
                  const std::string password) {
            mysql = initDB<DBInterfaceMysql>(ip, port, dbname, username, password);
        }

        int execute(DBResult *result, const char *cmd, int len) {
            mysql->execute(result, cmd, len);
        }
    }

    namespace Cache {
        DB_Interface *redis;

        void init(const std::string &ip, const unsigned int port, const std::string &dbname, const std::string username,
                  const std::string password) {
            redis = Dal::initDB<DBInterfaceRedis>(ip, port, dbname, username, password);
        }
        int execute(DBResult *result, const char *cmd, int len) {
            redis->execute(result, cmd, len);
        }
    }
}
#endif //ATHENA_DAL_H
