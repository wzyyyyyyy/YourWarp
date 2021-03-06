// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class InMemoryWritableFile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INMEMORYWRITABLEFILE
public:
    class InMemoryWritableFile& operator=(class InMemoryWritableFile const&) = delete;
    InMemoryWritableFile(class InMemoryWritableFile const&) = delete;
    InMemoryWritableFile() = delete;
#endif

public:
    /*0*/ virtual ~InMemoryWritableFile();
    /*1*/ virtual class leveldb::Status Append(class leveldb::Slice const&);
    /*2*/ virtual class leveldb::Status Close();
    /*
    inline class leveldb::Status Sync(){
        class leveldb::Status (InMemoryWritableFile::*rv)();
        *((void**)&rv) = dlsym("?Sync@InMemoryWritableFile@@UEAA?AVStatus@leveldb@@XZ");
        return (this->*rv)();
    }
    inline class leveldb::Status Flush(){
        class leveldb::Status (InMemoryWritableFile::*rv)();
        *((void**)&rv) = dlsym("?Flush@InMemoryWritableFile@@UEAA?AVStatus@leveldb@@XZ");
        return (this->*rv)();
    }
    */
    MCAPI InMemoryWritableFile(class std::shared_ptr<class InMemoryFile>);

protected:

private:

};