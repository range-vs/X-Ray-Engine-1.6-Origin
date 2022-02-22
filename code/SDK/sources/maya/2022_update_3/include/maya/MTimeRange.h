#ifndef _MTimeRange
#define _MTimeRange
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#include <maya/MTime.h>
#include <maya/MTypes.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! \brief Mathematic type that represent a set of time [min, max], i.e. {t | min <= t <= max}
//! \note  An open interval (min, max) can be represented by [min + 1_tick, max - 1_tick]
struct OPENMAYA_EXPORT MClosedTimeInterval
{
	//! \brief The lower bound of the set if the set is not empty
	MTime min;
	//! \brief The upper bound of the set if the set is not empty
	MTime max;
	//! \brief Check if the set is empty
	bool empty() const noexcept { return min > max; }
};

//! \brief	Mathematic type that represent a set of pseudo-real-number (in the unit of time), such as [-1s, +1s] U [+2, +5s]
//!
//! Allows to query if a specific time-point or time-interval is contained in this set
//!
//! \warning	Unlike MTime, Maya represent the time in MTimeRange with an 64-bits signed integer (ticks) (1 tick == 1/6000 second).
//!				The time you can represent in this range is [0.167 milliseconds, 48 million-years).
//!				For times smaller than 1 tick, Maya will round it to the closest tick.
//!				For times greater than 2^62 ticks, Maya may consider them as 'infinity' and arithmetic rules may not work properly.
//!				For times greater than 2^63 ticks, result are overflowed and any use of them are undefined behavior.
class OPENMAYA_EXPORT MTimeRange {
public:
	MTimeRange();
	~MTimeRange();
	MTimeRange(MTime, MTime) noexcept;
	MTimeRange(const MTimeRange&);
	MTimeRange& operator=(const MTimeRange&);

	/*[[nodiscard]]*/
	bool contains(MTime) const noexcept;
	/*[[nodiscard]]*/
	bool contains(MTime, MTime) const noexcept;
	/*[[nodiscard]]*/
	bool intersects(MTime, MTime) const noexcept;
	/*[[nodiscard]]*/
	bool empty() const noexcept;
	/*[[nodiscard]]*/
	MClosedTimeInterval bounds() const noexcept;

BEGIN_NO_SCRIPT_SUPPORT:
	MTimeRange(MTimeRange&&);
	MTimeRange& operator=(MTimeRange&&);
	//! \brief Checks if this set is an empty set
	explicit operator bool() const { return !empty(); }
END_NO_SCRIPT_SUPPORT:

	/*[[nodiscard]]*/
	MTimeRange operator| (const MTimeRange&) const;

	/*[[nodiscard]]*/
	bool operator==(const MTimeRange&) const noexcept;
	/*[[nodiscard]]*/
	bool operator!=(const MTimeRange& rhs) const { return !(*this == rhs); }
private:
	alignas(8) char _storage[128];
};

OPENMAYA_NAMESPACE_CLOSE
#endif