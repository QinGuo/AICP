#pragma once

#include"stdlib.h"
#include"time.h"
#include <Eigen/Dense>
#include <Eigen/SVD>
#include<iostream>


void ArticulatedICP::ICP_Loop(int numberOfIteration)
{
  int i;

  for(i=0;i<numberOfIteration;i++)
  {
	  chooseOneBone();
	  test_printTheActiveBones();
	  ICP_SVD();
  }
}
void ArticulatedICP::ICP_SVD()
{
	Eigen::Matrix3f matrixForSVD(Eigen::Matrix3f::Constant(0));
	for(int i=0;i<WIDTH*HEIGHT;i++)
		if(mSensorData[i].isActive)
	{
		Point nearestPointInSpere;
		Point onePoint=mSensorData[i];
		findTheNearest(onePoint,nearestPointInSpere);
		matrixForSVD+=onePoint.v*nearestPointInSpere.v.transpose();
		
		
	}
	Eigen::JacobiSVD<Eigen::Matrix3f> svd(matrixForSVD,Eigen::ComputeThinU|Eigen::ComputeThinV);
	Eigen::Matrix3f rotation=svd.matrixU()*svd.matrixV().transpose();

	for(int i=1;i<=BoneNUMBER;i++)
		if(mSkeleton.Bones[i].isActive==true)
			mSkeleton.Bones[i].BoneCenter.v=rotation*mSkeleton.Bones[i].BoneCenter.v;
}
void ArticulatedICP::findTheCorresponding()
{

}
void ArticulatedICP::findTheNearest(Point& onePoint,Point& nearestPointInSpere)
{
	double min=32767;
	int index=-1;
	for(int i=1;i<=BoneNUMBER;i++)
		if(mSkeleton.Bones[i].isActive==true)
	{
		Point BoneCenter=mSkeleton.Bones[i].BoneCenter;
		double dist=distanceOfPoints(onePoint,BoneCenter);
		if(dist<min)
		{
			
			index=i;
			min=dist;
		}
	}


		nearestPointInSpere.v=mSkeleton.Bones[index].BoneCenter.v+
			mSkeleton.Bones[index].radius*(onePoint.v-mSkeleton.Bones[index].BoneCenter.v)/min;

}
void ArticulatedICP::chooseOneBone()
{
	
	int choosedBone=rand()%(BoneNUMBER+1);
	for(int i=0;i<=BoneNUMBER;i++)mSkeleton.Bones[i].isActive=false;
	markTheActiveBones(choosedBone);
}
void ArticulatedICP::markTheActiveBones(int markingBone)
{
  mSkeleton.Bones[markingBone].isActive=true;
  if(mSkeleton.Bones[markingBone].childNumber[0]==-1)return;
  else
  { 
	for(int i=1;i<=mSkeleton.Bones[markingBone].childNumber[0];i++)  
		markTheActiveBones(mSkeleton.Bones[markingBone].childNumber[i]);
  }
}
void ArticulatedICP::test_printTheActiveBones()
{
	for(int i=0;i<=BoneNUMBER;i++)
		if(mSkeleton.Bones[i].isActive==true)
			std::cout<<i<<" ";
		std::cout<<std::endl;
			
}

