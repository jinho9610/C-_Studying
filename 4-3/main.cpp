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

    // �ֱٿ� ������ ��ü���� �Ҹ�Ǵ� ������ ����
    marine1.show_status();
    marine2.show_status();
    cout << '\n';
}