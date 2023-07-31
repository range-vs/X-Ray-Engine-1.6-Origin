#include "stdafx.h"
#pragma hdrstop

#include "ui_scale.hpp"


constexpr const int scaleLineHeightTree {5};

static void _scaleBy(TElTree* arg)
{
	if(arg)
	{
		std::cout << arg->Font->Height << std::endl;
		arg->LineHeight = std::abs(arg->Font->Height) + scaleLineHeightTree;
	}
}

void __fastcall scaleBy(TForm* Sender)
{
	if(Sender)
		Sender->ScaleBy(Sender->PixelsPerInch, 96);
}

void __fastcall scaleBy(TForm* Sender, const std::initializer_list<TElTree*>& list)
{
	scaleBy(Sender);
	for(auto&& l: list)
		_scaleBy(l);
}

