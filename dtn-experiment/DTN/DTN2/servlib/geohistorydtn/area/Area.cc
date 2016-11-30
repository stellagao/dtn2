//#include "Area.h"


#ifndef AREAMANAGER_H_
#define AREAMANAGER_H_
#include "servlib/geohistorydtn/area/AreaManager.h"
#endif

BOOST_CLASS_EXPORT_GUID(dtn::HourFrequencyVector, "HourFrequencyVector")
BOOST_CLASS_EXPORT_GUID(dtn::MinuteFrequencyVector, "MinuteFrequencyVector")
BOOST_CLASS_EXPORT_GUID(dtn::WeekFrequencyVector, "WeekFrequencyVector")
BOOST_CLASS_EXPORT_GUID(dtn::MonthFrequencyVector, "MonthFrequencyVector")
BOOST_CLASS_EXPORT_GUID(dtn::MonAftEveFrequencyVector, "MonAftEveFrequencyVector")

namespace dtn{

void Area::changeFVector(AreaInfo info)
{
	for(list<FrequencyVector *>::iterator it=vectorlist.begin();
			it!=vectorlist.end();++it)
	{
		(*it)->changeVector(info);
	}

	//递归向上调用区域改变频率向量的函数
	if(!father.empty())
	{
		Area *fatherArea=AreaManager::Getinstance()->lookforArea(father);
		fatherArea->changeFVector(info);
	}
}


Area *Area::getFatherArea()
{
	if(!father.empty())
	{
		Area *fatherArea=AreaManager::Getinstance()->lookforArea(father);
		return fatherArea;
	}
	else
		return NULL;
}
}