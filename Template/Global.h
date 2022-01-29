#pragma once
#define CONFPATH "./plugins/YourWarp/setting.json"
#define DBPATH "./plugins/YourWarp/DB"

class Config;
class Logger;
class KVDB;
class Money;

extern Logger logger;
extern Config config;
extern std::unique_ptr<KVDB> db;
extern std::unique_ptr<Money> money;