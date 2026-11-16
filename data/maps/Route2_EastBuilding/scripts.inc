.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_TM_REST, Route2_EastBuilding_EventScript_AlreadyGotRest
	msgbox Route2_EastBuilding_Text_GiveTM44IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_TM44
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedTM44FromAide, ITEM_TM44
	msgbox Route2_EastBuilding_Text_ReceivedTM44FromAide
	setflag FLAG_GOT_TM_REST
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotRest::
	msgbox Route2_EastBuilding_Text_ExplainRest
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_TM44
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end
