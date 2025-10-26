#ifndef __SETFUNC_H__
#define __SETFUNC_H__

#include <set>
#include <string>

std::set<int> parseSet(const std::string& str); //���ڿ� -> set�� ����
void printSet(const std::set<int>&); //���� ����ϱ�
std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1); //������ ���ϱ�
std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1); //������ ���ϱ�
std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1); //������ ���ϱ� 

#endif 