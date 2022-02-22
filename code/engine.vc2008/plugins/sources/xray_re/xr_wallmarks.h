#ifndef __GNUC__
#pragma once
#endif
#ifndef __XR_WALLMARKS_H__
#define __XR_WALLMARKS_H__

#include <vector>
#include "xr_types.h"
#include "xr_vector3.h"
#include "xr_color.h"

namespace xray_re {

// Common definitions.
struct wm_vertex {
	fvector3	p;
	rgba32		color;
	float		u, v;
};

typedef std::vector< wm_vertex > wm_vertex_vec; typedef std::vector< wm_vertex >::iterator wm_vertex_vec_it; typedef std::vector< wm_vertex >::const_iterator wm_vertex_vec_cit;

} // end of namespace xray_re

#endif
