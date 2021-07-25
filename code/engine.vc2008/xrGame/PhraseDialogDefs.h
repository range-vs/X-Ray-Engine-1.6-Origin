#pragma once

#include "../xrCore/intrusive_ptr.h"

class CPhraseDialog;

typedef intrusive_ptr<CPhraseDialog>	DIALOG_SHARED_PTR;

#include "PhraseDialog.h"

typedef xr_vector< shared_str > DIALOG_ID_VECTOR; typedef DIALOG_ID_VECTOR::iterator DIALOG_ID_IT;
