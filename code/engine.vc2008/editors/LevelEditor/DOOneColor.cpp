#include "stdafx.h"
#pragma hdrstop

#include "DOOneColor.h"
#include "DOShuffle.h"
#include "../xrEProps/ColorPicker.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ElXPThemedControl"
#pragma link "ExtBtn"
#pragma resource "*.dfm"

/*ColorIndicesFunctor::ColorIndicesFunctor(u32 fc):findColor(fc){}

bool ColorIndicesFunctor::operator()(const std::pair<u32, DOVec>& p)const
{
    return p.first == findColor;
} */



//---------------------------------------------------------------------------
__fastcall TfrmOneColor::TfrmOneColor(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

/*void __fastcall TfrmOneColor::AddObjectToIndexColor(const char* name)  // здесь добавляем модельку травы к индексу цвета
{
    EDetail* DO	= DM->FindDOByName(name);
    if (DO && std::find(DM->m_ColorIndices[indexColor].begin(), DM->m_ColorIndices[indexColor].end(), DO) == DM->m_ColorIndices[indexColor].end())
        DM->m_ColorIndices[indexColor].push_back(DO);
}

void __fastcall TfrmOneColor::RemoveObjectToIndexColor(const char* name)  // здесь удаляем модельку травы у индекса цвета
{
    EDetail* DO	= DM->FindDOByName(name);
    DM->m_ColorIndices[indexColor].erase(std::find(DM->m_ColorIndices[indexColor].begin(),
        DM->m_ColorIndices[indexColor].end(),
        DO));
}

void __fastcall TfrmOneColor::ReplaceObjectsToIndexColor() // здесь заеняем индекс цвета у DM->m_ColorIndices
{
     u32 oldIndexColor = indexColor;
     indexColor = color_rgba(GetRValue(mcColor->Brush->Color), GetGValue(mcColor->Brush->Color), GetBValue(mcColor->Brush->Color), 0);

     // обновление нового цвета
     int countIndexColor = std::count_if(DM->m_ColorIndices.begin(), DM->m_ColorIndices.end(), ColorIndicesFunctor(indexColor));
     if(countIndexColor == 0)
     {
          // перенос цветов со старого индекса в новый
          DM->m_ColorIndices.insert(make_pair(indexColor, DOVec()));
          for ( TElTreeItem* node = tvDOList->Items->GetFirstNode(); node; node = node->GetNext())
          {
                AnsiString as = AnsiString(node->Text);
                LPCSTR name = as.c_str();
                EDetail* DO = DM->FindDOByName(name);
                DM->m_ColorIndices[indexColor].push_back(DO);
          }
     }
     else
        DM->m_ColorIndices[indexColor].insert(DM->m_ColorIndices[indexColor].end(), DM->m_ColorIndices[oldIndexColor].begin(), DM->m_ColorIndices[oldIndexColor].end());

     // обновление старого цвета
     countIndexColor = std::count_if(DM->m_ColorIndices.begin(), DM->m_ColorIndices.end(), ColorIndicesFunctor(oldIndexColor));
     if(countIndexColor == 0)
        DM->m_ColorIndices.erase(oldIndexColor);

     // TODO: не забыть обновить ГУИ (для старого цвета, как? -> просто добавить еще один индекс с этими элементами(DM->m_ColorIndices[indexColor].insert(DM->m_ColorIndices[indexColor].end(), DM->m_ColorIndices[oldIndexColor].begin(), DM->m_ColorIndices[oldIndexColor].end());))
     
     //DM->m_ColorIndices.insert(make_pair(indexColor, DM->m_ColorIndices[oldIndexColor]));
     //DM->m_ColorIndices.erase(oldIndexColor);
}

void __fastcall TfrmOneColor::RemoveIndexColor() // здесь удаляем цвет из DM->m_ColorIndices
{
      DM->m_ColorIndices.erase(indexColor); 
}

void __fastcall TfrmOneColor::AddIndexColor() // здесь добавляем цвет к DM->m_ColorIndices
{
    if(DM->m_ColorIndices.find(indexColor) != DM->m_ColorIndices.end())
        DM->m_ColorIndices.insert(make_pair(indexColor, DOVec()));
}*/


void __fastcall TfrmOneColor::ShowIndex(TfrmDOShuffle* parent/*, EDetailManager* dm, xr_vector<TfrmOneColor*>* color_indices*/)
{
	m_Parent = parent;
//	VERIFY(stage);
//	m_CurStage = stage;

    bLoadMode = true;
//    if (m_CurStage){
//    }
    bLoadMode = false;
    Visible=true;

    /*DM = dm;
    this->color_indices = color_indices;
    indexColor = color_rgba(GetRValue(mcColor->Brush->Color), GetGValue(mcColor->Brush->Color), GetBValue(mcColor->Brush->Color), 0);*/
    //AddIndexColor();
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::HideIndex(){
    Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::mcColorMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	u32 color = ((TMultiObjColor*)Sender)->Brush->Color;
	if (SelectColor(&color)){
    	       ((TMultiObjColor*)Sender)->_Set(color);
               m_Parent->bColorIndModif = true;
               //ReplaceObjectsToIndexColor();
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	Action = caFree;
    m_Parent->RemoveColorIndex(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::ebMultiRemoveClick(TObject *Sender)
{
        //RemoveIndexColor();
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::tvDOListDragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
    Accept = false;
    if (Source == tvDOList) return;
	if (Source != m_Parent->tvItems) return;
    for ( TElTreeItem* node = tvDOList->Items->GetFirstNode(); node; node = node->GetNext())
        if (node->Text == m_Parent->FDragItem->Text) return;
	Accept = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::tvDOListDragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
    //AddObjectToIndexColor(((AnsiString)m_Parent->FDragItem->Text).c_str());
    tvDOList->Items->AddObject(0,m_Parent->FDragItem->Text,m_Parent->FDragItem->Data);
    m_Parent->bColorIndModif = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::tvDOListStartDrag(TObject *Sender,
      TDragObject *&DragObject)
{
	FDragItem = tvDOList->ItemFocused;
}
//---------------------------------------------------------------------------

void __fastcall TfrmOneColor::RemoveObject(LPCSTR text){
    for ( TElTreeItem* node = tvDOList->Items->GetFirstNode(); node; node = node->GetNext())
    {
        /*Msg(text);
        Msg(((AnsiString)node->Text).c_str());
        Msg("---");*/
        if (node->Text == (WideString)text){
                //RemoveObjectToIndexColor(text);
		node->Delete();
        	return;
        }
    }
}

void __fastcall TfrmOneColor::AppendObject(LPCSTR text, LPVOID data)
{
    for ( TElTreeItem* node = tvDOList->Items->GetFirstNode(); node; node = node->GetNext())
        if (node->Text == (WideString)text) return;
    tvDOList->Items->AddObject(0,text,data);
}

void __fastcall TfrmOneColor::tvDOListItemFocused(TObject *Sender)
{
	m_Parent->OnItemFocused		(tvDOList);
}
//---------------------------------------------------------------------------


