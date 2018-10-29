#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Date.h"

template <typename T>
class GlobalDataset
{
public:
	GlobalDataset();
	~GlobalDataset();


	GlobalDataset(std::string filePath, int datasetType, std::string name, T fillValue);
	void flipDatasetLat();
	void flipDatasetLon();
	void * getData();
	int getSizeOf();


private:

	std::string name;
	T maxValue, minValue, midValue;
	int width;
	int height;
	T fillValue;
	int filterType;
	int datasetType;

	T ** dataset;
	
	Date datasetDate;

};

template<typename T>
inline GlobalDataset<T>::GlobalDataset()
{
}

template<typename T>
inline GlobalDataset<T>::~GlobalDataset()
{
}


template<typename T>
inline GlobalDataset<T>::GlobalDataset(std::string filePath, int datasetType, std::string name, T fillValue)
{
}

template<typename T>
void GlobalDataset<T>::flipDatasetLat()
{
	for (int k = 0; k < height / 2; k++) {
		for (int l = 0; l < width; l++) {
			T temp = this->dataset[k][l];

			this->dataset[k][l] = this->dataset[height - k][l];

			this->dataset[height - k][l] = temp;

		}
	}
}

template<typename T>
void GlobalDataset<T>::flipDatasetLon()
{
	for (int k = 0; k < height; k++) {
		for (int l = 0; l < width / 2; l++) {
			T temp = this->dataset[k][l];

			this->dataset[k][l] = this->dataset[k][width - l];

			this->dataset[k][width - l] = temp;

		}
	}
}

template<typename T>
inline void * GlobalDataset<T>::getData()
{
	return this->dataset;
}

template<typename T>
inline int GlobalDataset<T>::getSizeOf()
{
	return sizeof(T);
}
