#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

class generator_1{
public:
    unsigned long start;
    int minV;
    int maxV;

    generator_1(unsigned long start_, int minV_, int maxV_){
        start = start_;
        minV = minV_;
        maxV = maxV_;
    }

    int next() {
        start = (unsigned int)(start) * 19004983 + 19004989;
        return minV + start % (maxV - minV);
    }
};

class generator_2{
public:
    unsigned long start, randM = 7837654853;
    int minV;
    int maxV;

    generator_2(unsigned long start_, int minV_, int maxV_){
        start = start_;
        minV = minV_;
        maxV = maxV_;
    }

    int next() {
        start ^= start << 11;
        start ^= start >> 13;
        start ^= start << 7;
        start %= randM;
        return minV + start % (maxV - minV);
    }
};

void analys(vector <int> array){
    cout << "Volume " << array.size() << "\n\n";

    double mean = 0.0;
    for (auto v : array)
        mean = mean + v;
    mean = mean / array.size();

    cout << "Mean " << mean << "\n\n";

    double deviation = 0.0;

    for (auto v : array)
        deviation += (v - mean) * (v - mean);
    deviation = deviation / array.size();
    deviation = pow(deviation, 0.5);

    cout << "Standard deviation " << deviation << "\n\n";

    cout << "Coefficient of variation " << deviation / mean << "\n\n";

    vector <long long> n = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (long long i = 0; i < array.size(); i++)
        n[array[i] / 1000]++;

    double xisum = 0.0;

    for (long long i = 0; i < 10; i++)
        xisum = xisum + (n[i] * n[i] * 10);

    xisum = xisum / array.size();
    xisum = xisum - array.size();

    cout << "___Value of criterion is " << xisum << "___\n\n";
}

int main(){
    cout << "Time with C++ random generator\n";

    vector <int> d_100 = {}, d_500 = {}, d_1000 = {}, d_5000 = {}, d_10000 = {}, d_50000 = {}, d_100000 = {}, d_500000 = {}, d_1000000 = {}, d_5000000 = {};

    srand(time(NULL));

    auto s_t = chrono::steady_clock::now();
    for (long i = 0; i < 100; i++)
        d_100.push_back(rand());
    cout << "Generation time for volume of\t100\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 500; i++)
        d_500.push_back(rand());
    cout << "Generation time for volume of\t500\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 1000; i++)
        d_1000.push_back(rand());
    cout << "Generation time for volume of\t1000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 5000; i++)
        d_5000.push_back(rand());
    cout << "Generation time for volume of\t5000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 10000; i++)
        d_10000.push_back(rand());
    cout << "Generation time for volume of\t10000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 50000; i++)
        d_50000.push_back(rand());
    cout << "Generation time for volume of\t50000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 100000; i++)
        d_100000.push_back(rand());
    cout << "Generation time for volume of\t100000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 500000; i++)
        d_500000.push_back(rand());
    cout << "Generation time for volume of\t500000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 1000000; i++)
        d_1000000.push_back(rand());
    cout << "Generation time for volume of\t1000000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

    s_t = chrono::steady_clock::now();
    for (long i = 0; i < 5000000; i++)
        d_5000000.push_back(rand());
    cout << "Generation time for volume of\t5000000\t"
         << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count()
         << "\n";

    cout << "\n\n\n";

    int option;
    cout << "What generator do you want: LCPRNG - print 1, XOR-Shift - print 2\n";
    cin >> option;
    cout << endl;

    if (option == 1){
        generator_1 puk(6089, 0, 10000);
        ofstream out("output.txt");
        vector <int> d_100 = {}, d_500 = {}, d_1000 = {}, d_5000 = {}, d_10000 = {}, d_50000 = {}, d_100000 = {}, d_500000 = {}, d_1000000 = {}, d_5000000 = {};

        auto s_t = chrono::steady_clock::now();
        for (long i = 0; i < 100; i++)
            d_100.push_back(puk.next());
        cout << "The time for array with volume 100\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 500; i++)
            d_500.push_back(puk.next());
        cout << "The time for array with volume 500\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 1000; i++)
            d_1000.push_back(puk.next());
        cout << "The time for array with volume 1000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 5000; i++)
            d_5000.push_back(puk.next());
        cout << "The time for array with volume 5000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 10000; i++)
            d_10000.push_back(puk.next());
        cout << "The time for array with volume 10000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 50000; i++)
            d_50000.push_back(puk.next());
        cout << "The time for array with volume 50000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 100000; i++)
            d_100000.push_back(puk.next());
        cout << "The time for array with volume 100000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 500000; i++)
            d_500000.push_back(puk.next());
        cout << "The time for array with volume 500000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 1000000; i++)
            d_1000000.push_back(puk.next());
        cout << "The time for array with volume 1000000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 5000000; i++)
            d_5000000.push_back(puk.next());
        cout << "The time for array with volume 5000000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        analys(d_100);
        analys(d_500);
        analys(d_1000);
        analys(d_5000);
        analys(d_10000);
        analys(d_50000);
        analys(d_100000);
        analys(d_500000);
        analys(d_1000000);
        analys(d_5000000);
    }

    if (option == 2){
        generator_2 puk(6089, 0, 10000);
        ofstream out("output.txt");
        vector <int> d_100 = {}, d_500 = {}, d_1000 = {}, d_5000 = {}, d_10000 = {}, d_50000 = {}, d_100000 = {}, d_500000 = {}, d_1000000 = {}, d_5000000 = {};

        auto s_t = chrono::steady_clock::now();
        for (long i = 0; i < 100; i++)
            d_100.push_back(puk.next());
        cout << "The time for array with volume 100\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 500; i++)
            d_500.push_back(puk.next());
        cout << "The time for array with volume 500\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 1000; i++)
            d_1000.push_back(puk.next());
        cout << "The time for array with volume 1000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 5000; i++)
            d_5000.push_back(puk.next());
        cout << "The time for array with volume 5000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 10000; i++)
            d_10000.push_back(puk.next());
        cout << "The time for array with volume 10000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 50000; i++)
            d_50000.push_back(puk.next());
        cout << "The time for array with volume 50000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 100000; i++)
            d_100000.push_back(puk.next());
        cout << "The time for array with volume 100000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 500000; i++)
            d_500000.push_back(puk.next());
        cout << "The time for array with volume 500000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 1000000; i++)
            d_1000000.push_back(puk.next());
        cout << "The time for array with volume 1000000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        s_t = chrono::steady_clock::now();
        for (long i = 0; i < 5000000; i++)
            d_5000000.push_back(puk.next());
        cout << "The time for array with volume 5000000\t" << chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - s_t).count() << "\n";

        analys(d_100);
        analys(d_500);
        analys(d_1000);
        analys(d_5000);
        analys(d_10000);
        analys(d_50000);
        analys(d_100000);
        analys(d_500000);
        analys(d_1000000);
        analys(d_5000000);
    }
}
