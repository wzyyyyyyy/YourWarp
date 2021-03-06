// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LevelEventCoordinator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELEVENTCOORDINATOR
public:
    class LevelEventCoordinator& operator=(class LevelEventCoordinator const&) = delete;
    LevelEventCoordinator(class LevelEventCoordinator const&) = delete;
#endif

public:
    /*0*/ virtual ~LevelEventCoordinator();
    /*
    inline  ~LevelEventCoordinator(){
         (LevelEventCoordinator::*rv)();
        *((void**)&rv) = dlsym("??1LevelEventCoordinator@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI LevelEventCoordinator();
    MCAPI void registerLevelGameplayHandler(std::unique_ptr<class LevelGameplayHandler>);
    MCAPI void sendLevelAddedActor(struct LevelAddedActorEvent const&);
    MCAPI void sendLevelBiomesRegistered(class BiomeRegistry&);
    MCAPI void sendLevelBroadcast(struct LevelBroadcastEvent const&);
    MCAPI void sendLevelInitialized(class Level&);
    MCAPI void sendLevelRemovedActor(class Level&, class Actor&);
    MCAPI void sendLevelSoundBroadcast(struct LevelSoundBroadcastEvent const&);
    MCAPI void sendLevelStartLeaveGame(struct LevelStartLeaveGameEvent const&);
    MCAPI void sendLevelTick();
    MCAPI void sendLevelWeatherChanged(std::string const&, bool, bool);

protected:

private:

};