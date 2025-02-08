#include <vector>
#include <string>
#ifndef HEADERS_HPP_
#define HEADERS_HPP_

template<class T>
class testBuild {
    private:
        std::string name;
        std::vector<T> list;
    public:
        testBuild();
        testBuild(std::string, std::vector<T>);
        testBuild(std::string &, std::vector<T> &);
        ~testBuild();
        void print();
        int get_size();
};
#endif