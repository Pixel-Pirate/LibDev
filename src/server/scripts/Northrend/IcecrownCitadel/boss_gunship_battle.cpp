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
}

void AddSC_boss_gunship_battle()
{
}