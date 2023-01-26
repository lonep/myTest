#include <iostream>
#include <random>
#include <typeinfo>
#include <memory>
#include <algorithm>
#include <atomic>
#include <thread>
#include <numeric>
#include <iterator>

#include <curves.h>
#include <tbb/parallel_invoke.h>


using namespace std;
using u32 = uint_least32_t;

void printPoint(const Curves::Point3D &point)
{
    cout << point.x <<"\t" << point.y << "\t" << point.z << "\n";
}

void sum(vector<shared_ptr<Curves::Curve>>::iterator &it1, vector<shared_ptr<Curves::Curve>>::iterator &it2, atomic<double> &sum)
{
    sum += accumulate(it1, it2, 0, [](double accumulator, shared_ptr<Curves::Curve> a)
    {
        return accumulator + a->radius();
    });
}


int main()
{
     std::random_device os_seed;
     const int seed = os_seed();

     std::mt19937 generator(seed);
     std::uniform_int_distribution<short> randomObject( 0, 2 );
     std::uniform_int_distribution<short> randomRadius( 1, 25 );
     std::uniform_int_distribution<short> randomStep( 1, 5 );

    int randNum = 0;

    std::vector<std::shared_ptr<Curves::Curve>> curveVector;

    for (int i = 0; i < 20; ++i)
    {
        randNum = randomObject(generator);

        if (randNum == 0)
            curveVector.push_back(std::make_shared<Curves::Circle>(randomRadius(generator)));

        if (randNum == 1)
             curveVector.push_back(std::make_shared<Curves::Ellipse>(randomRadius(generator), randomRadius(generator)));

        if (randNum == 2)
            curveVector.push_back(std::make_shared<Curves::Helix>(randomRadius(generator), randomStep(generator)));

    }

    vector<std::shared_ptr<Curves::Curve>> circleVector;

    for(auto it: curveVector)
    {
        printPoint(it->get3Dpoint(PI/4));

        if (typeid(*it) == typeid(Curves::Circle))
        {
            circleVector.push_back(it);
        }
    }

    sort(circleVector.begin(), circleVector.end(), [](shared_ptr<Curves::Curve> a, shared_ptr<Curves::Curve> b) { return a->radius() < b->radius();});

///https://github.com/oneapi-src/oneTBB/issues/802 same error. Solution doesn't work;
//    tbb::parallel_invoke(
//      [&circleVector, &sumOfRadii]() {
//        for (auto i = 0; i < circleVector.size()/2; i++)
//        {
//            sumOfRadii += circleVector[i]->radius();
//        }
//      },
//      [&circleVector, &sumOfRadii]() {
//        for (auto i = 0; i < circleVector.size()/2; i++)
//        {
//            sumOfRadii += circleVector[i]->radius();
//        }
//      });

    atomic<double> rSum(0);

    auto start = circleVector.begin();
    auto half  = start + circleVector.size();
    auto finish = circleVector.end();

    thread t1(sum, ref(start), ref(half), ref(rSum));
    thread t2(sum, ref(half), ref(finish), ref(rSum));

    t1.join();
    t2.join();

    cout << "Sum of all circle radii is " << rSum << "\n";

    circleVector.clear();
    curveVector.clear();

    return 0;
}
