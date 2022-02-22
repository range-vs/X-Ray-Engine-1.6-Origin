#ifndef __GNUC__
#pragma once
#endif
#ifndef __XR_SHAPE_H__
#define __XR_SHAPE_H__

#include <vector>
#include "xr_types.h"
#include "xr_sphere.h"
#include "xr_matrix.h"

namespace xray_re {

enum {
	SHAPE_SPHERE	= 0,
	SHAPE_BOX	= 1,
};

struct shape_def {
	uint8_t		type;
	union {
		fsphere	sphere;
		fmatrix	box;
	};
};

typedef std::vector< shape_def > shape_def_vec; typedef std::vector< shape_def >::iterator shape_def_vec_it; typedef std::vector< shape_def >::const_iterator shape_def_vec_cit;

} // end of namespace xray_re

#endif
