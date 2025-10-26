#ifndef __SETFUNC_H__
#define __SETFUNC_H__

#include <set>
#include <string>

std::set<int> parseSet(const std::string& str); //문자열 -> set에 저장
void printSet(const std::set<int>&); //집합 출력하기
std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1); //교집합 구하기
std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1); //합집합 구하기
std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1); //차집합 구하기 

#endif 