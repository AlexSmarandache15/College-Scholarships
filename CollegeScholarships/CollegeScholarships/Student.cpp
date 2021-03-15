//
// Student.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Student.h"

namespace sma
{
	Student::Student()
	{
		this->gdpr = this->specialization = this->cycle = "";
		this->age = this->performances_points = this->year = 0;
		this->tax = this->excellence_dossier = this->social_dossier = this->orphan = this->sick = this->integralist = 0;
		this->average_grades = this->income = 0.0;
		this->indicatives.resize(NO_ATRIBUTES);
	}

	bool Student::isEligibleForExcellence() const
	{
		return (average_grades == 10) && excellence_dossier && (performances_points >= 30) && !this->tax && this->integralist;
	}

	bool Student::isEligibleForSocial(const unsigned int& max_income) const
	{
		return this->social_dossier && (this->age <= 35) && (this->income <= max_income)
			&& (!this->tax || (orphan));
	}

	bool Student::isEligibleForScholarship(const double& minimum_grade) const
	{
		return !this->isEligibleForExcellence() && this->average_grades >= minimum_grade && !this->tax && this->integralist;
	}

	void Student::printForExcellence(std::ostream& out) const
	{
		out << this->gdpr << "\t" << this->performances_points;
	}

	void Student::printForSocial(std::ostream& out) const
	{
		out << this->gdpr << "\t" << "AverageIncome: " << this->income;
		if (this->sick || this->orphan) {
			out << "\tOther mention: ";
			if (this->orphan) {
				out << "\t" << "orphan";
			}
			if (this->sick) {
				out << "\t" << "sick";
			}
		}
	}

	void Student::printForScholarship(std::ostream& out) const
	{
		out << this->gdpr << "\t" << this->average_grades;
	}

	void Student::save(std::ostream& out)
	{
		auto it = std::begin(indicatives);

		out << *it++ << " " << gdpr << '\n';
		out << *it++ << " " << cycle << '\n';
		out << *it++ << " " << specialization << '\n';
		out << *it++ << " " << year << '\n';
		out << *it++ << " " << tax << '\n';
		out << *it++ << " " << integralist << '\n';
		out << *it++ << " " << average_grades << '\n';
		out << *it++ << " " << excellence_dossier << '\n';
		out << *it++ << " " << performances_points << '\n';
		out << *it++ << " " << social_dossier << '\n';
		out << *it++ << " " << age << '\n';
		out << *it++ << " " << income << '\n';
		out << *it++ << " " << orphan << '\n';
		out << *it << " " << sick << '\n';
		out << std::endl;
	}

	void Student::load(std::istream& in)
	{
		in >> *this;
	}

	std::istream& operator>>(std::istream& in, Student& _student)
	{
		auto it = std::begin(_student.indicatives);

		in >> *it, it++;
		in >> _student.gdpr;
		in >> *it, it++;
		in >> _student.cycle;
		in >> *it, it++;
		in >> _student.specialization;
		in >> *it, it++;
		in >> _student.year;
		in >> *it, it++;
		in >> _student.tax;
		in >> *it, it++;
		in >> _student.integralist;
		in >> *it, it++;
		in >> _student.average_grades;
		in >> *it, it++;
		in >> _student.excellence_dossier;
		in >> *it, it++;
		in >> _student.performances_points;
		in >> *it, it++;
		in >> _student.social_dossier;
		in >> *it, it++;
		in >> _student.age;
		in >> *it, it++;
		in >> _student.income;
		in >> *it, it++;
		in >> _student.orphan;
		in >> *it;
		in >> _student.sick;

		return in;
	}
};

