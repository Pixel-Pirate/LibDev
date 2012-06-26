		################################
		# Fix  NPC & GAMEOBJECT & Item #
		################################

DELETE FROM `creature_template` WHERE (`entry`=50004);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(50004, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'High Overlord Saurfang', '', '', 0, 80, 80, 3, 1802, 1802, 0, 0, 0, 1, 1, 252, 357, 0, 304, '7.5', 2000, 0, 1, 33554432, 8, 0, 0, 0, 0, 0, 215, 320, 44, 7, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340);

DELETE FROM `creature_template` WHERE (`entry`=50006);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(50006, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Muradin Bronzebeard', '', '', 10875, 83, 83, 2, 1802, 1802, 1, 1, '1.14286', 1, 1, 468, 702, 0, 175, '47.2', 2000, 2000, 1, 33554432, 8, 0, 0, 0, 0, 0, 374, 562, 140, 7, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15284, 70309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 175, 1, 1, 0, 0, 0, 0, 0, 0, 0, 164, 1, 0, 0, 0, '', 12340);
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` IN (50004, 50006);

DELETE FROM `creature` WHERE `id`=37003;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200988, 37003, 631, 15, 1, 0, 0, -562.385, 2217.58, 199.969, 3.46228, 86400, 0, 0, 398434, 41690, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `id`=37026;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(201020, 37026, 631, 15, 1, 0, 0, -571.091, 2219.71, 199.969, 5.06842, 86400, 0, 0, 269600, 91600, 0, 0, 0, 0);
		
		
				#####################
				# 	 SCRIPTNAME 	#
				#####################
UPDATE `creature_template` SET `ScriptName` = 'npc_muradin_gunship' WHERE `entry` = 36948;
UPDATE `creature_template` SET `ScriptName` = 'npc_saurfang_gunship' WHERE `entry` = 36939;
UPDATE `creature_template` SET `ScriptName` = 'npc_zafod_boombox' WHERE `entry` = 37184;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_defender' WHERE `entry` = 37032;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_primalist' WHERE `entry` = 37030;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_vindicator' WHERE `entry` = 37003;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_protector' WHERE `entry` = 36998;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_spire_frostwyrm' WHERE `entry` = 37230;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_axethrower_rifleman' WHERE `entry` = 36968;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_axethrower_rifleman' WHERE `entry` = 36969;

UPDATE `creature_template` SET `ScriptName` = 'npc_mortar_soldier_or_rocketeer', AIName = '' WHERE `entry` = 36982;
UPDATE `creature_template` SET `ScriptName` = 'npc_mortar_soldier_or_rocketeer', AIName = '' WHERE `entry` = 36978;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_mage' WHERE `entry` = 37117;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_mage' WHERE `entry` = 37116;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_trigger' WHERE `entry` = 37547;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_portal' WHERE `entry` = 37227;
UPDATE `creature_template` SET `ScriptName` = 'npc_marine_or_reaver' WHERE `entry` = 36957;
UPDATE `creature_template` SET `ScriptName` = 'npc_marine_or_reaver' WHERE `entry` = 36950;
UPDATE `creature_template` SET `ScriptName` = 'npc_sergeant' WHERE `entry` = 36960;
UPDATE `creature_template` SET `ScriptName` = 'npc_sergeant' WHERE `entry` = 36961;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_skybreaker' WHERE `entry` = 37540;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_orgrimmar' WHERE `entry` = 37215;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36838;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36839;
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=37184;

UPDATE `gameobject_template` SET `ScriptName` = 'transport_gunship' WHERE `entry` IN (201580, 201812);

UPDATE item_template SET ScriptName = 'item_icc_rocket_pack' WHERE entry = 49278;

		################################
		# FIX  NPC & GAMEOBJECT & ITEM #
		################################

UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 69399, `spell2` = 69401 WHERE entry = 36839;
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 70172, `spell2` = 70174 WHERE entry = 36838;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (36939, 38156, 38637, 38638);
UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71339, `spell2` = 70161, `spell3` = 72539, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36968, 38403, 38675, 38676);
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71335, `spell2` = 70162, `spell3` = 72566, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36969, 38408, 38689, 38690);
UPDATE `creature_template` SET `difficulty_entry_1` = '38129',`difficulty_entry_2` = '38701', `difficulty_entry_3` = '38702' WHERE `entry` =37215;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `minlevel` = 83, `maxlevel` = 83, `unit_flags` = 4, `flags_extra` = 2, `modelid1` = 1126, `modelid2` = 11686 WHERE `entry` IN (37215, 38129, 38701, 38702, 37540, 38128, 38699, 38700);

UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 201872;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 201873;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 201874;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 201875;
UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 202177;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 202178;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 202179;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 202180;

DELETE FROM creature WHERE id IN (37230, 36838, 36839, 36948, 36939);
DELETE FROM `creature_template_addon` WHERE (`entry`=37547);
UPDATE `creature_template` SET `flags_extra` = 130 WHERE `entry` = 37547;


DELETE FROM `creature_template_addon` WHERE `entry` IN (36838, 36839);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36838, 0, 0, 0, 1, 0, 69470),
(36839, 0, 0, 0, 1, 0, 69470);


	##########################
	#		   LOOTS	     #
	##########################
DELETE FROM `gameobject_loot_template` WHERE (`entry`=201872);
INSERT INTO `gameobject_loot_template` VALUES
(201872, 49426, 100, 1, 0, 2, 2),
(201872, 50340, 0, 1, 1, 1, 1),
(201872, 50787, 0, 1, 1, 1, 1),
(201872, 50788, 0, 1, 1, 1, 1),
(201872, 50789, 0, 1, 2, 1, 1),
(201872, 50790, 0, 1, 2, 1, 1),
(201872, 50791, 0, 1, 1, 1, 1),
(201872, 50792, 0, 1, 2, 1, 1),
(201872, 50793, 0, 1, 1, 1, 1),
(201872, 50794, 0, 1, 1, 1, 1),
(201872, 50795, 0, 1, 2, 1, 1),
(201872, 50796, 0, 1, 2, 1, 1),
(201872, 50797, 0, 1, 2, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE (`entry`=201873);
INSERT INTO `gameobject_loot_template` VALUES
(201873, 49426, 100, 1, 0, 2, 2),
(201873, 49908, 10, 1, 0, 1, 1),
(201873, 49998, 0, 1, 1, 1, 1),
(201873, 49999, 0, 1, 2, 1, 1),
(201873, 50000, 0, 1, 2, 1, 1),
(201873, 50001, 0, 1, 3, 1, 1),
(201873, 50002, 0, 1, 2, 1, 1),
(201873, 50003, 0, 1, 3, 1, 1),
(201873, 50005, 0, 1, 1, 1, 1),
(201873, 50006, 0, 1, 3, 1, 1),
(201873, 50008, 0, 1, 1, 1, 1),
(201873, 50009, 0, 1, 3, 1, 1),
(201873, 50010, 0, 1, 2, 1, 1),
(201873, 50011, 0, 1, 1, 1, 1),
(201873, 50274, 37.5, 1, 0, 1, 1),
(201873, 50352, 0, 1, 1, 1, 1),
(201873, 50359, 0, 1, 2, 1, 1),
(201873, 50411, 0, 1, 3, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE (`entry`=201874);
INSERT INTO `gameobject_loot_template` VALUES
(201874, 49426, 100, 1, 0, 2, 2),
(201874, 49908, 10, 1, 0, 1, 1),
(201874, 50345, 0, 1, 2, 1, 1),
(201874, 51906, 0, 1, 1, 1, 1),
(201874, 51907, 0, 1, 1, 1, 1),
(201874, 51908, 0, 1, 1, 1, 1),
(201874, 51909, 0, 1, 2, 1, 1),
(201874, 51910, 0, 1, 2, 1, 1),
(201874, 51911, 0, 1, 2, 1, 1),
(201874, 51912, 0, 1, 2, 1, 1),
(201874, 51913, 0, 1, 1, 1, 1),
(201874, 51914, 0, 1, 2, 1, 1),
(201874, 51915, 0, 1, 1, 1, 1),
(201874, 51916, 0, 1, 1, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE (`entry`=201875);
INSERT INTO `gameobject_loot_template` VALUES
(201875, 49426, 100, 1, 0, 2, 2),
(201875, 49908, 10, 1, 0, 1, 1),
(201875, 50274, 75, 1, 0, 1, 1),
(201875, 50349, 0, 1, 2, 1, 1),
(201875, 50366, 0, 1, 1, 1, 1),
(201875, 50653, 0, 1, 3, 1, 1),
(201875, 50654, 0, 1, 3, 1, 1),
(201875, 50655, 0, 1, 3, 1, 1),
(201875, 50656, 0, 1, 2, 1, 1),
(201875, 50657, 0, 1, 3, 1, 1),
(201875, 50658, 0, 1, 1, 1, 1),
(201875, 50659, 0, 1, 2, 1, 1),
(201875, 50660, 0, 1, 1, 1, 1),
(201875, 50661, 0, 1, 1, 1, 1),
(201875, 50663, 0, 1, 2, 1, 1),
(201875, 50664, 0, 1, 2, 1, 1),
(201875, 50665, 0, 1, 1, 1, 1),
(201875, 50667, 0, 1, 3, 1, 1);