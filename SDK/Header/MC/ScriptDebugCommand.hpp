// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptDebugCommand {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTDEBUGCOMMAND
public:
    class ScriptDebugCommand& operator=(class ScriptDebugCommand const&) = delete;
    ScriptDebugCommand(class ScriptDebugCommand const&) = delete;
    ScriptDebugCommand() = delete;
#endif

public:
    /*0*/ virtual ~ScriptDebugCommand();
    /*1*/ virtual void execute(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI static void setup(class CommandRegistry&, class IScriptDebugger*, class std::optional<struct ScriptSettings> const&);

protected:

private:
    MCAPI void _handleDebugger(class CommandOutput&) const;
    MCAPI static class std::optional<unsigned short> sForcedPort;
    MCAPI static class IScriptDebugger* sScriptDebugger;

};