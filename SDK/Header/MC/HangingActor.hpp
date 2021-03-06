// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HangingActor : public Actor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HANGINGACTOR
public:
    class HangingActor& operator=(class HangingActor const&) = delete;
    HangingActor(class HangingActor const&) = delete;
    HangingActor() = delete;
#endif

public:
    /*0*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const&);
    /*1*/ virtual void reloadHardcodedClient(enum Actor::InitializationMethod, class VariantParameterList const&);
    /*2*/ virtual ~HangingActor();
    /*3*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*4*/ virtual void __unk_vfn_0();
    /*5*/ virtual void move(class Vec3 const&);
    /*6*/ virtual float getInterpolatedHeadRot(float) const;
    /*7*/ virtual float getInterpolatedBodyYaw(float) const;
    /*8*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*9*/ virtual void __unk_vfn_1();
    /*10*/ virtual void normalTick();
    /*11*/ virtual float getRidingHeight();
    /*12*/ virtual void __unk_vfn_2();
    /*13*/ virtual void __unk_vfn_3();
    /*14*/ virtual float getCameraOffset() const;
    /*15*/ virtual void __unk_vfn_4();
    /*16*/ virtual float getBrightness(float) const;
    /*17*/ virtual void __unk_vfn_5();
    /*18*/ virtual void playerTouch(class Player&);
    /*19*/ virtual bool isPickable();
    /*20*/ virtual void __unk_vfn_6();
    /*21*/ virtual bool isSleeping() const;
    /*22*/ virtual void setSleeping(bool);
    /*23*/ virtual void __unk_vfn_7();
    /*24*/ virtual bool isBlocking() const;
    /*25*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*26*/ virtual void __unk_vfn_8();
    /*27*/ virtual bool isSurfaceMob() const;
    /*28*/ virtual void __unk_vfn_9();
    /*29*/ virtual void __unk_vfn_10();
    /*30*/ virtual void __unk_vfn_11();
    /*31*/ virtual class Actor* findAttackTarget();
    /*32*/ virtual bool isValidTarget(class Actor*) const;
    /*33*/ virtual void adjustDamageAmount(int&) const;
    /*34*/ virtual void onTame();
    /*35*/ virtual void onFailedTame();
    /*36*/ virtual bool isJumping() const;
    /*37*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*38*/ virtual bool isInvulnerableTo(class ActorDamageSource const&) const;
    /*39*/ virtual void animateHurt();
    /*40*/ virtual void onBounceStarted(class BlockPos const&, class Block const&);
    /*41*/ virtual float getPickRadius();
    /*42*/ virtual void awardKillScore(class Actor&, int);
    /*43*/ virtual enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot) const;
    /*44*/ virtual enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot) const;
    /*45*/ virtual float getArmorColorInSlot(enum ArmorSlot, int) const;
    /*46*/ virtual void setEquippedSlot(enum EquipmentSlot, class ItemStack const&);
    /*47*/ virtual class HashedString const& queryEntityRenderer() const;
    /*48*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*49*/ virtual bool canFreeze() const;
    /*50*/ virtual int getPortalWaitTime() const;
    /*51*/ virtual bool canChangeDimensions() const;
    /*52*/ virtual void __unk_vfn_12();
    /*53*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*54*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*55*/ virtual bool canBePulledIntoVehicle() const;
    /*56*/ virtual bool inCaravan() const;
    /*57*/ virtual void __unk_vfn_13();
    /*58*/ virtual bool canSynchronizeNewEntity() const;
    /*59*/ virtual void buildDebugInfo(std::string&) const;
    /*60*/ virtual int getDeathTime() const;
    /*61*/ virtual void swing();
    /*62*/ virtual void __unk_vfn_14();
    /*63*/ virtual void __unk_vfn_15();
    /*64*/ virtual float getYHeadRot() const;
    /*65*/ virtual bool isWorldBuilder() const;
    /*66*/ virtual void __unk_vfn_16();
    /*67*/ virtual bool isAdventure() const;
    /*68*/ virtual bool canDestroyBlock(class Block const&) const;
    /*69*/ virtual void setAuxValue(int);
    /*70*/ virtual void setSize(float, float);
    /*71*/ virtual void stopSpinAttack();
    /*72*/ virtual void __unk_vfn_17();
    /*73*/ virtual void __unk_vfn_18();
    /*74*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*75*/ virtual void __unk_vfn_19();
    /*76*/ virtual bool _hurt(class ActorDamageSource const&, int, bool, bool);
    /*77*/ virtual void readAdditionalSaveData(class CompoundTag const&, class DataLoadHelper&);
    /*78*/ virtual void addAdditionalSaveData(class CompoundTag&);
    /*79*/ virtual void __unk_vfn_20();
    /*80*/ virtual void _onSizeUpdated();
    /*81*/ virtual void __unk_vfn_21();
    /*82*/ virtual void setDir(int);
    /*83*/ virtual int getWidth() const = 0;
    /*84*/ virtual int getHeight() const = 0;
    /*85*/ virtual void dropItem() = 0;
    /*86*/ virtual bool placeHangingEntity(class BlockSource&, int);
    /*87*/ virtual bool wouldSurvive(class BlockSource&);
    MCAPI HangingActor(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class OwnerPtrT<struct EntityRefTraits> const&);
    MCAPI int getDirection() const;

protected:
    MCAPI void _calculateAABB();
    MCAPI void _calculateActorPositionFromPlacementPosition(class BlockPos const&);
    MCAPI bool _wouldSurvive(class BlockSource&, class BlockPos const&, bool);

private:
    MCAPI bool _canSurviveOnBlock(class BlockSource const&, class BlockPos const&, bool) const;
    MCAPI static float const HANGING_OFFSET;

};