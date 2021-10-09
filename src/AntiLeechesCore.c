
#include "AntiLeeches.h"

void OnGameInitCheck(void){
	
	if( CheckLeeches() )
		while(1);
	else
		NewGameCtrl();
	return;
}


bool CheckLeeches(void){
	const CheckLeech_Func* it = CheckFuncList;
	
	while(*it)
		if( TRUE == (*it++)() )
			return TRUE;
	return FALSE;
}


const struct ItemStatBonuses* NewGetItemStatBonus(u16 item){
	return (*gpItemTable)[item&0xFF].pStatBonuses;
}