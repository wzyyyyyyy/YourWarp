// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ScriptActorEvent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTACTOREVENT
public:
    struct ScriptActorEvent& operator=(struct ScriptActorEvent const&) = delete;
    ScriptActorEvent(struct ScriptActorEvent const&) = delete;
    ScriptActorEvent() = delete;
#endif

public:
    MCAPI ScriptActorEvent(class Scripting::WeakTypedObjectHandle<class ScriptActor>);

protected:

private:

};