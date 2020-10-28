#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <vector>
class Permutation
{
  public:
    Permutation(int length);
    void initS(int length);
    void printS();
    void perm1();
    void swap(int i, int j); 
    std::vector<int> getS();
    int fact(int n);
  private:
    static const int MAX = 20;  // twenty cities max
    int nfact = 1;
	 int n;
    int count = 1;
    std::vector<int> s;
};

#endif