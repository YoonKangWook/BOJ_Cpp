#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> time_calc(vector<int> current_time, vector<int> start_time)
{
    // "start_time.size()", 부호가 다른 정수 표현식의 비교로 경고 발생
    // 해결 : static_cast<int>()로 형변환
    vector<int> time_calc(static_cast<int>(start_time.size()));

    for (int i = 0; i < static_cast<int>(start_time.size()); i++)
    {
        time_calc[i] = start_time[i] - current_time[i];
    }

    if (time_calc[2] < 0)
    {
        time_calc[2] += 60;
        time_calc[1] -= 1;
    }

    if (time_calc[1] < 0)
    {
        time_calc[1] += 60;
        time_calc[0] -= 1;
    }

    if (time_calc[0] < 0)
    {
        time_calc[0] += 24;
    }

    return time_calc;
}

int main()
{
    vector<int> current_time;
    vector<int> start_time;
    vector<int> remain_time;

    // 인덱스 접근 가능, 각 인덱스는 char취급
    string str_currentTime;
    string str_startTime;

    cin >> str_currentTime;
    cin >> str_startTime;

    // :, 콜론 제거
    // error 발생 : 'std::__cxx11::basic_string<char>::iterator'를 'constchar*'로 변환할 수 없어 컴파일 에러 발생
    //str_currentTime.erase(remove(str_currentTime.begin(), str_currentTime.end(), ':'), str_currentTime.end());
    //str_startTime.erase(remove(str_startTime.begin(), str_startTime.end(), ':'), str_startTime.end());

    // 에러 수정
    str_currentTime.erase(str_currentTime.begin() + 2);
    str_currentTime.erase(str_currentTime.begin() + 4);
    str_startTime.erase(str_startTime.begin() + 2);
    str_startTime.erase(str_startTime.begin() + 4);

    // 아스키 코드값이 더해지는 문제 발생 
    // 원인 : string으로 입력 받은 후 각 문자에 인덱스로 접근함
    // 해결 방법 : int(문자) - '0'으로 char to int로 형변환
    for (int i = 0; i < 3; i++)
    {
        current_time.push_back( (int(str_currentTime[2*i]) - '0') * 10 + int(str_currentTime[2 * i + 1]) -'0');
        start_time.push_back( (int(str_startTime[2 * i]) - '0') * 10 + int(str_startTime[2 * i + 1]) - '0');
    }

    remain_time = time_calc(current_time, start_time);

    cout.width(2);
    cout.fill('0');
    cout << to_string(remain_time[0]) << ":";
    cout.width(2);
    cout.fill('0');
    cout << to_string(remain_time[1]) << ":";
    cout.width(2);
    cout.fill('0');
    cout << to_string(remain_time[2]) << endl;

    return 0;
}
