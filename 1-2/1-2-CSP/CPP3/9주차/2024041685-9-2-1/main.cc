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

        // 중괄호를 기준으로 입력 분리
        size_t firstOpen = input.find('{');
        size_t firstClose = input.find('}');
        size_t secondOpen = input.rfind('{');
        size_t secondClose = input.rfind('}');

        if (firstOpen == std::string::npos || firstClose == std::string::npos ||
            secondOpen == std::string::npos || secondClose == std::string::npos || firstClose > secondOpen) {
            std::cout << "잘못된 입력 형식입니다. 다시 입력하세요.\n";
            continue;
        }

        // 각 집합 문자열 및 연산자 추출
        setStr1 = input.substr(firstOpen, firstClose - firstOpen + 1);
        setStr2 = input.substr(secondOpen, secondClose - secondOpen + 1);
        operation = input.substr(firstClose + 1, secondOpen - firstClose - 1);
        operation.erase(remove(operation.begin(), operation.end(), ' '), operation.end()); // 공백 제거

        // 문자열을 집합으로 변환
        set1 = parseSet(setStr1);
        set2 = parseSet(setStr2);

        // 연산 수행
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
            std::cout << "지원하지 않는 연산자입니다. (+, -, *만 사용 가능)\n";
            continue;
        }

        // 결과 출력
        printSet(result);
    }

    return 0;
}
