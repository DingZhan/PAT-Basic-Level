#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100002
typedef struct _Student
{
    char ID[7];
    short score;
    char university[7];
}Student;
typedef struct _UniversityScore
{
    double totalScore;
    char university[7];
    int numStudents;
}UniversityScore;

int SortByUniversity(const void* a, const void *b)
{
    Student *aa = (Student*)a;
    Student *bb = (Student*)b;
    return strcmp(aa->university, bb->university);
}
int SortFinal(const void *a, const void *b)
{
    UniversityScore *aa = (UniversityScore*)a;
    UniversityScore *bb = (UniversityScore*)b;
    if((int)aa->totalScore < (int)bb->totalScore)
        return 1;
    else if((int)aa->totalScore > (int)bb->totalScore)
        return 0;
    if(aa->numStudents<bb->numStudents)
        return 0;
    else if(aa->numStudents>bb->numStudents)
        return 1;
    return strcmp(aa->university, bb->university);
}

Student results[MAX_N];
UniversityScore uss[MAX_N];
int main()
{
    int N, i, j, rank;
    char *p;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%s%d%s", results[i].ID, &(results[i].score), results[i].university);
        p = results[i].university;
        while((*p)!='\0')
        {
            if((*p)>='A'&&(*p)<='Z')
                (*p) = (*p)-'A' + 'a';
            ++p;
        }
    }
    qsort(results, N, sizeof(Student), SortByUniversity);

    /*
    printf("\n\nAfter sorting...\n");
    for(i=0; i<N; ++i)
    {
        printf("%s %s %d\n", results[i].university, results[i].ID, results[i].score);
    }*/

    UniversityScore us={0, "", 0};
    for(i=0, j=0; i<N; ++i)
    {
        if(strcmp(results[i].university, us.university))
        {
            if(us.numStudents)
            {
                strcpy(uss[j].university, us.university);
                uss[j].numStudents = us.numStudents;
                uss[j].totalScore = us.totalScore;
                ++j;
                us.numStudents = 0;
                us.totalScore = 0.0;
            }
            strcpy(us.university, results[i].university);
        }
        if(results[i].ID[0]=='T')
            us.totalScore +=1.5*results[i].score;
        else if(results[i].ID[0]=='A')
            us.totalScore +=results[i].score;
        else if(results[i].ID[0]=='B')
            us.totalScore +=results[i].score/1.5;
        ++us.numStudents;
    }
    if(us.numStudents)
    {
        strcpy(uss[j].university, us.university);
        uss[j].numStudents = us.numStudents;
        uss[j].totalScore = us.totalScore;
        ++j;
    }

    /*
    printf("\n\nAfter calculating...\n");
    for(i=0; i<j; ++i)
    {
        printf("%s %d %g\n", uss[i].university, uss[i].numStudents, uss[i].totalScore);
    }*/

    qsort(uss, j, sizeof(UniversityScore), SortFinal);
    printf("%d\n", j);
    int lastScore = -1;
    for(i=0; i<j; ++i)
    {
        if((int)uss[i].totalScore!=lastScore)
            rank = i+1;
        printf("%d %s %d %d\n", rank, uss[i].university,
               (int)uss[i].totalScore, uss[i].numStudents);
        lastScore = uss[i].totalScore;
    }
    return 0;
}
