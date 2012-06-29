-- http://github.com/Pixel-Pirate/LibDev
-- Remerciement particulier à Vlad.
-- Contribution : Lockas

-- Boss faction
DELETE FROM `creature_template` WHERE (`entry`=50004);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(50004, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'High Overlord Saurfang', '', '', 0, 80, 80, 3, 1802, 1802, 0, 0, 0, 1, 1, 252, 357, 0, 304, '7.5', 2000, 0, 1, 33554432, 8, 0, 0, 0, 0, 0, 215, 320, 44, 7, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340);

DELETE FROM `creature_template` WHERE (`entry`=50006);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(50006, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Muradin Bronzebeard', '', '', 10875, 83, 83, 2, 1802, 1802, 1, 1, '1.14286', 1, 1, 468, 702, 0, 175, '47.2', 2000, 2000, 1, 33554432, 8, 0, 0, 0, 0, 0, 374, 562, 140, 7, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15284, 70309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 175, 1, 1, 0, 0, 0, 0, 0, 0, 0, 164, 1, 0, 0, 0, '', 12340);
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` IN (50004, 50006);

UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (36939, 38156, 38637, 38638);

UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71339, `spell2` = 70161, `spell3` = 72539, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36968, 38403, 38675, 38676);
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71335, `spell2` = 70162, `spell3` = 72566, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36969, 38408, 38689, 38690);

-- Spells
UPDATE `creature_template` SET `unit_flags` = 33554564, `flags_extra` = 2 WHERE `entry` IN (37044, 37041);
UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801 WHERE `entry` = 37044;
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802 WHERE `entry` = 37041;
DELETE FROM `creature_template_addon` WHERE `entry` IN (37044, 37041);
SET @KORKRON := 37044; 
SET @SKYBREAKER := 37041;
SET @HSPELL := 69809;
SET @ASPELL := 69808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@KORKRON, @SKYBREAKER);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@KORKRON, @SKYBREAKER);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KORKRON ,0,0,0,25,0,100,1,0,0,0,0,11,@HSPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Kor''kron - spell 69809'),
(@SKYBREAKER,0,0,0,25,0,100,1,0,0,0,0,11,@ASPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Skybreaker - spell 69808');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71193 AND `spell_effect` = -71188;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71195 AND `spell_effect` = -71193;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 68645 AND `spell_effect` = 69193;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 73077 AND `spell_effect` = 69188;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 73077 AND `spell_effect` = 68721;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 69193 AND `spell_effect` = 69192;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(71193, -71188, 0, 'Gunship Battle'),
(71195, -71193, 0, 'Gunship Battle'),
(73077, 69188, 2, 'Gunship Battle'),
(68645, 69193, 0, 'Gunship Battle'),
(69193, 69192, 0, 'Gunship Battle');

SET @SPELL := 69705;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,@SPELL,0,18,1,36838,0,0,'','Gunship Battle - Spell 69705'),
(13,0,@SPELL,0,18,1,36839,0,0,'','Gunship Battle - Spell 69705');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (70713, 68645, 69471, 69488, 69402, 70175, 71335, 71339);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('70713', 'spell_icc_remove_rocket_pack'),
('68645', 'spell_rocket_pack'),
('69471', 'spell_gb_heat_drain'),
('69488', 'spell_gb_overheat_drain'),
('69402', 'spell_gb_incinerating_blast'),
('70175', 'spell_gb_incinerating_blast'),
('71335', 'spell_gb_burning_pitch'),
('71339', 'spell_gb_burning_pitch');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69400, 70173, 69402, 70175, 70374, 70383, 72959);
SET @ENTRYA := 37540;
SET @ENTRYH := 37215;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
('13', '69400', '18', '1', @ENTRYA),
('13', '70173', '18', '1', @ENTRYH),
('13', '69402', '18', '1', @ENTRYA),
('13', '70175', '18', '1', @ENTRYH),
('13', '70374', '18', '1', @ENTRYA),
('13', '70383', '18', '1', @ENTRYH),
('13', '72959', '18', '1', 0);

-- Gunship cannons
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` AND `SourceEntry` IN (69400,69402,70173,70715);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,0,69400,0,18,1,37540,0,0, '', NULL),
(13,0,69402,0,18,1,37540,0,0, '', NULL),
(13,0,70173,0,18,1,37215,0,0, '', NULL),
(13,0,70175,0,18,1,37215,0,0, '', NULL); 
DELETE FROM `creature_template` WHERE `entry` IN (36838,36839);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(36838,35410,0,0,0,0,29488,0,0,0,'Cannon de l\'Alliance','','vehichleCursor',0,80,80,0,1732,1732,0,0,0,1,0,422,586,0,642,1,0,0,1,0,16384,0,0,0,0,0,345,509,103,9,8,0,0,0,0,0,0,0,0,0,70172,70174,0,0,0,0,0,0,0,554,0,0,'SmartAI',0,3,65.5185,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'',12340),
(36839,35427,0,0,0,0,29489,0,0,0,'Cannon de la Horde','','vehichleCursor',0,80,80,0,1665,1665,0,0,0,1,0,422,586,0,642,1,0,0,1,16384,8,0,0,0,0,0,345,509,103,9,8,0,0,0,0,0,0,0,0,0,69399,69401,0,0,0,0,0,0,0,0,0,0,'SmartAI',0,3,65.5185,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'',12340);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (36838,36839);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36838,0,0,0,25,0,100,0,0,0,0,0,75,69470,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Heat Drain'),
(36839,0,0,0,25,0,100,0,0,0,0,0,75,69470,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Heat Drain');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (36838,36839);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES
(36838,46598,0,0,0,1,0,0,0),
(36839,46598,0,0,0,1,0,0,0);

-- Transport
DELETE FROM transports WHERE entry IN (201580, 201581, 201811, 201812);
DELETE FROM creature WHERE id IN (37230, 36838, 36839, 36948, 36939);
DELETE FROM `creature_template_addon` WHERE (`entry`=37547);
UPDATE `creature_template` SET `flags_extra` = 130 WHERE `entry` = 37547;

DELETE FROM `creature_template_addon` WHERE `entry` IN (36838, 36839);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36838, 0, 0, 0, 1, 0, 69470),
(36839, 0, 0, 0, 1, 0, 69470);

UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 69399, `spell2` = 69401 WHERE entry = 36839;
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 70172, `spell2` = 70174 WHERE entry = 36838;
REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `cast_flags`) VALUES
('36838', '46598', '0', '1'),
('36839', '46598', '0', '1');

UPDATE `creature_template` SET `difficulty_entry_1` = '38129',`difficulty_entry_2` = '38701', `difficulty_entry_3` = '38702' WHERE `entry` =37215;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `minlevel` = 83, `maxlevel` = 83, `unit_flags` = 4, `flags_extra` = 2, `modelid1` = 1126, `modelid2` = 11686 WHERE `entry` IN (37215, 38129, 38701, 38702, 37540, 38128, 38699, 38700);

-- Texts
SET @MURADIN := 36948;
SET @OVERLORD := 36939;
SET @PRIMALIST := 37030;
SET @INVOKER := 37033;
SET @DEFENDER := 37032;
SET @VINDICATOR := 37003;
SET @SORCERER := 37026;
SET @PROTECTOR := 36998;
SET @FROSTWYRM := 37230;
SET @SOUNDID :=0;
DELETE FROM `creature_text` WHERE `entry` IN (36948, 36939, 37030, 37033, 37032, 37003, 37026, 36998, 37230);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@MURADIN, 0, 0, 'Faites chauffer les moteurs, on à rencard avec le destin les gars.', 14, 0, 100, 0, 0, 16962, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_0'),
(@MURADIN, 1, 0, 'Accrochez vous à vos casque !', 14, 0, 100, 0, 0, 16963, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_1'),
(@MURADIN, 2, 0, 'Qu\'est ce que c\'est que ce truc ?!', 14, 0, 100, 0, 0, 16964, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_2'),
(@MURADIN, 3, 0, 'Par ma barbe ! HORDE EN APPROCHE ET PAS QU\'A MOITIER!', 14, 0, 100, 0, 0, 16965, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_3'),
(@MURADIN, 4, 0, 'MANOEUVRE D\'ESQUIVE! TOUS A VOS CANNON !', 14, 0, 100, 0, 0, 16966, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_4'),
(@MURADIN, 5, 0, 'Chiens! Vous nous aveuglés !', 14, 0, 100, 0, 0, 16967, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_5'),
(@MURADIN, 6, 0, '', 14, 0, 100, 0, 0, 16968, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_7'),
(@MURADIN, 7, 0, 'La Horde n\a rien à faire ici !', 14, 0, 100, 0, 0, 16969, 'Muradin Bronzebeard - SAY_INTRO_HORDE_3'),
(@MURADIN, 8, 0, '', 14, 0, 100, 0, 0, 16958, 'Muradin Bronzebeard - SAY_BOARDING_SKYBREAKER_1'),
(@MURADIN, 9, 0, 'Sergent à l\'attaque !', 14, 0, 100, 0, 0, 16956, 'Muradin Bronzebeard - SAY_BOARDING_ORGRIMS_HAMMER_0'),
(@MURADIN, 10, 0, 'Fusillier, accélérez le tire !', 14, 0, 100, 0, 0, 16954, 'Muradin Bronzebeard - SAY_NEW_RIFLEMEN_SPAWNED'),
(@MURADIN, 11, 0, 'Mortier recharger !', 14, 0, 100, 0, 0, 16955, 'Muradin Bronzebeard - SAY_NEW_MORTAR_TEAM_SPAWNED'),
(@MURADIN, 12, 0, 'Nous prenons des dommages à la coque, faites taire ces canons!', 14, 0, 100, 0, 0, 16957, 'Muradin Bronzebeard - SAY_NEW_MAGE_SPAWNED'),
(@MURADIN, 13, 0, 'Ne dites pas que je ne vous avais pas prévenu canailles ! Mes frères et soeurs en avant !', 14, 0, 100, 0, 0, 16959, 'Muradin Bronzebeard - SAY_ALLIANCE_VICTORY'),
(@MURADIN, 14, 0, 'Captain Bartlett, get us out of here! We''re taken too much damage to stay afloat!', 14, 0, 100, 0, 0, 16960, 'Muradin Bronzebeard - SAY_ALLIANCE_DEFEAT'),
(@OVERLORD, 0, 0, 'Levez-vous, fils et filles de la Horde! Aujourd\'hui, nous battre un ennemi haï de la Horde! LOK''TAR OGAR!', 14, 0, 100, 0, 0, 17087, 'High Overlord Saurfang - SAY_INTRO_HORDE_0'),
(@OVERLORD, 1, 0, '', 14, 0, 100, 0, 0, 17088, 'High Overlord Saurfang - SAY_INTRO_HORDE_1_1'),
(@OVERLORD, 2, 0, 'Qu\'est ce que c\'est ? Quelque chose approche !', 14, 0, 100, 0, 0, 17089, 'High Overlord Saurfang - SAY_INTRO_HORDE_1'),
(@OVERLORD, 3, 0, 'Vaisseau de l\'Alliance ! TOUT LE MONDE SUR LE PONT !', 14, 0, 100, 0, 0, 17090, 'High Overlord Saurfang - SAY_INTRO_HORDE_2'),
(@OVERLORD, 4, 0, '', 14, 0, 100, 0, 0, 17092, 'High Overlord Saurfang - SAY_INTRO_HORDE_4'),
(@OVERLORD, 5, 0, 'Sergent à l\'attaque !', 14, 0, 100, 0, 0, 17081, 'High Overlord Saurfang - SAY_BOARDING_SKYBREAKER_0'),
(@OVERLORD, 6, 0, 'Vous osez aborder mon vaiseau?! Votre mort sera rapide.', 14, 0, 100, 0, 0, 17083, 'High Overlord Saurfang - SAY_BOARDING_ORGRIMS_HAMMER_1'),
(@OVERLORD, 7, 0, 'Lanceur de hache augmentez la cadence !', 14, 0, 100, 0, 0, 17079, 'High Overlord Saurfang - SAY_NEW_AXETHROWER_SPAWNED'),
(@OVERLORD, 8, 0, 'Rockette rechargée !', 14, 0, 100, 0, 0, 17080, 'High Overlord Saurfang - SAY_NEW_ROCKETEERS_SPAWNED'),
(@OVERLORD, 9, 0, 'Nous prenons des dommages à la coque, faites taire ces canons!', 14, 0, 100, 0, 0, 17082, 'High Overlord Saurfang - SAY_NEW_BATTLE_MAGE_SPAWNED'),
(@OVERLORD, 10, 0, 'L\Alliance est faible. En route vers Arthas !', 14, 0, 100, 0, 0, 17084, 'High Overlord Saurfang - SAY_HORDE_VICTORY'),
(@OVERLORD, 11, 0, 'Soldat du feu, éteignez moi cet incendit ! La Horde n\'a pas dit son dernier mot.', 14, 0, 100, 0, 0, 17085, 'High Overlord Saurfang - SAY_HORDE_DEFEAT'),
(@OVERLORD, 12, 0, 'Ce n\'est pas votre combat, nain. Faites demi tour ou nous serons obligés de détruire votre vaisseau.', 14, 0, 100, 0, 0, 17093, 'High Overlord Saurfang - SAY_INTRO_ALLIANCE_6'),
(@PRIMALIST,0, 0, 'Remercier les esprits, frères et sœurs. Le Brise-ciel est en déroute. En avant !', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Primalist - SAY_FIRST_SQUAD_RESCUED_HORDE_0'),
(@INVOKER, 0, 0, 'Cela devrait vous aider!', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_FIRST_SQUAD_RESCUED_HORDE_1'),
(@INVOKER, 1, 0, '%s lance l\'event.', 16, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_SUMMON_BATTLE_STANDARD'),
(@DEFENDER, 0, 0, 'Bravo, braves guerriers. L\'alliance est en grand nombre ici.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_0'),
(@DEFENDER, 1, 0, 'Captain Saurfang will be pleased to see you aboard Orgrim''s Hammer. Make haste, we will secure the area until you are ready for take-off.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_1'),
(@DEFENDER, 2, 0, 'Un cri strident provient dans haut!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@VINDICATOR, 0, 0, 'Dieu merci, vous êtes arrivé. Marteau d\'Orgrim est déjà parti. Vite vous pourrez peut-être pour les attraper.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Vindicator - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_0'),
(@SORCERER, 0, 0, 'Cela devrait vous aider!', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Sorcerer - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_1'),
(@SORCERER, 1, 0, '%s lance l\'event.', 16, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Sorcerer - SAY_SUMMON_BATTLE_STANDARD'),
(@PROTECTOR,0, 0, 'Mes remerciements. Nous avons été plus nombreux que jusqu\'à ce que vous arrivé.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_0'),
(@PROTECTOR,1, 0, 'Le capitaine Muradin attend à bord du Brise-ciel. Nous allons sécuriser la zone jusqu\'à ce que vous êtes prêt pour le décollage.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_1'),
(@PROTECTOR,2, 0, 'Infanterie Brise-ciel, maintenez la position!', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_2'),
(@PROTECTOR,3, 0, 'Un cri strident provient dans haut!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@FROSTWYRM,0, 0, '', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_H_1'),
(@FROSTWYRM,1, 0, '', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_A_2');

REPLACE INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50004, 1, 0, 'Sergent à l\'attaque !', 14, 0, 0, 0, 0, 17081, ''),
(50004, 0, 0, 'Ce n\'est pas votre combat, nain. Faites demi tour ou nous serons obligés de détruire votre vaisseau.', 14, 0, 0, 0, 0, 17093, ''),
(50006, 1, 0, 'Soldat à l\'attaque !', 14, 0, 0, 0, 0, 16956, ''),

-- Loot
UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 201872;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 201873;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 201874;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 201875;
UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 202177;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 202178;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 202179;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 202180;

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

-- FIX

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
UPDATE `gameobject_template` SET `ScriptName` = 'transport_gunship' WHERE `entry` IN (201580, 201812);
UPDATE item_template SET ScriptName = 'item_icc_rocket_pack' WHERE entry = 49278;

UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 201872;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 201873;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 201874;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 201875;
UPDATE `gameobject_template` SET `data1` = 201872 WHERE `entry` = 202177;
UPDATE `gameobject_template` SET `data1` = 201873 WHERE `entry` = 202178;
UPDATE `gameobject_template` SET `data1` = 201874 WHERE `entry` = 202179;
UPDATE `gameobject_template` SET `data1` = 201875 WHERE `entry` = 202180;

UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=37184;

DELETE FROM `creature` WHERE `id`=37003;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200988, 37003, 631, 15, 1, 0, 0, -562.385, 2217.58, 199.969, 3.46228, 86400, 0, 0, 398434, 41690, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `id`=37026;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(201020, 37026, 631, 15, 1, 0, 0, -571.091, 2219.71, 199.969, 5.06842, 86400, 0, 0, 269600, 91600, 0, 0, 0, 0);

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5630, 5628);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5628,'at_icc_land_frostwyrm'),
(5630,'at_icc_land_frostwyrm');