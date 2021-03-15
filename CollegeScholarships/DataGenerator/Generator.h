//
// Generator.h
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include <stdlib.h>   
#include <time.h>
#include <memory>
#include <unordered_set>
#include <map>
#include <random>
#include <algorithm>
#include "MinimalStudent.h"

#define MAX_SALARY 1350

namespace sma
{

    class Generator
    {
    private:
        Generator() {}

        static std::shared_ptr<Generator> instance;

        static void generateStudent(MinimalStudent&);

        static double round(double var)
        {
            double value = (int)(var * 100 + .5);
            return (double)value / 100;
        }

    public:
       
        ~Generator() {}

        static std::shared_ptr<Generator>& getGenerator();

        static double generateDouble(double min, double max)
        {
            double num = (double)rand() / RAND_MAX;
            return round(min + num * (max - min));
        }

        static int generateInt(int min, int max)
        {
            return (rand() % (max - min) + min);
        }

        static std::string generateString() 
        {
            std::string str("01234567890QWERTYUIOPLKJAHSGDFZMXNCBV");
            std::random_device random;
            std::mt19937 generator(random());
            std::shuffle(std::begin(str), std::end(str), generator);
            return str.substr(0, 10);
        }

        static void generateStudents(std::vector<MinimalStudent>&, 
          std::map<std::string, std::vector<std::pair<std::string, std::vector<unsigned int>>>>&);
    };
}
