#include "CameraMan.h"
#include <fstream>
#include <iostream>
#include <iomanip>


CameraMan::CameraMan() {}
CameraMan::CameraMan(std::string name, std::string surname, bool sex, std::string bornYear, std::string startYear, double rating ) {
	this->name = name;
	this->surname = surname;
	this->sex = sex;
	this->bornYear = bornYear;
	this->startYear = startYear;
	this->rating = rating;
}

void CameraMan::setName(std::string name) {
	this->name = name;
}

void CameraMan::setSurname(std::string surname) {
	this->surname = surname;
}
void CameraMan::setSex(bool sex) {
	this->sex = sex;
}

void CameraMan::setBornYear(std::string bornYear) {
	this->bornYear = bornYear;
}

void CameraMan::setStartYear(std::string startYear) {
	this->startYear = startYear;
}

void CameraMan::setRating(double rating) {
	this->rating = rating;
	
}

void CameraMan::upRating(int jury){
	this->jury = jury;
	
	if (jury >= 10) {
		for (int i = 0; i < jury; i++) {
			this->rating += (double)(rand()) / RAND_MAX * (1.0 - 0.0) + 0.0;
		}
	}
	else this->rating = rating;
}



void CameraMan::serialize() {
	std::ofstream fout;
	fout.open("CameraMan.txt", std::ofstream::app);

	if (fout.is_open()) {
		printf("\nFile is open");
		fout.write((char*)this, sizeof(CameraMan));
	}
	else {
		printf("\nError opening file");
	}

	fout.close();
}

void CameraMan::deserialize() {
	std::ifstream fin;
	fin.open("CameraMan.txt");

	if (fin.is_open()) {
		printf("\nFile is open");
		
	}
	else {
		printf("\nError opening file");
		fin.read((char*)this, sizeof(CameraMan));
		
	}

	fin.close();
}

void CameraMan::serialize(const std::string& file) const {
	std::ofstream fout;
	fout.open(file, std::ofstream::app);

	if (fout.is_open()) {
		printf("\nFile is open");
		fout.write((char*)this, sizeof(CameraMan));
	}
	else {
		printf("\nError opening file");
	}

	fout.close();
}

void CameraMan::deserialize(const std::string& file) {
	std::ifstream fin;
	fin.open(file);

	if (fin.is_open()) {
		printf("\nFile is open");
		
	}
	else {
		printf("\nError opening file");
		fin.read((char*)this, sizeof(CameraMan));
	}

	fin.close();
}

CameraMan::~CameraMan() {}