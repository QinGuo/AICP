#pragma once

#include"CloudPoints.h"
struct Bone
{
 
 int idx; // Bone index
 char name[256];

 struct Bone *sibling;	// Pointer to the sibling (branch bone) in the hierarchy tree 
 struct Bone *child; // Pointer to the child (outboard bone) in the hierarchy tree 


 double dir[3]; // Unit vector describes the direction from local origin to 
 // the origin of the child bone 
 // Notice: stored in local coordinate system of the bone

 double length; // Bone length  

 Point	BoneCenter;
 double radius;
 bool isActive;
 Bone(){length=0;radius=0;isActive=true;}
};
struct Bone
{



	
	double axis_x, axis_y, axis_z;// orientation of each bone's local coordinate 
	//system as specified in ASF file (axis field)

	double aspx, aspy; // aspect ratio of bone shape

	int dof; // number of bone's degrees of freedom 
	int dofrx, dofry, dofrz; // rotational degree of freedom mask in x, y, z axis 
	int doftx, dofty, doftz; // translational degree of freedom mask in x, y, z axis
	int doftl;
	// dofrx=1 if this bone has x rotational degree of freedom, otherwise dofrx=0.

	// bone names
	char name[256];
	// rotation matrix from the local coordinate of this bone to the local coordinate system of it's parent
	double rot_parent_current[4][4];

	//Rotation angles for this bone at a particular time frame (as read from AMC file) in local coordinate system, 
	//they are set in the setPosture function before display function is called
	double rx, ry, rz;
	double tx, ty, tz;
	double tl;
	int dofo[8];



};



class Skeleton
{
public:
	Skeleton(){};
	 
	void makeHandSkeleton();
	void printSkeletonPara();
	private:
    void readSkeletonPara();
	public:
	 Bone Bones[20];
};
