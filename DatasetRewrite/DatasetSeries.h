#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "GlobalDataset.h"



template <typename T>
class DatasetSeries
{
public:
	DatasetSeries();
	~DatasetSeries();
private:
	std::vector<GlobalDataset<T>> datasets;
};

template<typename T>
inline DatasetSeries<T>::DatasetSeries()
{
}

template<typename T>
inline DatasetSeries<T>::~DatasetSeries()
{
}
