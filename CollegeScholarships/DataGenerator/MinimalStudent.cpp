//
// MinimalStudent.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "MinimalStudent.h"

std::vector<std::string> sma::MinimalStudent::indicatives = { "GDPR: ", "Cycle: ", "Specialization: ", "Year: ", "Tax: ", "Integralist: ", "Average: ",
		"ExcellenceDosier: ", "PerformancePoints: ", "SocialDossier: ", "Age: ", "Income: ", "Orphan: ", "Sick: " };

namespace sma
{
	std::ostream& operator<<(std::ostream& out, const MinimalStudent& student)
	{
		out << MinimalStudent::indicatives[0] << student.gdpr << '\n';
		out << MinimalStudent::indicatives[1] << student.cycle << '\n';
		out << MinimalStudent::indicatives[2] << student.specialization << '\n';
		out << MinimalStudent::indicatives[3] << student.year << '\n';
		out << MinimalStudent::indicatives[4] << student.tax << '\n';
		out << MinimalStudent::indicatives[5] << student.integralist << '\n';
		out << MinimalStudent::indicatives[6] << student.averrage_grades << '\n';
		out << MinimalStudent::indicatives[7] << student.performance_dossier << '\n';
		out << MinimalStudent::indicatives[8] << student.performances_points << '\n';
		out << MinimalStudent::indicatives[9] << student.social_dossier << '\n';
		out << MinimalStudent::indicatives[10] << student.age << '\n';
		out << MinimalStudent::indicatives[11] << student.income << '\n';
		out << MinimalStudent::indicatives[12] << student.orphan << '\n';
		out << MinimalStudent::indicatives[13] << student.sick;
		return out;
	}
}


sma::MinimalStudent& sma::MinimalStudent::operator=(const MinimalStudent& student)
{
	if (this != &student) {
		this->averrage_grades = student.averrage_grades;
		this->cycle = student.cycle;
		this->gdpr = student.gdpr;
		this->income = student.income;
		this->orphan = student.orphan;
		this->performances_points = student.performances_points;
		this->performance_dossier = student.performance_dossier;
		this->specialization = student.specialization;
		this->orphan = student.orphan;
		this->sick = student.sick;
		this->age = student.age;
		this->tax = student.tax;
		this->year = student.year;
	}
	return *this;
}
