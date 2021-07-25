#include "stdafx.h"
#pragma hdrstop

#include "xrHemisphere.h"

#define HEMI1_VERTS	26
#define HEMI1_FACES	40
#define HEMI2_VERTS	91
#define HEMI2_FACES	160
#define HEMI3_VERTS	196

#pragma warning (disable:4305)
const Fvector hemi_1[HEMI1_VERTS] = {
	{ 0.525730f,	 0.850655f,	-0.000000f},
	{ 0.162460f,	 0.850655f,	 0.500000f},
	{ 0.000000f,	 1.000000f,	-0.000000f},
	{-0.425324f,	 0.850655f,	 0.309015f},
	{-0.425324f,	 0.850655f,	-0.309017f},
	{ 0.162460f,	 0.850655f,	-0.500000f},
	{ 0.688194f,	 0.525730f,	 0.500000f},
	{-0.262865f,	 0.525730f,	 0.809013f},
	{-0.850647f,	 0.525730f,	-0.000001f},
	{-0.262865f,	 0.525730f,	-0.809021f},
	{ 0.688194f,	 0.525730f,	-0.500000f},
	{ 0.894424f,	 0.447212f,	-0.000000f},
	{ 0.276394f,	 0.447212f,	 0.850647f},
	{-0.723610f,	 0.447212f,	 0.525730f},
	{-0.723610f,	 0.447212f,	-0.525734f},
	{ 0.276394f,	 0.447212f,	-0.850655f},
	{ 0.951057f,	 0.000000f,	 0.309017f},
	{ 0.587788f,	 0.000000f,	 0.809013f},
	{ 0.000000f,	 0.000000f,	 1.000000f},
	{-0.587784f,	 0.000000f,	 0.809013f},
	{-0.951057f,	 0.000000f,	 0.309015f},
	{-0.951057f,	 0.000000f,	-0.309017f},
	{-0.587784f,	 0.000000f,	-0.809021f},
	{ 0.000000f,	 0.000000f,	-1.000000f},
	{ 0.587788f,	 0.000000f,	-0.809013f},
	{ 0.951057f,	 0.000000f,	-0.309017f},
};
const u16 hemi_1v[HEMI1_FACES*3] = {
	0,		1,		2,
	1,		3,		2,
	3,		4,		2,
	4,		5,		2,
	5,		0,		2,
	1,		0,		6,
	3,		1,		7,
	4,		3,		8,
	5,		4,		9,
	0,		5,		10,
	10,		11,		0,
	11,		6,		0,
	6,		12,		1,
	12,		7,		1,
	7,		13,		3,
	13,		8,		3,
	8,		14,		4,
	14,		9,		4,
	9,		15,		5,
	15,		10,		5,
	6,		11,		16,
	12,		6,		17,
	7,		12,		18,
	13,		7,		19,
	8,		13,		20,
	14,		8,		21,
	9,		14,		22,
	15,		9,		23,
	10,		15,		24,
	11,		10,		25,
	25,		16,		11,
	16,		17,		6,
	17,		18,		12,
	18,		19,		7,
	19,		20,		13,
	20,		21,		8,
	21,		22,		14,
	22,		23,		9,
	23,		24,		15,
	24,		25,		10,
};

const Fvector hemi_2[HEMI2_VERTS] =
{
	{ 0.273268f,	 0.961937f,	-0.000000f},
	{ 0.084444f,	 0.961937f,	 0.259892f},
	{ 0.000000f,	 1.000000f,	-0.000000f},
	{ 0.525730f,	 0.850655f,	-0.000000f},
	{ 0.361805f,	 0.894424f,	 0.262865f},
	{ 0.162460f,	 0.850655f,	 0.500000f},
	{-0.221077f,	 0.961937f,	 0.160622f},
	{-0.138196f,	 0.894424f,	 0.425324f},
	{-0.425324f,	 0.850655f,	 0.309015f},
	{-0.221077f,	 0.961937f,	-0.160623f},
	{-0.447212f,	 0.894424f,	-0.000001f},
	{-0.425324f,	 0.850655f,	-0.309017f},
	{ 0.084445f,	 0.961937f,	-0.259892f},
	{-0.138196f,	 0.894424f,	-0.425327f},
	{ 0.162460f,	 0.850655f,	-0.500000f},
	{ 0.361805f,	 0.894424f,	-0.262865f},
	{ 0.447212f,	 0.723610f,	 0.525730f},
	{ 0.638195f,	 0.723610f,	 0.262865f},
	{ 0.688194f,	 0.525730f,	 0.500000f},
	{-0.361801f,	 0.723610f,	 0.587784f},
	{-0.052786f,	 0.723610f,	 0.688187f},
	{-0.262865f,	 0.525730f,	 0.809013f},
	{-0.670822f,	 0.723610f,	-0.162460f},
	{-0.670822f,	 0.723610f,	 0.162458f},
	{-0.850647f,	 0.525730f,	-0.000001f},
	{-0.052786f,	 0.723610f,	-0.688194f},
	{-0.361801f,	 0.723610f,	-0.587788f},
	{-0.262865f,	 0.525730f,	-0.809021f},
	{ 0.638195f,	 0.723610f,	-0.262865f},
	{ 0.447212f,	 0.723610f,	-0.525734f},
	{ 0.688194f,	 0.525730f,	-0.500000f},
	{ 0.738174f,	 0.674606f,	-0.000000f},
	{ 0.822617f,	 0.505722f,	-0.259892f},
	{ 0.894424f,	 0.447212f,	-0.000000f},
	{ 0.822617f,	 0.505722f,	 0.259892f},
	{ 0.228109f,	 0.674606f,	 0.702049f},
	{ 0.501377f,	 0.505722f,	 0.702049f},
	{ 0.276394f,	 0.447212f,	 0.850647f},
	{ 0.007032f,	 0.505722f,	 0.862671f},
	{-0.597195f,	 0.674606f,	 0.433887f},
	{-0.512752f,	 0.505722f,	 0.693779f},
	{-0.723602f,	 0.447212f,	 0.525730f},
	{-0.818275f,	 0.505722f,	 0.273266f},
	{-0.597195f,	 0.674606f,	-0.433887f},
	{-0.818275f,	 0.505722f,	-0.273268f},
	{-0.723602f,	 0.447212f,	-0.525734f},
	{-0.512753f,	 0.505722f,	-0.693779f},
	{ 0.228109f,	 0.674606f,	-0.702049f},
	{ 0.007032f,	 0.505722f,	-0.862671f},
	{ 0.276394f,	 0.447212f,	-0.850655f},
	{ 0.501377f,	 0.505722f,	-0.702049f},
	{ 0.861801f,	 0.276394f,	 0.425323f},
	{ 0.959251f,	 0.232454f,	 0.160622f},
	{ 0.951057f,	 0.000000f,	 0.309017f},
	{ 0.449184f,	 0.232454f,	 0.862671f},
	{ 0.670822f,	 0.276394f,	 0.688187f},
	{ 0.587788f,	 0.000000f,	 0.809013f},
	{-0.138196f,	 0.276394f,	 0.951057f},
	{ 0.143665f,	 0.232454f,	 0.961937f},
	{ 0.000000f,	 0.000000f,	 1.000000f},
	{-0.681641f,	 0.232454f,	 0.693779f},
	{-0.447212f,	 0.276394f,	 0.850647f},
	{-0.587784f,	 0.000000f,	 0.809013f},
	{-0.947212f,	 0.276394f,	 0.162458f},
	{-0.870460f,	 0.232454f,	 0.433887f},
	{-0.951057f,	 0.000000f,	 0.309015f},
	{-0.870460f,	 0.232454f,	-0.433887f},
	{-0.947212f,	 0.276394f,	-0.162460f},
	{-0.951057f,	 0.000000f,	-0.309017f},
	{-0.447212f,	 0.276394f,	-0.850655f},
	{-0.681641f,	 0.232454f,	-0.693779f},
	{-0.587784f,	 0.000000f,	-0.809021f},
	{ 0.143665f,	 0.232454f,	-0.961937f},
	{-0.138196f,	 0.276394f,	-0.951057f},
	{ 0.000000f,	 0.000000f,	-1.000000f},
	{ 0.670822f,	 0.276394f,	-0.688194f},
	{ 0.449188f,	 0.232454f,	-0.862671f},
	{ 0.587788f,	 0.000000f,	-0.809013f},
	{ 0.959251f,	 0.232454f,	-0.160623f},
	{ 0.861801f,	 0.276394f,	-0.425327f},
	{ 0.951057f,	 0.000000f,	-0.309017f},
	{ 1.000000f,	 0.000000f,	-0.000000f},
	{ 0.809021f,	 0.000000f,	 0.587784f},
	{ 0.309017f,	 0.000000f,	 0.951057f},
	{-0.309015f,	 0.000000f,	 0.951057f},
	{-0.809013f,	 0.000000f,	 0.587784f},
	{-1.000000f,	 0.000000f,	-0.000001f},
	{-0.809013f,	 0.000000f,	-0.587788f},
	{-0.309015f,	 0.000000f,	-0.951057f},
	{ 0.309017f,	 0.000000f,	-0.951057f},
	{ 0.809021f,	 0.000000f,	-0.587788f},
};
const u16 hemi_2v[HEMI2_FACES*3] = {
	0,		1,		2,
	3,		4,		0,
	4,		1,		0,
	4,		5,		1,
	1,		6,		2,
	5,		7,		1,
	7,		6,		1,
	7,		8,		6,
	6,		9,		2,
	8,		10,		6,
	10,		9,		6,
	10,		11,		9,
	9,		12,		2,
	11,		13,		9,
	13,		12,		9,
	13,		14,		12,
	12,		0,		2,
	14,		15,		12,
	15,		0,		12,
	15,		3,		0,
	16,		17,		18,
	5,		4,		16,
	4,		17,		16,
	4,		3,		17,
	19,		20,		21,
	8,		7,		19,
	7,		20,		19,
	7,		5,		20,
	22,		23,		24,
	11,		10,		22,
	10,		23,		22,
	10,		8,		23,
	25,		26,		27,
	14,		13,		25,
	13,		26,		25,
	13,		11,		26,
	28,		29,		30,
	3,		15,		28,
	15,		29,		28,
	15,		14,		29,
	28,		31,		3,
	30,		32,		28,
	32,		31,		28,
	32,		33,		31,
	31,		17,		3,
	33,		34,		31,
	34,		17,		31,
	34,		18,		17,
	16,		35,		5,
	18,		36,		16,
	36,		35,		16,
	36,		37,		35,
	35,		20,		5,
	37,		38,		35,
	38,		20,		35,
	38,		21,		20,
	19,		39,		8,
	21,		40,		19,
	40,		39,		19,
	40,		41,		39,
	39,		23,		8,
	41,		42,		39,
	42,		23,		39,
	42,		24,		23,
	22,		43,		11,
	24,		44,		22,
	44,		43,		22,
	44,		45,		43,
	43,		26,		11,
	45,		46,		43,
	46,		26,		43,
	46,		27,		26,
	25,		47,		14,
	27,		48,		25,
	48,		47,		25,
	48,		49,		47,
	47,		29,		14,
	49,		50,		47,
	50,		29,		47,
	50,		30,		29,
	51,		52,		53,
	18,		34,		51,
	34,		52,		51,
	34,		33,		52,
	54,		55,		56,
	37,		36,		54,
	36,		55,		54,
	36,		18,		55,
	57,		58,		59,
	21,		38,		57,
	38,		58,		57,
	38,		37,		58,
	60,		61,		62,
	41,		40,		60,
	40,		61,		60,
	40,		21,		61,
	63,		64,		65,
	24,		42,		63,
	42,		64,		63,
	42,		41,		64,
	66,		67,		68,
	45,		44,		66,
	44,		67,		66,
	44,		24,		67,
	69,		70,		71,
	27,		46,		69,
	46,		70,		69,
	46,		45,		70,
	72,		73,		74,
	49,		48,		72,
	48,		73,		72,
	48,		27,		73,
	75,		76,		77,
	30,		50,		75,
	50,		76,		75,
	50,		49,		76,
	78,		79,		80,
	33,		32,		78,
	32,		79,		78,
	32,		30,		79,
	78,		52,		33,
	80,		81,		78,
	81,		52,		78,
	81,		53,		52,
	51,		55,		18,
	53,		82,		51,
	82,		55,		51,
	82,		56,		55,
	54,		58,		37,
	56,		83,		54,
	83,		58,		54,
	83,		59,		58,
	57,		61,		21,
	59,		84,		57,
	84,		61,		57,
	84,		62,		61,
	60,		64,		41,
	62,		85,		60,
	85,		64,		60,
	85,		65,		64,
	63,		67,		24,
	65,		86,		63,
	86,		67,		63,
	86,		68,		67,
	66,		70,		45,
	68,		87,		66,
	87,		70,		66,
	87,		71,		70,
	69,		73,		27,
	71,		88,		69,
	88,		73,		69,
	88,		74,		73,
	72,		76,		49,
	74,		89,		72,
	89,		76,		72,
	89,		77,		76,
	75,		79,		30,
	77,		90,		75,
	90,		79,		75,
	90,		80,		79,
};

const Fvector hemi_3[HEMI3_VERTS] =
{
	{+0.0000f,	+0.5000f,	+0.0000f },
	{+0.2629f,	+0.4253f,	+0.0000f },
	{+0.0812f,	+0.4253f,	+0.2500f },
	{-0.2127f,	+0.4253f,	+0.1545f },
	{-0.2127f,	+0.4253f,	-0.1545f },
	{+0.0812f,	+0.4253f,	-0.2500f },
	{+0.4472f,	+0.2236f,	+0.0000f },
	{+0.1382f,	+0.2236f,	+0.4253f },
	{-0.3618f,	+0.2236f,	+0.2629f },
	{-0.3618f,	+0.2236f,	-0.2629f },
	{+0.1382f,	+0.2236f,	-0.4253f },
	{+0.3441f,	+0.2629f,	+0.2500f },
	{-0.1314f,	+0.2629f,	+0.4045f },
	{-0.4253f,	+0.2629f,	-0.0000f },
	{-0.1314f,	+0.2629f,	-0.4045f },
	{+0.3441f,	+0.2629f,	-0.2500f },
	{+0.4755f,	+0.0000f,	+0.1545f },
	{+0.2939f,	+0.0000f,	+0.4045f },
	{-0.0000f,	+0.0000f,	+0.5000f },
	{-0.2939f,	+0.0000f,	+0.4045f },
	{-0.4755f,	+0.0000f,	+0.1545f },
	{-0.4755f,	+0.0000f,	-0.1545f },
	{-0.2939f,	+0.0000f,	-0.4045f },
	{+0.0000f,	+0.0000f,	-0.5000f },
	{+0.2939f,	+0.0000f,	-0.4045f },
	{+0.4755f,	+0.0000f,	-0.1545f },
	{+0.0917f,	+0.4915f,	+0.0000f },
	{+0.1804f,	+0.4663f,	+0.0000f },
	{+0.0283f,	+0.4915f,	+0.0872f },
	{+0.0557f,	+0.4663f,	+0.1715f },
	{-0.0742f,	+0.4915f,	+0.0539f },
	{-0.1459f,	+0.4663f,	+0.1060f },
	{-0.0742f,	+0.4915f,	-0.0539f },
	{-0.1459f,	+0.4663f,	-0.1060f },
	{+0.0283f,	+0.4915f,	-0.0872f },
	{+0.0557f,	+0.4663f,	-0.1715f },
	{+0.2106f,	+0.4448f,	+0.0884f },
	{+0.1492f,	+0.4448f,	+0.1730f },
	{-0.0190f,	+0.4448f,	+0.2276f },
	{-0.1184f,	+0.4448f,	+0.1953f },
	{-0.2224f,	+0.4448f,	+0.0523f },
	{-0.2224f,	+0.4448f,	-0.0523f },
	{-0.1184f,	+0.4448f,	-0.1953f },
	{-0.0190f,	+0.4448f,	-0.2276f },
	{+0.1492f,	+0.4448f,	-0.1730f },
	{+0.2106f,	+0.4448f,	-0.0884f },
	{+0.3364f,	+0.3699f,	+0.0000f },
	{+0.3986f,	+0.3019f,	+0.0000f },
	{+0.1040f,	+0.3699f,	+0.3200f },
	{+0.1232f,	+0.3019f,	+0.3791f },
	{-0.2722f,	+0.3699f,	+0.1978f },
	{-0.3225f,	+0.3019f,	+0.2343f },
	{-0.2722f,	+0.3699f,	-0.1978f },
	{-0.3225f,	+0.3019f,	-0.2343f },
	{+0.1040f,	+0.3699f,	-0.3200f },
	{+0.1232f,	+0.3019f,	-0.3791f },
	{+0.3036f,	+0.3873f,	+0.0884f },
	{+0.3311f,	+0.3323f,	+0.1730f },
	{+0.0097f,	+0.3873f,	+0.3161f },
	{-0.0622f,	+0.3323f,	+0.3683f },
	{-0.2976f,	+0.3873f,	+0.1069f },
	{-0.3695f,	+0.3323f,	+0.0547f },
	{-0.1936f,	+0.3873f,	-0.2500f },
	{-0.1662f,	+0.3323f,	-0.3346f },
	{+0.1779f,	+0.3873f,	-0.2614f },
	{+0.2668f,	+0.3323f,	-0.2614f },
	{+0.3036f,	+0.3873f,	-0.0884f },
	{+0.3311f,	+0.3323f,	-0.1730f },
	{+0.1779f,	+0.3873f,	+0.2614f },
	{+0.2668f,	+0.3323f,	+0.2614f },
	{-0.1936f,	+0.3873f,	+0.2500f },
	{-0.1662f,	+0.3323f,	+0.3346f },
	{-0.2976f,	+0.3873f,	-0.1069f },
	{-0.3695f,	+0.3323f,	-0.0547f },
	{+0.0097f,	+0.3873f,	-0.3161f },
	{-0.0622f,	+0.3323f,	-0.3683f },
	{+0.4269f,	+0.2452f,	+0.0872f },
	{+0.3922f,	+0.2584f,	+0.1715f },
	{+0.0490f,	+0.2452f,	+0.4330f },
	{-0.0420f,	+0.2584f,	+0.4260f },
	{-0.3967f,	+0.2452f,	+0.1804f },
	{-0.4181f,	+0.2584f,	+0.0917f },
	{-0.2941f,	+0.2452f,	-0.3215f },
	{-0.2165f,	+0.2584f,	-0.3693f },
	{+0.2149f,	+0.2452f,	-0.3791f },
	{+0.2843f,	+0.2584f,	-0.3200f },
	{+0.3922f,	+0.2584f,	-0.1715f },
	{+0.4269f,	+0.2452f,	-0.0872f },
	{+0.2843f,	+0.2584f,	+0.3200f },
	{+0.2149f,	+0.2452f,	+0.3791f },
	{-0.2165f,	+0.2584f,	+0.3693f },
	{-0.2941f,	+0.2452f,	+0.3215f },
	{-0.4181f,	+0.2584f,	-0.0917f },
	{-0.3967f,	+0.2452f,	-0.1804f },
	{-0.0420f,	+0.2584f,	-0.4260f },
	{+0.0490f,	+0.2452f,	-0.4330f },
	{+0.4728f,	+0.1534f,	+0.0539f },
	{+0.4824f,	+0.0780f,	+0.1060f },
	{+0.4063f,	+0.1819f,	+0.2276f },
	{+0.4508f,	+0.0930f,	+0.1953f },
	{+0.3421f,	+0.1819f,	+0.3161f },
	{+0.3251f,	+0.0930f,	+0.3683f },
	{+0.1974f,	+0.1534f,	+0.4330f },
	{+0.2499f,	+0.0780f,	+0.4260f },
	{+0.0948f,	+0.1534f,	+0.4663f },
	{+0.0482f,	+0.0780f,	+0.4915f },
	{-0.0909f,	+0.1819f,	+0.4568f },
	{-0.0465f,	+0.0930f,	+0.4891f },
	{-0.1949f,	+0.1819f,	+0.4230f },
	{-0.2499f,	+0.0930f,	+0.4230f },
	{-0.3508f,	+0.1534f,	+0.3215f },
	{-0.3279f,	+0.0780f,	+0.3693f },
	{-0.4142f,	+0.1534f,	+0.2343f },
	{-0.4526f,	+0.0780f,	+0.1978f },
	{-0.4625f,	+0.1819f,	+0.0547f },
	{-0.4795f,	+0.0930f,	+0.1069f },
	{-0.4625f,	+0.1819f,	-0.0547f },
	{-0.4795f,	+0.0930f,	-0.1069f },
	{-0.4142f,	+0.1534f,	-0.2343f },
	{-0.4526f,	+0.0780f,	-0.1978f },
	{-0.3508f,	+0.1534f,	-0.3215f },
	{-0.3279f,	+0.0780f,	-0.3693f },
	{-0.1949f,	+0.1819f,	-0.4230f },
	{-0.2499f,	+0.0930f,	-0.4230f },
	{-0.0909f,	+0.1819f,	-0.4568f },
	{-0.0465f,	+0.0930f,	-0.4891f },
	{+0.0948f,	+0.1534f,	-0.4663f },
	{+0.0482f,	+0.0780f,	-0.4915f },
	{+0.1974f,	+0.1534f,	-0.4330f },
	{+0.2499f,	+0.0780f,	-0.4260f },
	{+0.3421f,	+0.1819f,	-0.3161f },
	{+0.3251f,	+0.0930f,	-0.3683f },
	{+0.4063f,	+0.1819f,	-0.2276f },
	{+0.4508f,	+0.0930f,	-0.1953f },
	{+0.4728f,	+0.1534f,	-0.0539f },
	{+0.4824f,	+0.0780f,	-0.1060f },
	{+0.4330f,	+0.0000f,	+0.2500f },
	{+0.3716f,	+0.0000f,	+0.3346f },
	{+0.2034f,	+0.0000f,	+0.4568f },
	{+0.1040f,	+0.0000f,	+0.4891f },
	{-0.1040f,	+0.0000f,	+0.4891f },
	{-0.2034f,	+0.0000f,	+0.4568f },
	{-0.3716f,	+0.0000f,	+0.3346f },
	{-0.4330f,	+0.0000f,	+0.2500f },
	{-0.4973f,	+0.0000f,	+0.0523f },
	{-0.4973f,	+0.0000f,	-0.0523f },
	{-0.4330f,	+0.0000f,	-0.2500f },
	{-0.3716f,	+0.0000f,	-0.3346f },
	{-0.2034f,	+0.0000f,	-0.4568f },
	{-0.1040f,	+0.0000f,	-0.4891f },
	{+0.1040f,	+0.0000f,	-0.4891f },
	{+0.2034f,	+0.0000f,	-0.4568f },
	{+0.3716f,	+0.0000f,	-0.3346f },
	{+0.4330f,	+0.0000f,	-0.2500f },
	{+0.4973f,	+0.0000f,	-0.0523f },
	{+0.4973f,	+0.0000f,	+0.0523f },
	{+0.1208f,	+0.4772f,	+0.0878f },
	{-0.0461f,	+0.4772f,	+0.1420f },
	{-0.1493f,	+0.4772f,	-0.0000f },
	{-0.0461f,	+0.4772f,	-0.1420f },
	{+0.1208f,	+0.4772f,	-0.0878f },
	{+0.2465f,	+0.3965f,	+0.1791f },
	{-0.0941f,	+0.3965f,	+0.2897f },
	{-0.3047f,	+0.3965f,	-0.0000f },
	{-0.0941f,	+0.3965f,	-0.2897f },
	{+0.2465f,	+0.3965f,	-0.1791f },
	{+0.3715f,	+0.3229f,	-0.0881f },
	{+0.3715f,	+0.3229f,	+0.0881f },
	{+0.1986f,	+0.3229f,	+0.3261f },
	{+0.0310f,	+0.3229f,	+0.3805f },
	{-0.2488f,	+0.3229f,	+0.2896f },
	{-0.3523f,	+0.3229f,	+0.1471f },
	{-0.3523f,	+0.3229f,	-0.1471f },
	{-0.2488f,	+0.3229f,	-0.2896f },
	{+0.0310f,	+0.3229f,	-0.3805f },
	{+0.1986f,	+0.3229f,	-0.3261f },
	{+0.4476f,	+0.1707f,	+0.1433f },
	{+0.2746f,	+0.1707f,	+0.3814f },
	{+0.0020f,	+0.1707f,	+0.4700f },
	{-0.2778f,	+0.1707f,	+0.3790f },
	{-0.4463f,	+0.1707f,	+0.1471f },
	{-0.4463f,	+0.1707f,	-0.1471f },
	{-0.2778f,	+0.1707f,	-0.3790f },
	{+0.0020f,	+0.1707f,	-0.4700f },
	{+0.2746f,	+0.1707f,	-0.3814f },
	{+0.4476f,	+0.1707f,	-0.1433f },
	{+0.4936f,	+0.0799f,	+0.0000f },
	{+0.3971f,	+0.0952f,	+0.2885f },
	{+0.1525f,	+0.0799f,	+0.4694f },
	{-0.1517f,	+0.0952f,	+0.4668f },
	{-0.3993f,	+0.0799f,	+0.2901f },
	{-0.4909f,	+0.0952f,	-0.0000f },
	{-0.3993f,	+0.0799f,	-0.2901f },
	{-0.1517f,	+0.0952f,	-0.4668f },
	{+0.1525f,	+0.0799f,	-0.4694f },
	{+0.3971f,	+0.0952f,	-0.2885f },
};
#pragma warning(default:4305)

void ECORE_API xrHemisphereBuild	(int quality, float energy, xrHemisphereIterator* iterator, LPVOID param)
{
	const Fvector* hemi=0;
	int h_count		= xrHemisphereVertices(quality,hemi); VERIFY(h_count>0);
    // Calculate energy
    float total		= (float)h_count;
    float E			= 1.f/total;
		
    // Iterate
    for (int i=0; i<h_count; i++){
        float x		=	-float	(hemi[i][0]);
        float y		=	-float	(hemi[i][1]);
        float z		=	-float	(hemi[i][2]);
        float mag	=	_sqrt	(x*x + y*y + z*z);
        x /= mag;	y /= mag;	z /= mag;
        iterator	(x,y,z,E*energy,param);
    }
}

int ECORE_API xrHemisphereVertices	(int quality, const Fvector*& verts)
{
	// SELECT table
	int				h_count	= 0;
	switch (quality)
	{
	case 1:	// LOW quality
		h_count		= HEMI1_VERTS;
		verts		= hemi_1;
		break;
	case 2:	// HIGH quality
		h_count		= HEMI2_VERTS;
		verts		= hemi_2;
		break;
	case 3:	// SUPER HIGH quality
		h_count		= HEMI3_VERTS;
		verts		= hemi_3;
		break;
	default:// NO 	
		NODEFAULT;
	}
	return h_count;
}

int	ECORE_API xrHemisphereIndices	(int quality, const u16*& indices)
{
	// SELECT table
	int				h_count	= 0;
	switch (quality)
	{
	case 1:	// LOW quality
		h_count		= HEMI1_FACES*3;
		indices		= hemi_1v;
		break;
	case 2:	// HIGH quality
		h_count		= HEMI2_FACES*3;
		indices		= hemi_2v;
		break;
//	case 3:	// SUPER HIGH quality
//		h_count		= HEMI3_FACES*3;
//		indices		= hemi_3v;
//		break;
	default:// NO 	
		NODEFAULT;
	}
	return h_count;
}
