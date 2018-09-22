#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 100001
struct Student
{
    char university[7];
    char type; //B, A, T
    int score;
};
bool SortStudentByUniversity(const Student& a, const Student& b)
{
    return strcmp(a.university, b.university)<0;
}
struct University
{
    char name[7];
    int studentNum;
    double totalScore;
};

bool SortUniversity(const University& a, const University& b)
{
    if((int)a.totalScore>(int)b.totalScore)
        return true;
    else if((int)a.totalScore<(int)b.totalScore)
        return false;
    if(a.studentNum<b.studentNum)
        return true;
    else if(a.studentNum>b.studentNum)
        return false;
    return strcmp(a.name, b.name)<0;
}

int main()
{
    int N, i, j;
    std::vector<Student>  students;
    std::vector<University> universities;
    char name[7];
    cin>>N;
    students.resize(N);
    for(i=0; i<N; ++i)
    {
        cin>>name;
        students[i].type = name[0];
        cin>>students[i].score>>students[i].university;
        for(j=0; j<7; ++j)
            students[i].university[j] = tolower(students[i].university[j]);
    }
    std::sort(students.begin(), students.end(), SortStudentByUniversity);

    University uni;
    uni.name[0]='\0';
    uni.studentNum = 0;
    uni.totalScore = 0;
    for(i=0; i<N; ++i)
    {
        if(strcmp(students[i].university, uni.name))
        {
            if(i!=0)
            {
                universities.push_back(uni);
            }
            //init next
            strcpy(uni.name, students[i].university);
            uni.studentNum = 1;
            if(students[i].type=='B')
                uni.totalScore=students[i].score/1.5;
            else if(students[i].type=='A')
                uni.totalScore=students[i].score;
            else
                uni.totalScore=students[i].score*1.5;
        }
        else
        {
            ++uni.studentNum;
            if(students[i].type=='B')
                uni.totalScore+=students[i].score/1.5;
            else if(students[i].type=='A')
                uni.totalScore+=students[i].score;
            else
                uni.totalScore+=students[i].score*1.5;
        }
    }
    universities.push_back(uni);
    std::sort(universities.begin(), universities.end(), SortUniversity);
    cout<<universities.size()<<endl;
    int rank=1, lastScore=-1;
    for(i=0; i<universities.size(); ++i)
    {
        if((int)universities[i].totalScore!=lastScore)
            rank = i+1;
        cout<<rank<<" "<<universities[i].name<<" "<<(int)universities[i].totalScore<<" "<<universities[i].studentNum<<endl;
        lastScore=universities[i].totalScore;
    }
}
