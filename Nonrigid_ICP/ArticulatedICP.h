#pragma once
#include"Micros.h"
#include"Skeleton.h"
#include"CloudPoints.h"

class ArticulatedICP
{
public:

	ArticulatedICP(Point* sensorData,Skeleton SkeletonIn){setSkeleton(SkeletonIn);setSensorData(sensorData);}
	//~ArticulatedICP();
	void ICP_Loop(int numberOfIteration);
	void setSkeleton(Skeleton skeletonIn){mSkeleton=skeletonIn;}
	void setSensorData(Point* sensorData){mSensorData=sensorData;}
	void ICP_SVD();

private:
	void findTheCorresponding();
	void findTheNearest(Point& onePoint,Point& nearestPointInSpere);//in(onePoint) & out(nearestPointInSpere)
	void chooseOneBone();
	void markTheActiveBones(int dividedBone);
	Skeleton mSkeleton;
	Point* mSensorData; 
public://The following functions are for testing
	void test_printTheActiveBones();

};