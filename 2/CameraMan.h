#pragma once
#include <string>
#include <fstream>
class CameraMan
{
public: // из-за функции printInfo не получается сделать их приватными 

	std::string name;
	std::string surname;
	bool sex; // 1-male, 0-female
	std::string bornYear;
	std::string startYear;
	double rating;
	int jury; // кол-во голосующих
	
	
	


public:
	CameraMan();
	CameraMan(std::string name, std::string surname, bool sex, std::string bornYear, std::string startYear, double rating );
	void setName(std::string name);
	void setSurname(std::string surname);
	void setSex(bool sex);
	void setBornYear(std::string bornYear);
	void setStartYear(std::string startYear);
	void setRating(double rating);
	void upRating(int jury);
	void serialize();
	void deserialize();
	void serialize(const std::string& file) const;
	void deserialize(const std::string& file);
	~CameraMan();
};

