//---------------------------------------------------------------------------

#ifndef DOOneColorH
#define DOOneColorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include "ElHeader.hpp"
#include <Grids.hpp>
#include "ElTree.hpp"
#include <Menus.hpp>
#include "multi_color.hpp"
#include "ElXPThemedControl.hpp"
#include "ExtBtn.hpp"

//#include "Edit/ESceneDOTools.h"

//refs
class TfrmDOShuffle;

class TfrmOneColor : public TForm
{
__published:	// IDE-managed Components
	TBevel *Bevel1;
	TBevel *Bevel2;
	TMultiObjColor *mcColor;
	TExtBtn *ebMultiRemove;
	TElTree *tvDOList;
	void __fastcall mcColorMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ebMultiRemoveClick(TObject *Sender);
	void __fastcall tvDOListDragOver(TObject *Sender, TObject *Source, int X,
          int Y, TDragState State, bool &Accept);
	void __fastcall tvDOListDragDrop(TObject *Sender, TObject *Source, int X,
          int Y);
	void __fastcall tvDOListStartDrag(TObject *Sender,
          TDragObject *&DragObject);
	void __fastcall tvDOListItemFocused(TObject *Sender);
private:	// User declarations
	TfrmDOShuffle* m_Parent;
public:
    bool bLoadMode;
    TElTreeItem* FDragItem;
    /*EDetailManager* DM;
    u32 indexColor;
    xr_vector<TfrmOneColor*>* color_indices;*/

public:		// User declarations
    __fastcall TfrmOneColor(TComponent* Owner);
    void __fastcall ShowIndex(TfrmDOShuffle* parent/*, EDetailManager* dm, xr_vector<TfrmOneColor*>* color_indices*/);
    void __fastcall HideIndex();
    void __fastcall RemoveObject(LPCSTR text);
    void __fastcall AppendObject(LPCSTR text, LPVOID data);

    /*void __fastcall AddIndexColor();
    void __fastcall AddObjectToIndexColor(const char* name);
    void __fastcall RemoveObjectToIndexColor(const char* name);
    void __fastcall RemoveIndexColor();
    void __fastcall ReplaceObjectsToIndexColor();*/
};
//---------------------------------------------------------------------------

// functors
/*struct ColorIndicesFunctor
{
    u32 findColor;
    ColorIndicesFunctor(u32 fc);
    bool operator()(const std::pair<u32, DOVec>&)const;
}; */

#endif
