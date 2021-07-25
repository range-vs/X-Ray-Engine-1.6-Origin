//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "../Include/stack_trace.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ElTree"
#pragma link "ElXPThemedControl"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

typedef unsigned int u32;
#define TYPE_OBJECT 1

bool __fastcall TForm1::MakeName(TElTreeItem* begin_item, TElTreeItem* end_item, AnsiString& name, bool bOnlyFolder)
{
	name = "";
	if (begin_item){
		TElTreeItem* node = (u32(begin_item->Data)==TYPE_OBJECT)?begin_item->Parent:begin_item;
		while (node){
			name.Insert(node->Text+AnsiString('\\'),0);
        	if (node==end_item) break;
            node=node->Parent;
		}
        if (!bOnlyFolder){
			if (u32(begin_item->Data)==TYPE_OBJECT)
				name+=begin_item->Text;
			else
				return false;
        }
        return true;
    }else{
        return false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::tvItemsItemChange(TObject *Sender, TElTreeItem *Item, TItemChangeMode ItemChangeMode)

{
	if (Item&&(ItemChangeMode==icmCheckState))
	{
		DEBUG_MESSAGE("IN!")
        AnsiString fn;
		MakeName(Item,0,fn,false);
		DEBUG_MESSAGE("CREATE NAME!")
        DEBUG_MESSAGE(fn.c_str())
		TElTreeItem *node = tvMulti->Items->LookForItem(0,fn.c_str(),0,0,false,true,false,true,true);
		DEBUG_MESSAGE("GET NODE!")
		if (node&&!Item->Checked)
		{
			node->Delete();
        }
		if (!node&&Item->Checked)
		{
			if ((tvMulti->Items->Count+1)<=256)
			{
                DEBUG_MESSAGE("START ADD!")
				tvMulti->Items->AddObject(0,fn,(void*)TYPE_OBJECT);
				DEBUG_MESSAGE("ADD!")
			}
			else
			{
				Item->Checked 	= false;
            }
		}
		DEBUG_MESSAGE("OUT!")
	}
}
//---------------------------------------------------------------------------

