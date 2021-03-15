//
// Scholarship.h
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Bursary.h"

namespace sma
{
	class Scholarship : public Bursary 
	{
	public:
		Scholarship(double min_average = 8.00, const unsigned int& amount = 0, const unsigned int total_sum = 0,
			const std::string& type = "") : Bursary(amount, total_sum, type) {
			this->min_average = min_average;
		}
		virtual bool addStudent(const Student&) override;
		virtual void selectFinalList() override;
		virtual void display(std::ostream&, unsigned int&) const override;
	private:
		double min_average;
	};
}


