#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Students{
    public:
        string StuID;
        int solve;
        int score = 0;
};

bool cmp(Students A,Students B)
{
    if(A.score != B.score)
        return A.score > B.score;
    else
        return A.StuID < B.StuID;
}

void print(int present_location)
{
    cout << "case #" << present_location << ":" << endl;
    return;
}

void question(int present_location)
{
    int N, M, G; // N:学生人数 M:题目数量，不超过10道  G:合格线
    cin >> N >> M >> G;
    int scores[10] = {0}; // 每道题分值
    int temp;
    for (int i = 0; i < M;i++)
    {
        cin >> temp;
        scores[i] = temp;
    }

    Students student[500];
    for (int i = 0; i < N;i++)
    {
        cin >> student[i].StuID >> student[i].solve;
        int quesID;
        for (int j = 0; j < student[i].solve;j++)
        {
            cin >> quesID;
            student[i].score += scores[quesID - 1];
        }
    }

    sort(student, student + N, cmp);

    print(present_location);

    int cnt = 0;
    for (int i = 0; i < N;i++)
    {
        if(student[i].score >= G)
            cnt++;
        else
            break;
    }

    cout << cnt << endl;

    for (int i = 0; i < cnt;i++)
    {
        cout << student[i].StuID << ' ' << student[i].score << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T;i++)
        question(i);
    return 0;
}