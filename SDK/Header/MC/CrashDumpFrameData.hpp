// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct CrashDumpFrameData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CRASHDUMPFRAMEDATA
public:
    struct CrashDumpFrameData& operator=(struct CrashDumpFrameData const&) = delete;
    CrashDumpFrameData(struct CrashDumpFrameData const&) = delete;
    CrashDumpFrameData() = delete;
#endif

public:
    MCAPI CrashDumpFrameData(int, int, unsigned __int64, float, float, float, float);

protected:

private:

};