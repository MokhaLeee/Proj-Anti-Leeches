#include "AntiLeeches.h"
static bool IsWeaponShouldSkip(ItemData*);

bool gCheckFunc_UnitGrowth(void){
	CharacterData* CurChar = NULL;
	
	for(u8 i=0; UnitCheckList[i]; i++ )
	{
		CurChar = &(*gpUnitTable)[UnitCheckList[i]-1];
		if( CurChar->growthPow > MaxGrowth ) return TRUE;
		if( CurChar->growthSkl > MaxGrowth ) return TRUE;
		if( CurChar->growthSpd > MaxGrowth ) return TRUE;
		if( CurChar->growthDef > MaxGrowth ) return TRUE;
		if( CurChar->growthRes > MaxGrowth ) return TRUE;
	}
	return FALSE;
}



bool gCheckFunc_UnitBase(void){
	u8 i = 0;
	CharacterData* CurChar = NULL;
	
	for(i=0; UnitCheckList_BaseStatusForLowerClass[i]; i++ )
	{
		CurChar = &(*gpUnitTable)[UnitCheckList_BaseStatusForLowerClass[i]-1];
		if( CurChar->basePow > UnitStatusBase_Low ) return TRUE;
		if( CurChar->baseSkl > UnitStatusBase_Low ) return TRUE;
		if( CurChar->baseSpd > UnitStatusBase_Low ) return TRUE;
		if( CurChar->baseDef > UnitStatusBase_Low ) return TRUE;
		if( CurChar->baseRes > UnitStatusBase_Low ) return TRUE;
	}
	
	for(i=0; UnitCheckList_BaseStatusForHigherClass[i]; i++ )
	{
		CurChar = &(*gpUnitTable)[UnitCheckList_BaseStatusForHigherClass[i]-1];
		if( CurChar->basePow > UnitStatusBase_High ) return TRUE;
		if( CurChar->baseSkl > UnitStatusBase_High ) return TRUE;
		if( CurChar->baseSpd > UnitStatusBase_High ) return TRUE;
		if( CurChar->baseDef > UnitStatusBase_High ) return TRUE;
		if( CurChar->baseRes > UnitStatusBase_High ) return TRUE;
	}
	
	return FALSE;
}


bool gCheckFunc_WpnBonus(void){
	u8 i = 0;
	ItemData* CurWpn = NULL;
	
	for(i=0; i<0xCD; i++)
	{
		CurWpn = &(*gpItemTable)[i];
		
		if( (1&CurWpn->attributes) & (0xB!=CurWpn->weaponType) & (!IsWeaponShouldSkip(CurWpn)) & (0!=CurWpn->pStatBonuses) )
		{
			if( CurWpn->pStatBonuses->hpBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->powBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->sklBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->spdBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->defBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->resBonus > MaxWpnBonus ) return TRUE;
			if( CurWpn->pStatBonuses->lckBonus > MaxWpnBonus ) return TRUE;
		
		}
	}
	
	return FALSE;
}

static bool IsWeaponShouldSkip(ItemData* itemdata){
	for(u8 j=0; WpnExceptList[j]; j++)
		if( WpnExceptList[j] == itemdata->number )
			return TRUE;
	return FALSE;
}