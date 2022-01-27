#pragma once
#define CONFPATH "./plugins/YourWarp/setting.json"
#define DBPATH "./plugins/YourWarp/DB"
class Config;
class Logger;
class KVDB;

extern Logger logger;
extern Config config;
extern std::unique_ptr<KVDB> db;