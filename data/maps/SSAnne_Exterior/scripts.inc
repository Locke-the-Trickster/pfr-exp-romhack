SSAnne_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAnne_Exterior_OnFrame
	.byte 0

SSAnne_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	call_if_set FLAG_GOT_HM01, SSAnne_Exterior_EventScript_RemoveSlowpoke
	call_if_set FLAG_BADGE08_GET, SSAnne_Exterior_EventScript_MewFightCheck
	end

SSAnne_Exterior_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 1, SSAnne_Exterior_ExitSSAnne
	.2byte 0

SSAnne_Exterior_ExitSSAnne::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_le VAR_0x8005, 6, SSAnne_Exterior_WalkDown
	call_if_ge VAR_0x8005, 7, SSAnne_Exterior_WalkInPlaceDown
	fadenewbgm MUS_SURF
	delay 50
	special DoSSAnneDepartureCutscene
	waitstate
	removeobject LOCALID_SS_ANNE
	applymovement LOCALID_PLAYER, SSAnne_Exterior_Movement_Exit
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 2
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	warp MAP_VERMILION_CITY, 23, 34
	waitstate
	releaseall
	end

SSAnne_Exterior_WalkDown::
	applymovement LOCALID_PLAYER, SSAnne_Exterior_Movement_WalkDown
	waitmovement 0
	return

SSAnne_Exterior_WalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SSAnne_Exterior_Movement_Exit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SSAnne_Exterior_Movement_WalkDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_Exterior_EventScript_TryRemoveMew::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

SSAnne_Exterior_EventScript_MewFightCheck::
	call_if_unset FLAG_FOUGHT_MEW, SSAnne_Exterior_EventScript_ShowMew
	return

SSAnne_Exterior_EventScript_ShowMew::
	clearflag FLAG_HIDE_MEW
	return

SSAnne_Exterior_EventScript_Mew::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_MEW, 75
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SSAnne_Exterior_EventScript_DefeatedMew
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SSAnne_Exterior_EventScript_RanFromMew
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SSAnne_Exterior_EventScript_RanFromMew
	setflag FLAG_FOUGHT_MEW
	setflag FLAG_HIDE_MEW
	release
	end

SSAnne_Exterior_EventScript_DefeatedMew::
	setflag FLAG_FOUGHT_MEW
	goto EventScript_RemoveStaticMon
	end

SSAnne_Exterior_EventScript_RanFromMew::
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_MonFlewAway
	end

SSAnne_Exterior_EventScript_RemoveSlowpoke::
	setflag FLAG_HIDE_SSANNEEXT_SLOWPOKE
	removeobject LOCALID_SSANNE_SLOWPOKE
	return

SSAnne_Exterior_EventScript_Slowpoke::
	lock
	faceplayer
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox SSAnne_Exterior_Text_SlowpokeTalk
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	releaseall
	end

SSAnne_Exterior_Text_SlowpokeTalk::
	.string "Ssloowwww...? Zzz....$"

