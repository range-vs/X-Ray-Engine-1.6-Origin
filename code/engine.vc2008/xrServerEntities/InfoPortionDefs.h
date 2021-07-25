#pragma once


typedef shared_str INFO_DATA;
typedef xr_vector< INFO_DATA > KNOWN_INFO_VECTOR; typedef KNOWN_INFO_VECTOR::iterator KNOWN_INFO_VECTOR_IT;

class CFindByIDPred
{
public:
	CFindByIDPred(shared_str element_to_find) {element = element_to_find;}
	IC bool operator () (const INFO_DATA& data) const {return data == element;}
private:
	shared_str element;
};
