#include "reply_admin.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm> // 추가된 부분

int main() {
    ReplyAdmin admin;
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (input == "#quit") {
            break;  // 종료 명령어 처리
        }

        if (input[0] != '#') {  // 일반 채팅 추가
            if (admin.addChat(input)) {
                admin.printChats();
            } else {
                std::cout << "Error!" << std::endl;  // 추가 실패 처리
            }
            continue;
        }

        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "#remove") {
            std::string indicesPart;
            std::getline(iss, indicesPart);

            // 각 인덱스를 담을 벡터
            std::vector<int> indicesToRemove;
            std::istringstream tokenStream(indicesPart);
            std::string token;

            bool hasValidIndex = false;

            while (std::getline(tokenStream, token, ',')) {
                // '-' 범위 처리
                if (token.find('-') != std::string::npos) {
                    size_t pos = token.find('-');
                    int start = std::stoi(token.substr(0, pos));
                    int end = std::stoi(token.substr(pos + 1));

                    // 범위 유효성 검사
                    if (start >= 0 && end >= start) {
                        for (int i = start; i <= end; ++i) {
                            if (i < admin.getChatCount()) {
                                indicesToRemove.push_back(i);
                                hasValidIndex = true;
                            }
                        }
                    }
                } 
                // 단일 인덱스 처리
                else {
                    try {
                        int index = std::stoi(token);
                        if (index >= 0 && index < admin.getChatCount()) {
                            indicesToRemove.push_back(index);
                            hasValidIndex = true;
                        }
                    } catch (std::invalid_argument&) {
                        // 변환 실패 처리 (무시)
                    }
                }
            }

            // 유효한 인덱스가 있는 경우 삭제 처리
            if (hasValidIndex) {
                // 정렬 후 중복 제거 (내림차순 정렬)
                std::sort(indicesToRemove.begin(), indicesToRemove.end(), std::greater<int>());
                indicesToRemove.erase(std::unique(indicesToRemove.begin(), indicesToRemove.end()), indicesToRemove.end());

                // 멤버 함수 호출
                if (admin.removeChat(indicesToRemove.data(), indicesToRemove.size())) {
                    admin.printChats();
                } else {
                    std::cout << "Error!" << std::endl;  // 삭제 실패 처리
                }
            } else {
                std::cout << "Error!" << std::endl;  // 유효한 인덱스 없음
            }
        }
    }

    return 0;
}
