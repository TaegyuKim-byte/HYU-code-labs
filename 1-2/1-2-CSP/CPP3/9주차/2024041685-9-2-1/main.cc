#include "setfunc.h"
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::string input, setStr1, setStr2, operation;
    std::set<int> set1, set2, result;

    while (true) {
        std::getline(std::cin, input);

        if (input == "0") {
            break;
        }

        // �߰�ȣ�� �������� �Է� �и�
        size_t firstOpen = input.find('{');
        size_t firstClose = input.find('}');
        size_t secondOpen = input.rfind('{');
        size_t secondClose = input.rfind('}');

        if (firstOpen == std::string::npos || firstClose == std::string::npos ||
            secondOpen == std::string::npos || secondClose == std::string::npos || firstClose > secondOpen) {
            std::cout << "�߸��� �Է� �����Դϴ�. �ٽ� �Է��ϼ���.\n";
            continue;
        }

        // �� ���� ���ڿ� �� ������ ����
        setStr1 = input.substr(firstOpen, firstClose - firstOpen + 1);
        setStr2 = input.substr(secondOpen, secondClose - secondOpen + 1);
        operation = input.substr(firstClose + 1, secondOpen - firstClose - 1);
        operation.erase(remove(operation.begin(), operation.end(), ' '), operation.end()); // ���� ����

        // ���ڿ��� �������� ��ȯ
        set1 = parseSet(setStr1);
        set2 = parseSet(setStr2);

        // ���� ����
        if (operation == "+") {
            result = getUnion(set1, set2);
        }
        else if (operation == "*") {
            result = getIntersection(set1, set2);
        }
        else if (operation == "-") {
            result = getDifference(set1, set2);
        }
        else {
            std::cout << "�������� �ʴ� �������Դϴ�. (+, -, *�� ��� ����)\n";
            continue;
        }

        // ��� ���
        printSet(result);
    }

    return 0;
}
