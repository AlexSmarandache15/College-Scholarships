//
// ExcellenceScholarship.h
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Bursary.h"

namespace sma
{
	class ExcellenceScholarship : public Bursary
	{
	public:
		ExcellenceScholarship(const unsigned int& quantum = 0, const unsigned int total_sum = 0,
			const std::string& type = "") : Bursary(quantum, total_sum, type) { }
		virtual bool addStudent(const Student&) override;
		virtual void selectFinalList() override;
		virtual void display(std::ostream&, unsigned int&) const override;
	};
}


