//
// Student.h
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace sma
{
#define NO_ATRIBUTES 14

	class Student
	{
	public:
		Student();

		const std::string& getGDPR()               const { return this->gdpr; }
		const std::string& getSpecialization()     const { return this->specialization; }
		const std::string& getCycle()              const { return this->cycle; }
		const double& getIncome()                  const { return this->income; }
		const double& getAverage()                 const { return this->average_grades; }
		const unsigned int& getYear()              const { return this->year; }
		const unsigned int& getAge()	           const { return this->age; }
		const bool& isIntegralist()		   const { return this->integralist; }
		const bool& hasSocialDossier()             const { return this->social_dossier; }
		const bool& isOrphan()                     const { return this->orphan; }
		const bool& isSick()                       const { return this->sick; }
		const bool& hasPerformanceDossier()	   const { return this->excellence_dossier; }
		const unsigned int& getPerformancePoints() const { return this->performances_points; }

		bool isEligibleForExcellence() const;
		bool isEligibleForSocial(const unsigned int&) const;
		bool isEligibleForScholarship(const double&) const;

		void printForExcellence(std::ostream&) const;
		void printForSocial(std::ostream&) const;
		void printForScholarship(std::ostream&) const;

		void save(std::ostream&);
		void load(std::istream&);
		friend std::istream& operator>>(std::istream&, Student&);

	private:
		std::vector<std::string> indicatives;
		std::string gdpr;
		std::string specialization;
		std::string cycle;
		unsigned int age;
		unsigned int year;
		double average_grades;
		bool integralist;
		bool social_dossier;
		bool tax;
		double income;
		bool excellence_dossier;
		unsigned int performances_points;
		bool orphan;
		bool sick;
	};
};


