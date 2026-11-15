Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_OnTransition
	.byte 0

Route25_OnTransition::
	call_if_unset FLAG_SYS_GAUNTLET, Route25_EventScript_Gauntlet
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_EventScript_Gauntlet::
	setflag FLAG_SYS_GAUNTLET
	end
