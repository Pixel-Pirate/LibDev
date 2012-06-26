#include "icecrown_citadel.h"
#include "Transport.h"
#include "MapManager.h"

enum eAchievements
{
	IM_ON_A_BOAT_10 = 4536,
    IM_ON_A_BOAT_25 = 4612,
};

enum Actions
{
	ACTION_INTRO_START = 1,
    ACTION_BATTLE_EVENT = 2,
};

enum Spells
{
	SPELL_BURNING_PITCH_A 				= 71335,
    SPELL_BURNING_PITCH_H 				= 71339,
    SPELL_BURNING_PITCH_SIEGE_DMG_A 	= 70383,
    SPELL_BURNING_PITCH_SIEGE_DMG_H 	= 70374,
    SPELL_BURNING_PITCH_AOE_DAMAGE 		= 69660,

    SPELL_WOUNDING_STRIKE_10_NM 		= 69651,
    SPELL_WOUNDING_STRIKE_10_HM 		= 72570,
    SPELL_WOUNDING_STRIKE_25_NM 		= 72569,
    SPELL_WOUNDING_STRIKE_25_HM 		= 72571,

    SPELL_TELEPORT_VISUAL 				= 64446,
    SPELL_BLADESTORM 					= 69652,
    SPELL_BLADESTORM_TRIGGER 			= 69653,

    SPELL_HEAT_DRAIN 					= 69470,
    SPELL_OVERHEAT 						= 69487,
    SPELL_CANNON_BLAST 					= 69399,
    SPELL_INCINERATING_BLAST 			= 69401,

    SPELL_ON_ORGRIMS_HAMMERS_DECK 		= 70121,
    SPELL_ON_SKYBREAKERS_DECK 			= 70120,

    SPELL_WRATH 						= 69968,
    SPELL_HEALING_TOUCH 				= 69899,
    SPELL_REGROWTH 						= 69882,
    SPELL_REJUVENATION 					= 69898, // I'm not sure...

    SPELL_SUMMON_BATTLE_STANDART_A 		= 69810,
    SPELL_SUMMON_BATTLE_STANDART_H 		= 69811,

    SPELL_DEVASTATE 					= 69902,
    SPELL_THUNDERCLAP 					= 69965,
    SPELL_SUNDER_ARMOR 					= 57807,
    SPELL_SPELL_REFLECT 				= 69901,

    SPELL_AVENGERS_SHIELD 				= 69927,
    SPELL_CONCENTRATION 				= 69930,
    SPELL_HOLY_WRATH 					= 69934,

    SPELL_FROST_BREATH 					= 70116,
    SPELL_BLIZZARD 						= 70362,
    SPELL_FROST_CLEAVE 					= 70361,

    SPELL_CLEAVE 						= 15284,
    SPELL_RENDING_THROW 				= 70309,
    SPELL_TASTE_OF_BLOOD 				= 69634,
	
	SPELL_BELOW_ZERO                	= 69705,
    SPELL_SHADOW_CHANNELING        	 	= 45104,
	
	SPELL_EXPERIENCED              	 	= 71188,
    SPELL_VETERAN                   	= 71193,
    SPELL_ELITE                     	= 71195,
    SPELL_DESPERATE_RESOLVE_10_NM   	= 69647,
    SPELL_DESPERATE_RESOLVE_10_HM   	= 72537,
    SPELL_DESPERATE_RESOLVE_25_NM   	= 72536,
    SPELL_DESPERATE_RESOLVE_25_HM   	= 72538,

    SPELL_HURL_AXE                  	= 70161,
    SPELL_SHOOT                     	= 70162,

    SPELL_ROCKET_ARTILLERY_MARKER   	= 71371,
    SPELL_ROCKET_ARTILLERY_TRIGGERED	= 69679,
    SPELL_ROCKET_ARTILLERY_HORDE      	= 69678,
    SPELL_ROCKET_ARTILLERY_ALLIANCE   	= 70609,
    SPELL_EXPLOSION                   	= 69680,

	SPELL_SHIP_EXPLOSION 				= 72137,
    SPELL_REMOVE_ROCKET_PACK 			= 70713,
};

enum Events
{
	EVENT_NULL,
    EVENT_INTRO_ALLIANCE_1,	// Muradin Faites chauffer les moteurs! Nous avons rendez-vous avec le destin, les gars !
    EVENT_INTRO_ALLIANCE_2,	// Muradin Accrochez-vous à vos casques !
    EVENT_INTRO_ALLIANCE_3,	// Muradin Qu'est-ce ce que ce truc ?
    EVENT_INTRO_ALLIANCE_4,	// Muradin Par ma barbe horde en approche !
    EVENT_INTRO_ALLIANCE_5,	// Muradin Manoeuvre d'esquive, tous à vos cannons !
    EVENT_INTRO_ALLIANCE_6,	// Muradin Lâche vous nous aveuglés !
    EVENT_INTRO_ALLIANCE_7,	// Muradin Ce combat n'est pas le votre, nain. Retirez vous ou nous serons forcé de détruire votre vaiseau !
    EVENT_INTRO_ALLIANCE_8,	// High Overlord Saurfang Fusillier intensifié le tire !

    EVENT_INTRO_HORDE_1,	// High Overlord Saurfang
    EVENT_INTRO_HORDE_1_1,	// Kor'kron
    EVENT_INTRO_HORDE_2,	// High Overlord Saurfang
    EVENT_INTRO_HORDE_3,	// High Overlord Saurfang
    EVENT_INTRO_HORDE_4,	// High Overlord Saurfang
    EVENT_INTRO_HORDE_5,	// High Overlord Saurfang

    EVENT_OUTRO_ALLIANCE_1,
    EVENT_OUTRO_ALLIANCE_2,
    EVENT_OUTRO_ALLIANCE_3,

    EVENT_OUTRO_HORDE_1,
    EVENT_OUTRO_HORDE_2,
    EVENT_OUTRO_HORDE_3,
    
    EVENT_START_FLY,

    EVENT_WALK_MOBS,
    EVENT_SUMMON_PORTAL,
    EVENT_FREEZE_CANNON,
    EVENT_SHADOW_CHANNELING,
    EVENT_UNSUMMON_PORTAL,
    EVENT_BOARDING_GUNSHIP,
    EVENT_BOARDING_TALK,
    EVENT_BURNING_PITCH,
    EVENT_WOUNDING_STRIKE,
    EVENT_BLADE_STORM,
    EVENT_DONE,
    EVENT_FAIL,
    EVENT_RESTART_EVENT,
    EVENT_BOARDING_REAVERS_MARINE,
    EVENT_WIPE_CHECK,

    EVENT_WRATH,
    EVENT_HEAL,

    EVENT_SUNDER_ARMOR,
    EVENT_SPELL_REFLECT,
    EVENT_THUNDERCLAP,
    EVENT_DEVASTATE,

    EVENT_FROST_BREATH,
    EVENT_BLIZZARD,
    EVENT_CLEAVE,

    EVENT_AVENGERS_SHILED,
    EVENT_CONCENTRATION,
    EVENT_HOLY_WRATH,

    EVENT_FIRST_SQUAD_ASSISTED_1,
    EVENT_FIRST_SQUAD_ASSISTED_2,

    EVENT_SECOND_SQUAD_ASSISTED_1,
    EVENT_SECOND_SQUAD_ASSISTED_2,
    EVENT_SECOND_SQUAD_ASSISTED_3,
	
	EVENT_EXPERIENCED,
    EVENT_VETERAN,
    EVENT_ELITE,
    EVENT_ATACK_START,

    EVENT_HURL_AXE,
    EVENT_SHOOT,

    EVENT_ROCKET_ART,

    EVENT_RENDING_THROW,
    EVENT_TASTE_OF_BLOOD,

    EVENT_SPAWN_MAGE,
    EVENT_RESPAWN_AXES_RIFLEMEN,
    EVENT_RESPAWN_ROCKETEER,
};

enum Texts
{
    SAY_FIRST_SQUAD_RESCUED_HORDE_0 		= 0,

    SAY_FIRST_SQUAD_RESCUED_HORDE_1 		= 0,

    SAY_SECOND_SQUAD_RESCUED_HORDE_0 		= 0,
    SAY_SECOND_SQUAD_RESCUED_HORDE_1 		= 1,
    SAY_FROSTWYRM_SUMMON_0 					= 2,
    SAY_FROSTWYRM_SUMMON_1 					= 3,

    SAY_FIRST_SQUAD_RESCUED_ALLIANCE_0 		= 0,
    SAY_FIRST_SQUAD_RESCUED_ALLIANCE_1 		= 0,

    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_0 	= 0,
    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_1 	= 1,
    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_2 	= 2,

    SAY_SUMMON_BATTLE_STANDARD 				= 1,

    SAY_FROSTWYRM_LAND_H_0 					= 0,
    SAY_FROSTWYRM_LAND_A_1 					= 1,

    SAY_INTRO_ALLIANCE_0 					= 0,
    SAY_INTRO_ALLIANCE_1 					= 1,
    SAY_INTRO_ALLIANCE_2 					= 2,
    SAY_INTRO_ALLIANCE_3 					= 3,
    SAY_INTRO_ALLIANCE_4 					= 4,
    SAY_INTRO_ALLIANCE_5 					= 5,
    SAY_INTRO_ALLIANCE_7 					= 6,
    SAY_INTRO_HORDE_3 						= 7,
    SAY_BOARDING_SKYBREAKER_1 				= 8,
    SAY_BOARDING_ORGRIMS_HAMMER_0 			= 9,
    SAY_NEW_RIFLEMEN_SPAWNED 				= 10,
    SAY_NEW_MORTAR_TEAM_SPAWNED 			= 11,
    SAY_NEW_MAGE_SPAWNED 					= 12,
    SAY_ALLIANCE_VICTORY 					= 13,
    SAY_ALLIANCE_DEFEAT 					= 14,

    SAY_INTRO_HORDE_0 						= 0,
    SAY_INTRO_HORDE_0_1 					= 1,
    SAY_INTRO_HORDE_1 						= 2,
    SAY_INTRO_HORDE_2 						= 3,
    SAY_INTRO_HORDE_4 						= 4,
    SAY_BOARDING_SKYBREAKER_0 				= 5,
    SAY_BOARDING_ORGRIMS_HAMMER_1 			= 6,
    SAY_NEW_AXETHROWER_SPAWNED 				= 7,
    SAY_NEW_ROCKETEERS_SPAWNED 				= 8,
    SAY_NEW_BATTLE_MAGE_SPAWNED 			= 9,
    SAY_HORDE_VICTORY 						= 10,
    SAY_HORDE_DEFEAT 						= 11,

    SAY_HIGH_OVERLORD_SAURFANG_NOT_VISUAL 	= 0,
    SAY_BOARDING_SKYBREAKER_SAURFANG 		= 1,
    SAY_MURADIN_BRONZEBEARD_NOT_VISUAL 		= 0,
    SAY_BOARDING_SKYBREAKER_MURADIN 		= 1,
};

Position const FrostWyrmPosH = {-435.429f, 2077.556f, 219.1148f, 4.767166};
Position const FrostWyrmPosA = {-437.409f, 2349.026f, 219.1148f, 1.483120};

struct mortarMarksLoc
{
};

void AddSC_boss_gunship_battle()
{
	uint32 durationBeforeRefreshing;
    Position location;
}

typedef std::list<Player*> TPlayerLists;

TPlayerLists GetPlayersInTheMaps(Map *map)
{
    TPlayerLists players;
    const Map::PlayerList &PlayerList = map->GetPlayers();
    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->getSource())
                players.push_back(player);
    return players;
}

Player* SelectRandomPlayerFromLists(TPlayerLists &players)
{
    if (players.empty())
        return NULL;
    TPlayerLists::iterator it = players.begin();
    std::advance(it, urand(0, players.size()-1));
    return *it;
}

Player* SelectRandomPlayerInTheMaps(Map* map)
{
    TPlayerLists players = GetPlayersInTheMaps(map);
    return SelectRandomPlayerFromLists(players);
}

void StartFlyShip(Transport* transport)
{
    transport->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    transport->SetGoState(GO_STATE_ACTIVE);
    transport->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0x10830010); // Seen in sniffs
    transport->SetFloatValue(GAMEOBJECT_PARENTROTATION 3, 1.0f);

    Map* map = transport->GetMap();
    std::set<uint32> mapsUsed;
    GameObjectTemplate const* goinfo = transport->GetGOInfo();

    transport->GenerateWaypoints(goinfo->moTransport.taxiPathId, mapsUsed);

    for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
    {
        if (Player* pPlayer = itr->getSource())
        {
            UpdateData transData;
            transport->BuildCreateUpdateBlockForPlayer(&transData, pPlayer);
            WorldPacket packet;
            transData.BuildPacket(&packet);
            pPlayer->SendDirectMessage(&packet);
        }
    }
}

void RelocateTransport(Transport* transport)
{
    Map* map = transport->GetMap();
    InstanceScript* instance = transport->GetInstanceScript();

    if (!transport || !instance)
        return;

    switch (transport->GetEntry())
    {
        case GO_THE_SKYBREAKER_ALLIANCE_ICC:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                transport->Relocate(-377.184021f, 2073.548584f, 445.753387f);
            else if (instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE)
                transport->Relocate(-583.942627f, 2212.364990f, 534.673889f);
            break;
        case GO_ORGRIM_S_HAMMER_ALLIANCE_ICC:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                transport->Relocate(-384.878479f, 1989.831665f, 431.549438f);
            break;
        case GO_ORGRIM_S_HAMMER_HORDE_ICC:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                transport->Relocate(-438.142365f, 2395.725830f, 436.781647f);
            else if (instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE)
                transport->Relocate(-583.942627f, 2212.364990f, 534.673889f);
            break;
        case GO_THE_SKYBREAKER_HORDE_ICC:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                transport->Relocate(-435.854156f, 2475.328125f, 449.364105f);
            break;
    }

    transport->Update(0);
    transport->UpdateNPCPositions();
}

void StopFlyShip(Transport* transport)
{
    Map* map = transport->GetMap();
    transport->m_WayPoints.clear();
    RelocateTransport(transport);
    transport->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    transport->SetGoState(GO_STATE_READY);

    for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
    {
        if (Player* pPlayer = itr->getSource())
        {
            UpdateData transData;
            transport->BuildCreateUpdateBlockForPlayer(&transData, pPlayer);
            WorldPacket packet;
            transData.BuildPacket(&packet);
            pPlayer->SendDirectMessage(&packet);
        }
    }
}

Transport* CheckUnfriendlyShip(Creature* creature, InstanceScript* instance, uint32 data)
{
    if(Creature* pCapitan = ObjectAccessor::GetCreature(*creature, instance->GetData64(data)))
        return pCapitan->GetTransport();
    else
        return NULL;
}

void TeleportPlayers(Map* map, uint64 TeamInInstance)
{
    if(map)
    {
        Map::PlayerList const &lPlayers = map->GetPlayers();
        if (!lPlayers.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            {
                if (Player* pPlayer = itr->getSource())
                {
                    if (pPlayer->isDead() && !pPlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                        pPlayer->ResurrectPlayer(1.0f);

                    if(TeamInInstance == ALLIANCE)
                        pPlayer->TeleportTo(631, -437.498505f, 2425.954f, 192.997f, 2.247f);
                    else
                        pPlayer->TeleportTo(631, -437.498505f, 1997.954f, 192.997f, 2.247f);
                }
            }
        }
    }
}

void DoShipExplosion(Transport* transport)
{
    for (Transport::CreatureSet::iterator itr = transport->m_NPCPassengerSet.begin(); itr != transport->m_NPCPassengerSet.end();)
    {
        if (Creature* npc = *itr)
        {
            if(npc->GetEntry() == NPC_GB_GUNSHIP_HULL)
                npc->CastSpell(npc, SPELL_SHIP_EXPLOSION, true);
        }
        ++itr;
    }
}

bool DoWipeCheck(Transport* transport)
{
    for (Transport::PlayerSet::const_iterator itr = transport->GetPassengers().begin(); itr != transport->GetPassengers().end();)
    {
        Player* plr = *itr;
        ++itr;

        if (plr && plr->isAlive())
            return true;
    }
    return false;
}

void DoCheckFallingPlayer(Creature* creature)
{
    Map* map = creature->GetMap();

    if(map)
    {
        Map::PlayerList const &lPlayers = map->GetPlayers();
        if (!lPlayers.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            {
                if (Player* pPlayer = itr->getSource())
                {
                    if (pPlayer->GetPositionZ() < 420.0f && pPlayer->IsWithinDistInMap(creature, 300.0f))
                        pPlayer->NearTeleportTo(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ() 5.0f, creature->GetOrientation());
                }
            }
        }
    }
}

void RestartEvent(Transport* transport1, Transport* transport2, Map* map, uint64 TeamInInstance)
{
	sMapMgr->UnLoadTransportFromMap(transport1);
    sMapMgr->UnLoadTransportFromMap(transport2);

    Map::PlayerList const& players = map->GetPlayers();
    if (players.isEmpty())
        return;
			
				if(TeamInInstance == ALLIANCE)
                {
                    if(Transport* transport = sMapMgr->LoadTransportInMap(instance, GO_ORGRIM_S_HAMMER_ALLIANCE_ICC, 108000))
                    {
                        transport->AddNPCPassengerInInstance(NPC_GB_ORGRIMS_HAMMER, 1.845810f, 1.268872f, 34.526218f, 1.5890f);
                        transport->AddNPCPassengerInInstance(NPC_GB_HIGH_OVERLORD_SAURFANG, 37.18615f, 0.00016f, 36.78849f, 3.13683f);
                        transport->AddNPCPassengerInInstance(NPC_GB_INVISIBLE_STALKER, 37.18615f, 0.00016f, 36.78849f, 3.13683f);
                        transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_BATTLE_MAGE, 47.2929f, -4.308941f, 37.5555f, 3.05033f);
                        transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_BATTLE_MAGE, 47.34621f, 4.032004f, 37.70952f, 3.05033f);
                        transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_BATTLE_MAGE, 15.03016f, 0.00016f, 37.70952f, 1.55138f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -13.19547f, -27.160213f, 35.47252f, 3.10672f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.33902f, -25.230491f, 33.04052f, 3.00672f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -60.1251f, -1.27014f, 42.8335f, 5.16073f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -48.2651f, 16.78034f, 34.2515f, 0.04292f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -14.8356f, 27.931688f, 33.363f, 1.73231f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 10.2702f, 20.62966f, 35.37483f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 39.32459f, 14.50176f, 36.88428f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 46.17223f, -6.638763f, 37.35444f, 1.32f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 27.4456f, -13.397498f, 36.34746f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 18.16184f, 1.37897f, 35.31705f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.11516f, -0.196236f, 45.15709f, 2.9f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.11844f, -0.19624f, 49.18192f, 1.6f);

                        if (instance->ToInstanceMap()->GetMaxPlayers() == 10)
                        {
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -3.170555f, 28.30652f, 34.21082f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -12.0928f, 27.65942f, 33.58557f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 14.92804f, 26.18018f, 35.47803f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 24.70331f, 25.36584f, 35.97845f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -11.44849f, -25.71838f, 33.64343f, 1.49248f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 12.30336f, -25.69653f, 35.32373f, 1.49248f);
                        }
                        else
                        {
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -3.170555f, 28.30652f, 34.21082f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -12.0928f, 27.65942f, 33.58557f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 14.92804f, 26.18018f, 35.47803f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 24.70331f, 25.36584f, 35.97845f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 19.92804f, 27.18018f, 35.47803f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -7.70331f, 28.36584f, 33.88557f, 1.66527f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -11.44849f, -25.71838f, 33.64343f, 1.49248f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 12.30336f, -25.69653f, 35.32373f, 1.49248f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -3.44849f, -25.71838f, 34.21082f, 1.49248f);
                            transport->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 3.30336f, -25.69653f, 35.32373f, 1.49248f);
                        }
                    }

                    if(Transport* t = sMapMgr->LoadTransportInMap(instance, GO_THE_SKYBREAKER_ALLIANCE_ICC, 108000))
                    {
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER, -17.156807f, -1.633260f, 20.81273f, 4.52672f);
                        t->AddNPCPassengerInInstance(NPC_GB_MURADIN_BRONZEBEARD, 13.51547f, -0.160213f, 20.87252f, 3.10672f);
                        t->AddNPCPassengerInInstance(NPC_GB_HIHG_CAPTAIN_JUSTIN_BARTLETT, 42.78902f, -0.010491f, 25.24052f, 3.00672f);
                        t->AddNPCPassengerInInstance(NPC_GB_HIGH_OVERLORD_SAURFANG_NOT_VISUAL, -12.9806f, -22.9462f, 21.659f, 4.72416f);
                        t->AddNPCPassengerInInstance(NPC_GB_ZAFOD_BOOMBOX, 18.8042f, 9.907914f, 20.33559f, 3.10672f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_DECKHAND, -64.8423f, 4.4658f, 23.4352f, 2.698897f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_DECKHAND, 35.54972f, 19.93269f, 25.0333f, 4.71242f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_DECKHAND, -36.39837f, 3.13127f, 20.4496f, 1.5708f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_DECKHAND, -36.23974f, -2.75767f, 20.4506f, 4.69496f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_DECKHAND, 41.94677f, 44.08411f, 24.66587f, 1.62032f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 13.51547f, -0.160213f, 20.87252f, 3.10672f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 42.78902f, -0.010491f, 25.24052f, 3.00672f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 14.0551f, 3.65014f, 20.7935f, 3.16073f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 14.0551f, -4.65034f, 20.7915f, 3.04292f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -17.8356f, 0.031688f, 20.823f, 4.73231f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -34.2702f, -26.18966f, 21.37483f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -11.64459f, -19.85176f, 20.88428f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -19.88223f, -6.578763f, 20.57444f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -41.4456f, -7.647498f, 20.49746f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 0.554884f, -1.232897f, 20.53705f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -50.16516f, 9.716236f, 23.58709f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 11.45844f, 16.36624f, 20.54192f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 19.72286f, -2.193787f, 33.06982f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 19.72286f, -2.193787f, 33.06982f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 8.599396f, -28.55855f, 24.79919f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 38.94339f, -33.808f, 25.39618f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 58.15474f, 0.748094f, 41.87663f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 5.607554f, -6.350654f, 34.00357f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 4.780305f, -29.05227f, 35.09634f, 1.6f);

                        if (instance->ToInstanceMap()->GetMaxPlayers() == 10)
                        {
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                        }
                        else
                        {
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -14.9806f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -21.7406f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_ALLIANCE_CANON, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                        }
                    }
                }

                if(TeamInInstance == HORDE)
                {
                    if(Transport* t = sMapMgr->LoadTransportInMap(instance, GO_THE_SKYBREAKER_HORDE_ICC, 77800))
                    {
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER, -17.156807f, -1.633260f, 20.81273f, 4.52672f);
                        t->AddNPCPassengerInInstance(NPC_GB_MURADIN_BRONZEBEARD, 13.51547f, -0.160213f, 20.87252f, 3.10672f);
                        t->AddNPCPassengerInInstance(NPC_GB_HIHG_CAPTAIN_JUSTIN_BARTLETT, 42.78902f, -0.010491f, 25.24052f, 3.00672f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_SORCERERS, 14.0551f, 3.65014f, 20.7935f, 3.16073f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_SORCERERS, 14.0551f, -4.65034f, 20.7915f, 3.04292f);
                        t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_SORCERERS, -17.8356f, 0.031688f, 20.823f, 4.73231f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 13.51547f, -0.160213f, 20.87252f, 3.10672f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 42.78902f, -0.010491f, 25.24052f, 3.00672f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 14.0551f, 3.65014f, 20.7935f, 3.16073f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 14.0551f, -4.65034f, 20.7915f, 3.04292f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -17.8356f, 0.031688f, 20.823f, 4.73231f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -34.2702f, -26.18966f, 21.37483f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -11.64459f, -19.85176f, 20.88428f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -19.88223f, -6.578763f, 20.57444f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -41.4456f, -7.647498f, 20.49746f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 0.554884f, -1.232897f, 20.53705f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -50.16516f, 9.716236f, 23.58709f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 11.45844f, 16.36624f, 20.54192f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 19.72286f, -2.193787f, 33.06982f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 19.72286f, -2.193787f, 33.06982f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 8.599396f, -28.55855f, 24.79919f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 38.94339f, -33.808f, 25.39618f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 58.15474f, 0.748094f, 41.87663f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 5.607554f, -6.350654f, 34.00357f, 1.6f);
                        t->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 4.780305f, -29.05227f, 35.09634f, 1.6f);

                        if(instance->ToInstanceMap()->GetMaxPlayers() == 10)
                        {
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -14.9806f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -21.7406f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -8.61003f, 15.483f, 20.4158f, 4.69854f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -27.9583f, 14.8875f, 20.4428f, 4.77865f);
                        }
                        else
                        {
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, 0.15231f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -14.9806f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -21.7406f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -33.0876f, -22.9462f, 21.659f, 4.72416f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -8.61003f, 15.483f, 20.4158f, 4.69854f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -27.9583f, 14.8875f, 20.4428f, 4.77865f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -15.61003f, 15.483f, 20.4158f, 4.69854f);
                            t->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -20.9583f, 14.8875f, 20.4428f, 4.77865f);
                        }
                    }
                
                    if(Transport* transport = sMapMgr->LoadTransportInMap(instance,GO_ORGRIM_S_HAMMER_HORDE_ICC, 77800))
                    {
                        transport->AddNPCPassengerInInstance(NPC_GB_ORGRIMS_HAMMER, 1.845810f, 1.268872f, 34.526218f, 1.5890f);
                        transport->AddNPCPassengerInInstance(NPC_GB_HIGH_OVERLORD_SAURFANG, 37.18615f, 0.00016f, 36.78849f, 3.13683f);
                        transport->AddNPCPassengerInInstance(NPC_GB_MURADIN_BRONZEBEARD_NOT_VISUAL, -7.09684f, 30.582f, 34.5013f, 1.53591f);
                        transport->AddNPCPassengerInInstance(NPC_GB_INVISIBLE_STALKER, 37.30764f, -0.143823f, 36.7936f, 3.13683f);
                        transport->AddNPCPassengerInInstance(NPC_GB_ZAFOD_BOOMBOX, 35.18615f, 15.30652f, 37.64343f, 3.05033f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -13.19547f, -27.160213f, 35.47252f, 3.10672f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.33902f, -25.230491f, 33.04052f, 3.00672f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -60.1251f, -1.27014f, 42.8335f, 5.16073f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -48.2651f, 16.78034f, 34.2515f, 0.04292f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -14.8356f, 27.931688f, 33.363f, 1.73231f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 10.2702f, 20.62966f, 35.37483f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 39.32459f, 14.50176f, 36.88428f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 46.17223f, -6.638763f, 37.35444f, 1.32f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 27.4456f, -13.397498f, 36.34746f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, 18.16184f, 1.37897f, 35.31705f, 1.6f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.11516f, -0.196236f, 45.15709f, 2.9f);
                        transport->AddNPCPassengerInInstance(NPC_GB_GUNSHIP_HULL, -18.11844f, -0.19624f, 49.18192f, 1.6f);

                        if(instance->ToInstanceMap()->GetMaxPlayers() == 10)
                        {
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, 22.6225f, 28.9309f, 36.3929f, 1.53591f);
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, -21.7509f, 29.4207f, 34.2588f, 1.53591f);
                        }
                        else
                        {
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, 22.6225f, 28.9309f, 36.3929f, 1.53591f);
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, 9.87745f, 30.5047f, 35.7147f, 1.53591f);
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, -7.09684f, 30.582f, 34.5013f, 1.53591f);
                            transport->AddNPCPassengerInInstance(NPC_GB_HORDE_CANON, -21.7509f, 29.4207f, 34.2588f, 1.53591f);
                        }
                    }
                }

}

void StopFight(Transport* transport1, Transport* transport2)
{
    Map* map = transport1->GetMap();

    for (Transport::CreatureSet::iterator itr = transport1->m_NPCPassengerSet.begin(); itr != transport1->m_NPCPassengerSet.end();)
    {
        if (Creature *_creature = *itr)
        {
            if(_creature->GetEntry() != NPC_GB_SKYBREAKER && _creature->GetEntry() != NPC_GB_ORGRIMS_HAMMER && _creature->GetEntry() != NPC_GB_HIGH_OVERLORD_SAURFANG
            && _creature->GetEntry() != NPC_GB_MURADIN_BRONZEBEARD && _creature->GetEntry() != NPC_GB_GUNSHIP_HULL)
            {
                if (Vehicle* veh = _creature->GetVehicleKit())
                    veh->RemoveAllPassengers();
                _creature->Kill(_creature);
            }
        }
        ++itr;
    }

    for (Transport::CreatureSet::iterator itr =  transport2->m_NPCPassengerSet.begin(); itr !=  transport2->m_NPCPassengerSet.end();)
    {
        if (Creature *_creature = *itr)
        {
            if(_creature->GetEntry() != NPC_GB_GUNSHIP_HULL && _creature->GetEntry() != NPC_GB_SKYBREAKER && _creature->GetEntry() != NPC_GB_ORGRIMS_HAMMER)
                _creature->Kill(_creature);
        }
        ++itr;
    }

    for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
    {
        if (Player* pPlayer = itr->getSource())
            pPlayer->CombatStop();
    }
}

class npc_muradin_gunship : public CreatureScript
{
    public:
        npc_muradin_gunship() : CreatureScript("npc_muradin_gunship") { }

        bool OnGossipHello(Player* player, Creature* pCreature)
        {
            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
            {
                if ((!player->GetGroup() || !player->GetGroup()->IsLeader(player->GetGUID())) && !player->isGameMaster())
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Je ne suis pas le chef du raid...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                    return true;
                }

                player->ADD_GOSSIP_ITEM(0, "Mes compagnons sont tous présent, Muradin. Allons-y!", 631, 1001);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());
                return true;
            }
            return false;
        }

        bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
        {
            InstanceScript* instance = pCreature->GetInstanceScript();
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();

            if (action == GOSSIP_ACTION_INFO_DEF+2)
                pCreature->MonsterSay("Je vais attendre le chef du raid", LANG_UNIVERSAL, player->GetGUID());

            if (action == 1001)
            {
                pCreature->AI()->DoAction(ACTION_INTRO_START);
                pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
            return true;
        }

        struct npc_muradin_gunshipAI : public ScriptedAI
        {
            npc_muradin_gunshipAI(Creature *creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {

            }

            void Reset()
            {
                if (_instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                    return;
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(1802);
                events.Reset();
                map = me->GetMap();
                skybreaker = me->GetTransport();
                SummonCount = RAID_MODE(3, 5, 4, 6);
                count = 0;
                RocketerCount = RAID_MODE(2, 4, 2, 4);
                RiflCount = RAID_MODE(4, 6, 4, 6);
                RocketerDieCount = 0;
                RiflDieCount = 0;
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                EventScheduled = false;
            }

            void SendMusicToPlayers(uint32 musicId) const
            {
                WorldPacket data(SMSG_PLAY_MUSIC, 4);
                data << uint32(musicId);
                SendPacketToPlayers(&data);
            }

            void SendPacketToPlayers(WorldPacket const* data) const
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->getSource())
                            player->GetSession()->SendPacket(data);
            }

            bool CanAIAttack(Unit const* target) const
            {
                if (target->GetEntry() == NPC_GB_KORKRON_SERGANTE || target->GetEntry() == NPC_GB_KORKRON_REAVERS)
                    return true;

                return false;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_INTRO_START:
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_1, 1000);
                        events.ScheduleEvent(EVENT_START_FLY, 2500);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_2, 7000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_3, 28000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_4, 35000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_5, 40000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_6, 47000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_7, 53000);
                        events.ScheduleEvent(EVENT_INTRO_ALLIANCE_8, 58900);
                        break;
                    case ACTION_BATTLE_EVENT:
                    {
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            events.ScheduleEvent(EVENT_WIPE_CHECK, 5000);

                        Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS));
                        Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS));

                        if (pHordeBoss && pAllianceBoss)
                        {
                             me->SetReactState(REACT_AGGRESSIVE);
                             pHordeBoss->SetInCombatWith(pAllianceBoss);
                             pAllianceBoss->SetInCombatWith(pHordeBoss);
                             pAllianceBoss->AddThreat(pHordeBoss, 0.0f);
                             pHordeBoss->AddThreat(pAllianceBoss, 0.0f);
                             _instance->SetBossState(DATA_GUNSHIP_EVENT, IN_PROGRESS);
                             events.ScheduleEvent(EVENT_SUMMON_PORTAL, 30000);
                             RelocateTransport(skybreaker);
                             RelocateTransport(CheckUnfriendlyShip(me,_instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                        }
                        else
                            me->AI()->DoAction(ACTION_FAIL);
                        break;
                    }
                    case ACTION_DONE:
                        if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                        {
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, pAllianceBoss);
                        }
                        if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                        {
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, pHordeBoss);
                        }

                        me->SetReactState(REACT_PASSIVE);
                        _instance->SetBossState(DATA_GUNSHIP_EVENT, DONE);
                        _instance->DoCastSpellOnPlayers(SPELL_REMOVE_ROCKET_PACK);
                        Talk(SAY_ALLIANCE_VICTORY);
                        StartFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                        StopFight(skybreaker, CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                        events.CancelEvent(EVENT_WIPE_CHECK);
                        events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_1, 3500);
                        events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_2, 23000);
                        events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_3, 32000);
                        break;
                    case ACTION_FAIL:
                        events.CancelEvent(EVENT_WIPE_CHECK);
                        Talk(SAY_ALLIANCE_DEFEAT);
                        if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                        {
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, pAllianceBoss);
                        }
                        if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                        {
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, pHordeBoss);
                        }
                        StopFight(skybreaker, CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                        events.ScheduleEvent(EVENT_FAIL, 10000);
                        break;
                    case ACTION_MAGE_DIE:
                        events.ScheduleEvent(EVENT_SPAWN_MAGE, 60000);
                        break;
                    case ACTION_ROCK_DIE:
                        ++RocketerDieCount;
                        if(RocketerDieCount == RocketerCount)
                            events.ScheduleEvent(EVENT_RESPAWN_ROCKETEER, 60000);
                        break;
                    case ACTION_AXES_RIFL_DIE:
                        ++RiflDieCount;
                        if(RiflDieCount == RiflCount)
                            events.ScheduleEvent(EVENT_RESPAWN_AXES_RIFLEMEN, 60000);
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE && me->GetHealthPct() < 2.0f )
                {
                   damage = 0;
                }
                
                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetHealthPct() < 2.0f )
                {
                   damage = 0;
                   me->AI()->DoAction(ACTION_FAIL);
                }
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (pointId = 1)
                    me->DespawnOrUnsummon(1000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                
                if (!HealthAbovePct(75))
                {
                    me->SetHealth(me->GetMaxHealth() / 100 * 76);
                    DoCast(me, SPELL_TASTE_OF_BLOOD);
                }

                if (UpdateVictim())
                {
                    if (!EventScheduled)
                    {
                        EventScheduled = true;
                        events.ScheduleEvent(EVENT_RENDING_THROW, 3000);
                    }
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WIPE_CHECK:
                            DoCheckFallingPlayer(me);
                            if (DoWipeCheck(skybreaker))
                                events.ScheduleEvent(EVENT_WIPE_CHECK, 3000);
                            else
                                me->AI()->DoAction(ACTION_FAIL);
                            break;
                        case EVENT_INTRO_ALLIANCE_1:
                            Talk(SAY_INTRO_ALLIANCE_0);
                            break;
                        case EVENT_START_FLY:
                            StartFlyShip(skybreaker);
                            break;
                        case EVENT_INTRO_ALLIANCE_2:
                            Talk(SAY_INTRO_ALLIANCE_1);
                            break;
                        case EVENT_INTRO_ALLIANCE_3:
                            Talk(SAY_INTRO_ALLIANCE_2);
                            StartFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                            break;
                        case EVENT_INTRO_ALLIANCE_4:
                            Talk(SAY_INTRO_ALLIANCE_3);
                            break;
                        case EVENT_INTRO_ALLIANCE_5:
                            StopFlyShip(skybreaker);
                            StopFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                            Talk(SAY_INTRO_ALLIANCE_4);
                            break;
                        case EVENT_INTRO_ALLIANCE_6:
                            Talk(SAY_INTRO_ALLIANCE_5);
                            SendMusicToPlayers(17289);
                            me->AI()->DoAction(ACTION_BATTLE_EVENT);
                            break;
                        case EVENT_INTRO_ALLIANCE_7:
                            if (Creature* pSaurfang = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HIGH_OVERLORD_SAURFANG_NOT_VISUAL)))
                            {
                                pSaurfang->AI()->Talk(SAY_HIGH_OVERLORD_SAURFANG_NOT_VISUAL);
                                pSaurfang->SetReactState(REACT_PASSIVE);
                                pSaurfang->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            }
                            break;
                        case EVENT_INTRO_ALLIANCE_8:
                            Talk(SAY_INTRO_ALLIANCE_7);
                            break;
                        case EVENT_SUMMON_PORTAL:
                            if(_instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                            {
                                events.ScheduleEvent(EVENT_BOARDING_TALK, 10000);
                                events.ScheduleEvent(EVENT_BOARDING_GUNSHIP, 2500);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_PORTAL, -15.51547f, -0.160213f, 28.87252f, 1.56211f);
                                CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG)->AddNPCPassengerInInstance(NPC_GB_PORTAL, 47.55099f, -0.101778f, 37.61111f, 1.55138f);
                            }
                            break;
                        case EVENT_RENDING_THROW:
                            if (UpdateVictim())
                                if (me->getVictim()->IsWithinDistInMap(me, 50.0f, false))
                                {
                                    DoCastVictim(SPELL_RENDING_THROW);
                                    EventScheduled = false;
                                }
                                else
                                    events.CancelEvent(EVENT_RENDING_THROW);
                            break;
                        case EVENT_TASTE_OF_BLOOD:
                            DoCast(me, SPELL_TASTE_OF_BLOOD);
                            break;
                        case EVENT_BOARDING_TALK:
                            Talk(SAY_BOARDING_SKYBREAKER_1);
                            break;
                        case EVENT_BOARDING_GUNSHIP:
                            if (Creature* pSaurfang = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HIGH_OVERLORD_SAURFANG_NOT_VISUAL)))
                            {
                                pSaurfang->AI()->Talk(SAY_BOARDING_SKYBREAKER_SAURFANG);
                            }
                            if(Creature* Sergante = skybreaker->AddNPCPassengerInInstance(NPC_GB_KORKRON_SERGANTE, -15.51547f, -0.160213f, 20.87252f, 1.56211f))
                            {
                                Sergante->CastSpell(Sergante, SPELL_TELEPORT_VISUAL, true);
                            }
                            events.ScheduleEvent(EVENT_SUMMON_PORTAL, 90000);
                            events.ScheduleEvent(EVENT_BOARDING_REAVERS_MARINE, 3000);
                            count = 0;
                            break;
                        case EVENT_BOARDING_REAVERS_MARINE:
                            if(count <= SummonCount)
                            {
                                if(Creature* Reavers = skybreaker->AddNPCPassengerInInstance(NPC_GB_KORKRON_REAVERS, -15.51547f, -0.160213f, 20.87252f, 1.56211f))
                                {
                                    Reavers->CastSpell(Reavers, SPELL_TELEPORT_VISUAL, true);
                                    events.ScheduleEvent(EVENT_BOARDING_REAVERS_MARINE, 21000 / SummonCount);
                                    ++count;
                                }
                            }
                            break;
                        case EVENT_OUTRO_ALLIANCE_1:
                            _instance->DoCompleteAchievement(RAID_MODE(IM_ON_A_BOAT_10,IM_ON_A_BOAT_25,IM_ON_A_BOAT_10,IM_ON_A_BOAT_25));
                            _instance->DoCastSpellOnPlayers(SPELL_ACHIEVEMENT_CHECK);
                            StartFlyShip(skybreaker);
                            StopFlyShip(CheckUnfriendlyShip(me,_instance,DATA_GB_HIGH_OVERLORD_SAURFANG));
                            break;
                        case EVENT_OUTRO_ALLIANCE_2:
                            StopFlyShip(skybreaker);
                            me->SummonGameObject(RAID_MODE(GO_CAPITAN_CHEST_A_10N, GO_CAPITAN_CHEST_A_25N, GO_CAPITAN_CHEST_A_10H, GO_CAPITAN_CHEST_A_25H), -590.200022f, 2241.193115f, 538.588269f, 0, 0, 0, 0, 0, 100000);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(0, -590.700f, 2213.01f, 539.1f);
                            break;
                        case EVENT_OUTRO_ALLIANCE_3:
                            me->GetMotionMaster()->MovePoint(1, -555.59f, 2213.01f, 539.28f);
                            break;
                        case EVENT_FAIL:
                            TeleportPlayers(map, ALLIANCE);
                            events.ScheduleEvent(EVENT_RESTART_EVENT, 2000);
                            _instance->SetBossState(DATA_GUNSHIP_EVENT, NOT_STARTED);
                            break;
                        case EVENT_RESTART_EVENT:
                            _instance->SetBossState(DATA_GUNSHIP_EVENT, FAIL);
                            RestartEvent(skybreaker, CheckUnfriendlyShip(me,_instance,DATA_GB_HIGH_OVERLORD_SAURFANG), map, ALLIANCE);
                            break;
                        case EVENT_SPAWN_MAGE:
                            Talk(SAY_NEW_MAGE_SPAWNED);
                            skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_SORCERERS, -17.8356f, 0.031688f, 20.823f, 4.73231f);
                            break;
                        case EVENT_RESPAWN_ROCKETEER:
                            Talk(SAY_NEW_MORTAR_TEAM_SPAWNED);
                            if(RocketerCount == 2)
                            {
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -8.61003f, 15.483f, 20.4158f, 4.69854f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -27.9583f, 14.8875f, 20.4428f, 4.77865f);
                            }
                            if(RocketerCount == 4)
                            {
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -8.61003f, 15.483f, 20.4158f, 4.69854f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -27.9583f, 14.8875f, 20.4428f, 4.77865f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -15.61003f, 15.483f, 20.4158f, 4.69854f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MORTAR_SOLDIER, -20.9583f, 14.8875f, 20.4428f, 4.77865f);
                            }
                            break;
                        case EVENT_RESPAWN_AXES_RIFLEMEN:
                            Talk(SAY_NEW_RIFLEMEN_SPAWNED);
                            if(RiflCount == 4)
                            {
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -21.7406f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -14.9806f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                            }
                            if(RiflCount == 6)
                            {
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -33.0876f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -28.0876f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -21.7406f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -14.9806f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, -5.15231f, -22.9462f, 21.659f, 4.72416f);
                                skybreaker->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_RIFLEMAN, 0.15231f, -22.9462f, 21.659f, 4.72416f);
                            }
                            break;
                      }
                }

                if (!me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                    DoCastVictim(SPELL_CLEAVE);

                DoMeleeAttackIfReady();
            }

            private:
                Transport* skybreaker;
                Map* map;
                uint32 SummonCount;
                EventMap events;
                InstanceScript* _instance;
                uint32 count;
                uint32 RocketerDieCount;
                uint32 RiflDieCount;
                uint32 RocketerCount;
                uint32 RiflCount;
                bool EventScheduled;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_muradin_gunshipAI(pCreature);
        }
};

void AddSC_boss_gunship_battle()
{
	new npc_muradin_gunship();
}