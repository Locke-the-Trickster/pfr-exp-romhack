Route2_MapScripts::
	.byte 0

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, Route2_Text_RickIntro, Route2_Text_RickDefeat
	msgbox Route2_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end
