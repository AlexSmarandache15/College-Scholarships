//
// ListOfPotentialScholarshipHolders.h
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Scholarship.h"
#include "ListOfPotentialBursaryHolders.h"
#include <list>
#include <unordered_map>
#include <algorithm>

namespace sma
{
	struct hash_triplet
	{
		template <typename T1, typename T2, typename T3>
		size_t operator()(const sma::Triplet<T1, T2, T3>& t) const
		{
			return (std::hash<T1>{}(t.first)) ^ (std::hash<T2>{}(t.second)) ^ (std::hash<T3>{}(t.third));
		}
	};

	class ListOfPotentialScholarshipHolders : ListOfPotentialBursaryHolders
	{
	public:
		ListOfPotentialScholarshipHolders(const unsigned int& amount, const unsigned int& total_sum, const std::string& type,
			double min_average = 8.0) : ListOfPotentialBursaryHolders(amount, total_sum, type), min_average(min_average) {
		}
		void add(const Student&) override;
		virtual void displayList(std::ostream&) override;
		void calculateDistribution(std::unordered_map < sma::Triplet<std::string, std::string, unsigned int>, unsigned int, hash_triplet>&);
	private:
		std::list<double> money_for_spec;
		double min_average;
	};
}