/* https://modoocode.com/169 */
#include <iostream>

using namespace std;

typedef struct Animal
{
    char name[100]; // 이름
    int age;        // 나이

    int health; // 체력
    int food;   // 배부른 정도
    int clean;  // 청결도
} Animal;

typedef struct Bird
{
    char name[100]; // 이름
    int age;        // 나이

    int health; // 체력
    int food;   // 배부른 정도
    int clean;  // 청결도

    int height; // 고도
} Bird;

typedef struct Fish
{
    char name[100]; // 이름
    int age;        // 나이

    int health; // 체력
    int food;   // 배부른 정도
    int clean;  // 청결도

    int deep; // 수심
} Fish;

/* 사실 Bird와 Fish는 Animal과 큰 차이가 없음에도 처음부터
모두 정의해주어야 하는 것이 굉장히 비효율적 */

void create_anmial(Animal *animal)
{
    cout << "동물의 이름? ";
    cin >> animal->name;

    cout << "동물의 나이? ";
    cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal)
{
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal)
{
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal)
{
    cout << animal->name << "의 상태" << endl;
    cout << "체력\t:" << animal->health << endl;
    cout << "배부름\t:" << animal->food << endl;
    cout << "청결도\t:" << animal->clean << endl;
}

int main()
{
    Animal *list[10];
    int animal_num = 0;

    for (;;)
    {
        cout << "1. 동물 추가하기" << endl;
        cout << "2. 놀기" << endl;
        cout << "3. 상태 보기" << endl;

        int input;
        cin >> input;

        switch (input)
        {
            int play_with;

        case 1:
            list[animal_num] = new Animal;
            create_anmial(list[animal_num]);
            animal_num++;
            break;

        case 2:
            cout << "누구랑 놀게?: ";
            cin >> play_with;
            if (play_with < animal_num)
                play(list[play_with - 1]);
            else
                continue;

            break;

        case 3:
            cout << "누구껄 보게?: ";
            cin >> play_with;
            if (play_with < animal_num)
                show_stat(list[play_with - 1]);
            else
                continue;

            break;

        default:
            break;
        }

        for (int i = 0; i < animal_num; i++)
            one_day_pass(list[i]);
    }
    for (int i = 0; i < animal_num; i++)
        delete list[i]; // 프로그램 종료 전 동물 메모리 해제
}