#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define MAX_N 10002
#define MAX_M 102
#define MAX_ROOMS 1002

struct PATID
{
    char code[14];
    char level; //T, A, B
    short roomCode;
    char date[7];
    short studentCode;
    short score;
};
struct RoomInfor
{
    int numStudents;
    int totalScore;
};
RoomInfor rooms[MAX_ROOMS];

struct RoomDateInfor
{
    RoomDateInfor()
    {
        memset(roomStudentsNum, 0, sizeof(short)*MAX_ROOMS);
    }
    short roomStudentsNum[MAX_ROOMS];
};
struct StudentsToRoomNum
{
    int numStudents;
    short roomNum;
};
//date->
std::map<std::string, RoomDateInfor > roomDates;
std::map<std::string, RoomDateInfor >::iterator it;
std::map<std::string, std::vector<StudentsToRoomNum> > dateMapRooms;
std::map<std::string, std::vector<StudentsToRoomNum> >::iterator it2;

bool SortStudentsToRoomNum(const StudentsToRoomNum& a, const StudentsToRoomNum& b)
{
    if(a.numStudents>b.numStudents)
        return true;
    else if(a.numStudents<b.numStudents)
        return false;
    return a.roomNum<b.roomNum;
}

bool SortByLevelScore(const PATID& a, const PATID& b)
{
    if(a.level<b.level)
        return true;
    else if(a.level>b.level)
        return false;
    if(a.score>b.score)
        return true;
    else if(a.score<b.score)
        return false;
    int ret = strcmp(a.code, b.code);
    return ret<0;
}

bool SortByDateRoom(const PATID& a, const PATID& b)
{
    int ret = strcmp(a.date, b.date);
    if(ret<0)
        return true;
    else if(ret>0)
        return false;
    return a.roomCode<b.roomCode;
}

PATID ids[MAX_N];
int main()
{
    int N, M, i;
    short type, roomCode, score;
    char str[14], temp[14], date[7];

    cin>>N>>M;
    for(i=0; i<N; ++i)
    {
        cin>>str>>score;
        ids[i].score = score;
        strcpy(ids[i].code, str);
        ids[i].level = str[0];
        strncpy(temp, str+1, 3);
        temp[3] = '\0';
        roomCode = atoi(temp);
        ids[i].roomCode = roomCode;
        strncpy(temp, str+4, 6);
        temp[6] = '\0';
        strcpy(ids[i].date, temp);
        ids[i].studentCode = atoi(str+10);

        //prepare room information
        ++rooms[roomCode].numStudents;
        rooms[roomCode].totalScore+=score;

        //prepare room&date information
        //roomDates[roomCode].push_back()
        it=roomDates.find(ids[i].date);
        if(it==roomDates.end())
        {
            RoomDateInfor rdi;
            rdi.roomStudentsNum[roomCode] = 1;
            roomDates.insert(std::make_pair(ids[i].date, rdi));
        }
        else
        {
            ++it->second.roomStudentsNum[roomCode];
        }
    }

    //sort by date and room, and fill into roomDates
    std::sort(ids, ids+N, SortByDateRoom);


    int j;
    for(it=roomDates.begin(); it!=roomDates.end(); ++it)
    {
        std::vector<StudentsToRoomNum> srs;
        StudentsToRoomNum sr;
        for(j=0; j<MAX_ROOMS; ++j)
        {
            if(it->second.roomStudentsNum[j])
            {
                sr.numStudents = it->second.roomStudentsNum[j];
                sr.roomNum = j;
                srs.push_back(sr);
            }
        }
        std::sort(srs.begin(), srs.end(), SortStudentsToRoomNum);
        dateMapRooms[it->first] = srs;
    }
    roomDates.clear();

    std::sort(ids, ids+N, SortByLevelScore);
    for(i=0; i<M; ++i)
    {
        std::string level;
        cin>>type;
        if(type==1)
        {
            cin>>level;
            cout<<"Case "<<i+1<<": "<<type<<" "<<level<<"\n";
            if(level.size()!=1)
                cout<<"NA"<<endl;
            else
            {
                bool bFind=false;
                for(j=0; j<N; ++j)
                {
                    if(ids[j].level==level[0])
                    {
                        cout<<ids[j].code<<" "<<ids[j].score<<"\n";
                        bFind = true;
                    }
//                    else if(ids[j].level>level[0])
//                        break;
                }
                if(!bFind)
                    cout<<"NA"<<endl;
            }
        }
        else if(type==2)
        {
            std::string rc;
            cin>>rc;
            cout<<"Case "<<i+1<<": "<<type<<" "<<rc<<"\n";
            roomCode = atoi(rc.c_str());
            if(roomCode<0 || roomCode>=MAX_ROOMS || rooms[roomCode].numStudents==0)
                cout<<"NA"<<endl;
            else
                cout<<rooms[roomCode].numStudents<<" "<<rooms[roomCode].totalScore<<endl;
        }
        else if(type==3)
        {
            cin>>date;
            cout<<"Case "<<i+1<<": "<<type<<" "<<date<<"\n";
            it2 = dateMapRooms.find(date);
            if(it2==dateMapRooms.end())
                cout<<"NA"<<endl;
            else
            {
                for(j=0; j<it2->second.size(); ++j)
                {
                    cout<<it2->second[j].roomNum<<" "<<it2->second[j].numStudents<<endl;
                }
            }
        }
    }

    return 0;
}
