#pragma once

class ShotRecord;

class Resolver {
public:
	enum Modes : size_t {
		RESOLVE_NONE = 0,
		RESOLVE_WALK,
		RESOLVE_STAND,
		RESOLVE_STAND1,
		RESOLVE_STAND2,
		RESOLVE_AIR,
		RESOLVE_LASTMOVE,
		RESOLVE_OVERRIDE,
		RESOLVE_UNKNOWM,
		RESOLVE_BODY,
		RESOLVE_STOPPED_MOVING,
		RESOLVE_LBY_UPDATE,
		RESOLVE_LAST_LBY,
	};

public:
	LagRecord* FindIdealRecord(AimPlayer* data);
	LagRecord* FindLastRecord(AimPlayer* data);

	LagRecord* FindFirstRecord(AimPlayer* data);

	void OnBodyUpdate(Player* player, float value);
	float GetAwayAngle(LagRecord* record);

	void MatchShot(AimPlayer* data, LagRecord* record);
	void SetMode(LagRecord* record);

	void DetectSide(Player* player, int* side);

	void ResolveAngles(Player* player, LagRecord* record);
	void ResolveWalk(AimPlayer* data, LagRecord* record);
	float GetLBYRotatedYaw(float lby, float yaw);
	bool IsYawSideways(Player* entity, float yaw);
	void ResolveYawBruteforce(LagRecord* record, Player* player, AimPlayer* data);
	float GetDirectionAngle(int index, Player* player);
	void LastMoveLby(LagRecord* record, AimPlayer* data, Player* player);
	void ResolveStand(AimPlayer* data, LagRecord* record);
	void StandNS(AimPlayer* data, LagRecord* record);
	void ResolveAir(AimPlayer* data, LagRecord* record, Player* player);
	void ResolveAir(AimPlayer* data, LagRecord* record);
	void resolve(Player* entity, LagRecord* record);

	void AirNS(AimPlayer* data, LagRecord* record);
	void ResolvePoses(Player* player, LagRecord* record);

	bool IdealFreestand(Player* entity, float& yaw, int damage_toleranc);
	bool lby_updated(LagRecord* a, AimPlayer* b, Player* entity);
	bool can_backtrack(Player* entity);
	void lby_update_checks(Player* entity, LagRecord* a, AimPlayer* b);
	void store(Player* entity, float yaw, AimPlayer* b);

	void ResolveOverride(Player* player, LagRecord* record, AimPlayer* data);

	void AntiFreestand(Player* pEnemy, float& y, float flLeftDamage, float flRightDamage, float flRightFraction, float flLeftFraction, float flToMe, int& iShotsMissed);

public:
	std::array< vec3_t, 64 > m_impacts;
};

extern Resolver g_resolver;