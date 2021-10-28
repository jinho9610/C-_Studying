#include "Marine.hpp"

int main() {
    Marine marine1(2, 3, "Jason");
    marine1.show_status();

    Marine marine2(3, 5, "Sean");
    marine2.show_status();

    cout << endl
         << "Marine1 attacked Marine2!\n"
         << endl;
    marine2.be_attacked(marine1.attack());

    // 최근에 생성된 객체부터 소멸되는 것으로 보임
    marine1.show_status();
    marine2.show_status();
    cout << '\n';
}