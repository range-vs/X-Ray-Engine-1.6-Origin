#ifndef __GNUC__
#pragma once
#endif
#ifndef __XR_LEVEL_WALLMARKS_H__
#define __XR_LEVEL_WALLMARKS_H__

#include <string>
#include <vector>
#include "xr_sphere.h"
#include "xr_wallmarks.h"

namespace xray_re {

struct wm_data {
	fsphere		bounds;
	wm_vertex_vec	vertices;
};

typedef std::vector< wm_data > wm_data_vec; typedef std::vector< wm_data >::iterator wm_data_vec_it; typedef std::vector< wm_data >::const_iterator wm_data_vec_cit;

struct wm_slot {
	std::string	shader;
	std::string	texture;
	wm_data_vec	wallmarks;
};

typedef std::vector< wm_slot* > wm_slot_vec; typedef std::vector< wm_slot* >::iterator wm_slot_vec_it; typedef std::vector< wm_slot* >::const_iterator wm_slot_vec_cit;

class xr_reader;
class xr_writer;

class xr_level_wallmarks {
public:
			xr_level_wallmarks(xr_reader& r);
			~xr_level_wallmarks();

	void		load(xr_reader& r);
	void		save(xr_writer& w) const;

	const wm_slot_vec&	slots() const;

private:
	wm_slot_vec	m_slots;
};

inline xr_level_wallmarks::xr_level_wallmarks(xr_reader& r) { load(r); }
inline const wm_slot_vec& xr_level_wallmarks::slots() const { return m_slots; }

} // end of namespace xray_re

#endif
