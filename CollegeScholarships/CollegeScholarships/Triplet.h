//
// Triplet.h
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once

namespace sma
{
	template<typename T1, typename T2, typename T3>
	class Triplet
	{
	public:

		Triplet() {}
		Triplet(const T1& first, const T2& second, const T3& third): 
			first(first), second(second), third(third) {}

		T1 first;
		T2 second;
		T3 third;

		const Triplet<T1, T2, T3>& operator=(const Triplet& arg) {
			if (this != &arg) {
				first = arg.first, second = arg.second, third = arg.third;
			}
			return *this;
		}

		bool operator==(const Triplet<T1, T2, T3>& arg) const {
			return first == arg.first && second == arg.second && third == arg.third;
		}

		bool operator!=(const Triplet<T1, T2, T3>& arg) const {
			return !(*this == arg);
		}

		template<typename T1, typename T2, typename T3>
		friend bool operator>(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend bool operator<(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend bool operator>=(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend bool operator<=(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend bool operator+(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend bool operator-(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y);

		template<typename T1, typename T2, typename T3>
		friend const Triplet<T1, T2, T3>& make_triplet(const T1& first, const T2& second, const T3& third);

	};

	template<typename T1, typename T2, typename T3>
	bool operator>(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return ((x.first > y.first) || ((x.first == y.first) && (x.second > y.second)) ||
			((x.first == y.first) && (x.second == y.second) && (x.third > y.third)));
	}

	template<typename T1, typename T2, typename T3>
	bool operator<(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return ((x.first < y.first) || ((x.first == y.first) && (x.second < y.second)) ||
			((x.first == y.first) && (x.second == y.second) && (x.third < y.third)));
	}

	template<typename T1, typename T2, typename T3>
	bool operator>=(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return !(x < y);
	}

	template<typename T1, typename T2, typename T3>
	bool operator<=(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return !(x > y);
	}

	template<typename T1, typename T2, typename T3>
	bool operator+(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return Triplet<T1, T2, T3>(x.first + y.first, x.second + y.second, x.third + y.third);
	}

	template<typename T1, typename T2, typename T3>
	bool operator-(const Triplet<T1, T2, T3>& x, const Triplet<T1, T2, T3>& y)
	{
		return Triplet<T1, T2, T3>(x.first - y.first, x.second - y.second, x.third - y.third);
	}

	template<typename T1, typename T2, typename T3>
	const Triplet<T1, T2, T3>& make_triplet(T1 first, T2 second, T3 third)
	{
		static Triplet<T1, T2, T3> var;
		var.first = first, var.second = second, var.third = third;
		return var;
	}
}

