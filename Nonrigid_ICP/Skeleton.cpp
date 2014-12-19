#include"Skeleton.h"
#include<iostream>
#include<fstream>
void Skeleton::makeHandSkeleton()
{
	int i;
	Bones[0].childNumber[0]=5;
	for(i=1;i<=5;i++)
	Bones[0].childNumber[i]=(i-1)*4+1;
	for(i=1;i<=20;i++)
	{
		Bones[i].number=i;
		if(i%4==0)Bones[i].childNumber[0]=-1;
		else {Bones[i].childNumber[0]=1;Bones[i].childNumber[1]=i+1;}

	}
	readSkeletonPara();
	return;
}
void Skeleton::readSkeletonPara()
{
	int number;
	double length;
	std::ifstream readfile;
	readfile.open("HandSkeleton.txt",std::ios::in);
	while(readfile>>number)
	{
	  readfile>>length;
	  Bones[number].length=length;
	  Bones[number].radius=length/2.0;
	}


}

void Skeleton::printSkeletonPara()
{
  int i;
  for(i=1;i<=20;i++)
  {
	  std::cout<<Bones[i].length<<std::endl;
  }
}