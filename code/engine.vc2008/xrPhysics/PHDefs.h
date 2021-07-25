#ifndef PHDEFS_H
#define PHDEFS_H
class CPHElement;
class CPHJoint;
class CPhysicsShell;

//class CPHFracture;
class CShellSplitInfo;

typedef std::pair<CPhysicsShell*,u16>	shell_root;

typedef xr_vector< CPHElement* > ELEMENT_STORAGE; typedef ELEMENT_STORAGE::iterator ELEMENT_I;
typedef		xr_vector<CPHElement*>::const_iterator	ELEMENT_CI;
typedef xr_vector< CPHJoint* > JOINT_STORAGE; typedef JOINT_STORAGE::iterator JOINT_I;
typedef xr_vector< shell_root > PHSHELL_PAIR_VECTOR; typedef PHSHELL_PAIR_VECTOR::iterator SHELL_PAIR_I;
typedef xr_vector<shell_root>::reverse_iterator SHELL_PAIR_RI;

typedef		xr_vector<CPHElement*>::reverse_iterator	ELEMENT_RI;

#endif