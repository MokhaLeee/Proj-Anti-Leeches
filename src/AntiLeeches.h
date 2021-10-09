#ifndef ANTI_LEECHES
#define ANTI_LEECHES

#include "include/gbafe.h"

extern void NewGameCtrl(void);  // 0x8009F08 in FE8U
extern ItemData** gpItemTable;
extern CharacterData** gpUnitTable;


typedef bool (*CheckLeech_Func)(void);
extern const CheckLeech_Func CheckFuncList[];

extern const u8 MaxGrowth;
extern const u8 UnitStatusBase_Low;
extern const u8 UnitStatusBase_High;
extern const u8 UnitCheckList[];
extern const u8 UnitCheckList_BaseStatusForLowerClass[];
extern const u8 UnitCheckList_BaseStatusForHigherClass[];

extern const u8 MaxWpnBonus;
extern const u8 WpnExceptList[];


// Functions
void OnGameInitCheck(void);
bool CheckLeeches(void);

#endif //ANTI_LEECHES