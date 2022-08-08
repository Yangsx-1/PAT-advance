#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct stu
{
    string reg;
    int score;
    int frank;
    int lrank;
    int loc;
};

bool cmp(stu stu1, stu stu2)
{
    if (stu1.score != stu2.score) return stu1.score > stu2.score;
    else return stu1.reg < stu2.reg;
}

int main()
{
    int n;
    cin >> n;
    int total = 0;
    vector<stu> ftotal;
    for (int i = 1; i <= n; ++i)
    {
        int people;
        cin >> people;
        total += people;
        vector<stu> ltotal;
        for (int j = 0; j < people; ++j)
        {
            stu tmp;
            cin >> tmp.reg >> tmp.score;
            tmp.loc = i;
            ltotal.push_back(tmp);
        }
        sort(ltotal.begin(), ltotal.end(), cmp);
        ltotal[0].lrank = 1;
        for (int j = 1; j < people; ++j)
        {
            if (ltotal[j - 1].score == ltotal[j].score)
            {
                ltotal[j].lrank = ltotal[j - 1].lrank;
            }
            else
            {
                ltotal[j].lrank = j + 1;
            }
        }
        ftotal.insert(ftotal.end(), ltotal.begin(), ltotal.end());
    }
    sort(ftotal.begin(), ftotal.end(), cmp);
    ftotal[0].frank = 1;
    for (int j = 1; j < total; ++j)
    {
        if (ftotal[j - 1].score == ftotal[j].score)
        {
            ftotal[j].frank = ftotal[j - 1].frank;
        }
        else
        {
            ftotal[j].frank = j + 1;
        }
    }
    cout << total << endl;
    for (int j = 0; j < total; ++j)
    {
        cout << ftotal[j].reg << " " << ftotal[j].frank << " " << ftotal[j].loc << " " << ftotal[j].lrank << endl;
    }
}
