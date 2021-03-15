//
// MinimalStudent.h
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace sma
{
	class MinimalStudent
	{
	public:
		static std::vector<std::string> indicatives;
		std::string gdpr;
		std::string specialization;
		std::string cycle;
		unsigned int age;
		unsigned int year;
		double averrage_grades;
		bool integralist;
		bool social_dossier;
		bool tax;
		double income;
		bool performance_dossier;
		unsigned int performances_points;
		bool orphan;
		bool sick;
		MinimalStudent& operator=(const MinimalStudent&);
		friend std::ostream& operator<<(std::ostream&, const MinimalStudent&);
	};
}


