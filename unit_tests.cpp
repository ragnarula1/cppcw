#include "fraction.h"
#include "sample.h"
#include "samplet.h"
#include <assert.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void test_fraction(const fraction &a, const fraction &b, 
    const fraction &add, const fraction &sub, 
    const fraction &mult, const fraction &divi)
{   
    cout << "Fraction: " << a << " " << b;
    assert(a + b == add);
    cout << " += " << add;
    assert(a - b == sub);
    cout << " -= " << sub;
    assert(a * b == mult);
    cout << " *= " << mult;
    assert(a / b == divi);
    cout << " /= " << divi;
    cout << " Passed!" << endl;
}

void test_sample(const sample &sam, uint size, 
    double minimum, double maximum, double range, 
    double midrange, double median, double mean, 
    double variance, double std)
{
    double epsilon = 0.0001;
    cout << "Sample: " << sam << " ";
    vector<double> data(sam.get_data());
    cout << "size " << data.size() << "(" << size << ") ";
    assert(data.size() == size);
    cout << "is sorted ";
    assert(is_sorted(data.begin(),data.end()));
    cout << "minimum " << sam.minimum() << "(" << minimum << ") ";
    assert(abs(sam.minimum() - minimum) < epsilon);
    cout << "maximum " << sam.maximum() << "(" << maximum << ") ";
    assert(abs(sam.maximum() - maximum) < epsilon);
    cout << "range " << sam.range() << "(" << range << ") ";
    assert(abs(sam.range() - range) < epsilon);
    cout << "midrange " << sam.midrange() << "(" << midrange << ") ";
    assert(abs(sam.midrange() - midrange) < epsilon);
    cout << "median " << sam.median() << "(" << median << ") ";
    assert(abs(sam.median() - median) < epsilon);
    cout << "mean " << sam.mean() << "(" << mean << ") ";
    assert(abs(sam.mean() - mean) < epsilon);
    cout << "variance " << sam.variance() << "(" << variance << ") ";
    assert(abs(sam.variance() - variance) < epsilon);
    cout << "std deviation " << sam.std_deviation() << "(" << std << ") ";
    assert(abs(sam.std_deviation() - std) < epsilon);
    
    cout << " Passed!" << endl;
}
template <typename T>
void test_sample_t(const samplet<T> &sam, uint size, 
    T minimum, T maximum, T range, 
    T midrange, T median, T mean, 
    double variance, double std)
{
    double epsilon = 0.0001;
    cout << "Sample: " << sam << " ";
    vector<T> data(sam.get_data());
    cout << "size " << data.size() << "(" << size << ") ";
    assert(data.size() == size);
    cout << "is sorted ";
    assert(is_sorted(data.begin(),data.end()));
    cout << "minimum " << sam.minimum() << "(" << minimum << ") ";
    assert(abs(sam.minimum() - minimum) < epsilon);
    cout << "maximum " << sam.maximum() << "(" << maximum << ") ";
    assert(abs(sam.maximum() - maximum) < epsilon);
    cout << "range " << sam.range() << "(" << range << ") ";
    assert(abs(sam.range() - range) < epsilon);
    cout << "midrange " << sam.midrange() << "(" << midrange << ") ";
    assert(abs(sam.midrange() - midrange) < epsilon);
    cout << "median " << sam.median() << "(" << median << ") ";
    assert(abs(sam.median() - median) < epsilon);
    cout << "mean " << sam.mean() << "(" << mean << ") ";
    assert(abs(sam.mean() - mean) < epsilon);
    cout << "variance " << sam.variance() << "(" << variance << ") ";
    assert(abs(sam.variance() - variance) < epsilon);
    cout << "std deviation " << sam.std_deviation() << "(" << std << ") ";
    assert(abs(sam.std_deviation() - std) < epsilon);
    
    cout << " Passed!" << endl;
}

sample build_sample(const string &sample_str)
{
    stringstream stream(sample_str);
    sample s;
    stream >> s;
    return s;
}

template <typename T>
samplet<T> build_sample_t(const string &sample_str)
{
    stringstream stream(sample_str);
    samplet<T> s;
    stream >> s;
    return s;
}

int main () 
{
    
    test_fraction(fraction(1,2),fraction(1,2),fraction(1,1),fraction(0,1),fraction(1,4),fraction(1,1));
    test_sample(build_sample("< 6 :7 11 2 13 3 5>"),6,2,13,11,7.5,6,6.833333,16.1389,4.01732);
    test_sample_t<fraction>(build_sample_t<fraction>("< 2: 1/2 1/4 >"), 2, fraction(1,4),
        fraction(1,2),fraction(1,4),fraction(3,8),fraction(3,8),fraction(3,8),
        0.0078125, 0.088388347);
    return 0;
}