//
// SocialScholarship.h
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Bursary.h"

namespace sma
{
	class SocialScholarship : public Bursary
	{
	public:
		SocialScholarship(const unsigned int& max_income = 1000, const unsigned int& amount = 0, const unsigned int total_sum = 0,
			const std::string& type = "") : Bursary(amount, total_sum, type) {
			this->max_income = max_income;
		}
		virtual bool addStudent(const Student&) override;
		virtual void selectFinalList() override;
		virtual void display(std::ostream&, unsigned int&) const override;
	private:
		unsigned int max_income;
	};
}


