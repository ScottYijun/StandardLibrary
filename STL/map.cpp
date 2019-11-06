#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
//https://blog.csdn.net/zhuochuyu7096/article/details/82817197
//https://blog.csdn.net/sevenjoin/article/details/81943864
//https://www.cnblogs.com/aaronzlq/p/3612629.html

//A3, A4, A5, A6, A7, A8, A9, C1, C2, C3, C4, C5, C6, C7,E5,J1,Note 3
//brandName="Samsung" deviceName="Galaxy A3"
//DownloadPages="downloading1"RecoveryPages="s1"
typedef struct stData{
    string deviceName;
    string brandName;
    string DownloadPages;
    string RecoveryPages;
}STDeviceInfo;

//map实际应用， 手机型号关系手机信息表   unordered_map对比用法
int main()
{
    map<string, STDeviceInfo> mapData;
    STDeviceInfo tempData;
    tempData.deviceName = "Galaxy A1";
    tempData.brandName = "Samsung";
    tempData.DownloadPages = "downloading1";
    tempData.RecoveryPages = "s1";
    //把手机型号的数据添加到map中.
    cout << "1.insert三种插入方式工a:pair<string, STDeviceInfo>, b:map<string, STDeviceInfo>::value_type(string, STDeviceInfo), c:mapData[string] = STDeviceInfo" << endl;
    mapData.insert(pair<string, STDeviceInfo>("Galaxy A1", tempData));

    tempData.deviceName = "Galaxy A2";
    tempData.brandName = "Samsung";
    tempData.DownloadPages = "downloading2";
    tempData.RecoveryPages = "s2";
    mapData.insert(map<string, STDeviceInfo>::value_type("Galaxy A2", tempData));

    tempData.deviceName = "Galaxy A3";
    tempData.brandName = "Samsung";
    tempData.DownloadPages = "downloading3";
    tempData.RecoveryPages = "s3";
    mapData["Galaxy A3"] = tempData;
    //取值
    map<string, STDeviceInfo>::iterator it = mapData.begin();
    STDeviceInfo temp2 = it->second;
    cout << it->first << "=>" << temp2.deviceName << endl;
    it++;
    temp2 = it->second;
    cout << it->first << "=>" << temp2.deviceName << endl;
    it++;
    temp2 = it->second;
    cout << it->first << "=>" << temp2.deviceName << endl;

    cout << "2.size() 获取map的大小" << endl;
    cout << "mapData.size()=====" << mapData.size() << endl;
    cout << "3.at(key) 获取key所对应的值" << endl;
    STDeviceInfo temp3 = mapData.at("Galaxy A3");
    cout << "Galaxy A3=>" << temp3.deviceName << endl;
    cout << "4.find(key) 查找key所在对象的位置，如果没有，返回的iter与end函数的值相同，" << endl;
    //find与at的区别是，find返回的是迭代器，而at返回是key对应的值
    map<string, STDeviceInfo>::iterator it2 = mapData.find("Galaxy A2");
    temp2 = it2->second;
    cout << it2->first << "=>" << temp2.deviceName << endl;
    cout << "5.begin() 返回map第一个元素的迭代器，6.end()指向map最后一个元素的下一位置的迭代器" << endl;
    for(map<string, STDeviceInfo>::iterator it = mapData.begin(); it != mapData.end(); ++it)
    {
        STDeviceInfo temp4 = it->second;
        cout << it->first << "=>" << temp4.brandName << "," << temp4.DownloadPages << "," << temp4.RecoveryPages << endl;
    }
    cout << "7.rbegin() 返回map最后一个元素的迭代器，8.rend()指向map第一个元素的-1的位置的迭代器" << endl;
    for(map<string, STDeviceInfo>::reverse_iterator it = mapData.rbegin(); it != mapData.rend(); ++it)
    {
        STDeviceInfo temp4 = it->second;
        cout << it->first << "=>" << temp4.brandName << "," << temp4.DownloadPages << "," << temp4.RecoveryPages << endl;
    }

    cout << "9.count(key) 返回map中含有key关键字元素的个数，由于map的关键字不是重复的，所以这个返回值是1" << endl;
    //count(key)与size()的区别的，count返回的是含有key关键字的元素的个数，而size返回的是整个map的元素的个数。
    cout << "mapData.count(Galaxy A2) = " << mapData.count("Galaxy A2") << endl;
    cout << "10.emplace 构造并插入元素" << endl;
    //C++11中，针对顺序容器(如vector、deque、list)，新标准引入了三个新成员：emplace_front、emplace和emplace_back，这些操作构造而不是拷贝元素。这些操作分别对应push_front、insert和push_back，允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。
//当调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器中。而当我们调用一个emplace成员函数时，则是将参数传递给元素类型的构造函数。emplace成员使用这些参数在容器管理的内存空间中直接构造元素。
//emplace函数的参数根据元素类型而变化，参数必须与元素类型的构造函数相匹配。emplace函数在容器中直接构造元素。传递给emplace函数的参数必须与元素类型的构造函数相匹配。
//其它容器中，std::forward_list中的emplace_after、emplace_front函数，std::map/std::multimap中的emplace、emplace_hint函数，std::set/std::multiset中的emplace、emplace_hint，std::stack中的emplace函数，等emplace相似函数操作也均是构造而不是拷贝元素。
//emplace相关函数可以减少内存拷贝和移动。当插入rvalue，它节约了一次move构造，当插入lvalue，它节约了一次copy构造。
    tempData.deviceName = "Galaxy A4";
    tempData.brandName = "Samsung";
    tempData.DownloadPages = "downloading4";
    tempData.RecoveryPages = "s4";
    mapData.emplace("Galaxy A4", tempData);
    temp3 = mapData.at("Galaxy A4");
    cout << "Galaxy A4=>" << temp3.brandName << "," << temp3.DownloadPages << "," << temp3.RecoveryPages << endl;
    cout << "11.empty 判断map是否为空" << endl;
    bool isEmpty = mapData.empty();
    if(isEmpty)
        cout << "map is empty===========为空" << endl;
    else
        cout << "map is not empty======不为空" << endl;
    cout << "mapData.size()======" << mapData.size() << endl;
    cout << "12.erase 删除map中的一个元素" << endl;
    map<string, STDeviceInfo>::iterator it5 = mapData.find("Galaxy A2");
    mapData.erase(it5);
    cout << "mapData.size()======" << mapData.size() << endl;
    cout << "13.clear 清空map的元素" << endl;
    mapData.clear();
    cout << "mapData.size()======" << mapData.size() << endl;
    time_t startTime;
    time(&startTime);  //获取当前时间get current time; same as: now = time(NULL)
    //sleep(3);
    for(int i = 0; i < 100000; ++i)
    {
        STDeviceInfo tempData;
        string str = to_string(i);
        tempData.deviceName = str;
        tempData.brandName = str;
        tempData.DownloadPages = str;
        tempData.RecoveryPages = str;
        mapData.insert(pair<string, STDeviceInfo>(str, tempData));
    }
    time_t endTime;
    time(&endTime); //结束时间
    double runTime = difftime(endTime, startTime);
    cout << "insert   runTime=======" << runTime << "\tmapData.size()===" << mapData.size() << endl;
    //==============================================================================
    time_t startTime1;
    time(&startTime1);  //获取当前时间get current time; same as: now = time(NULL)
    for(int i = 100000; i < 200000; ++i)
    {
        STDeviceInfo tempData;
        string str = to_string(i);
        tempData.deviceName = str;
        tempData.brandName = str;
        tempData.DownloadPages = str;
        tempData.RecoveryPages = str;
        mapData.emplace(str, tempData);
    }
    time_t endTime1;
    time(&endTime1); //结束时间
    double runTime1 = difftime(endTime1, startTime1);
    cout << "emplace  runTime1======" << runTime1 << "\tmapData.size()===" << mapData.size() << endl;
    cout << "14.max_size()       返回可以容纳的最大元素个数" << endl;
    cout << "mapData.max_size() ==========" << mapData.max_size() << endl;
    cout << "15.lower_bound(key) 返回比key小或等于的元素的第一个位置的迭找器" << endl;
    map<string, STDeviceInfo>::iterator itlow, itup;
    itlow = mapData.lower_bound("3");
    STDeviceInfo temp5 = itlow->second;
    cout << itlow->first << "=>" << temp5.brandName << "," << temp5.DownloadPages << "," << temp5.RecoveryPages << endl;
    cout << "16.upper_bound(key) 返回比key大的元素的第一个位置的迭找器" << endl;
    itup = mapData.upper_bound("1999998");
    temp5 = itup->second;
    cout << itup->first << "=>" << temp5.brandName << "," << temp5.DownloadPages << "," << temp5.RecoveryPages << endl;
    cout << "mapData.size()======" << mapData.size() << endl;
    //mapData.erase(itlow, itup);  //erase[itlow, itup)
    //mapData.erase(itlow);
    //mapData.erase(itup);
    mapData.clear();
    bool isEmpty2 = mapData.empty();
    if(isEmpty2)
        cout << "map is empty===========为空" << endl;
    else
        cout << "map is not empty======不为空" << endl;

    for(int i = 10; i < 20; ++i)
    {
        STDeviceInfo tempData;
        string str = to_string(i);
        tempData.deviceName = str;
        tempData.brandName = str;
        tempData.DownloadPages = str;
        tempData.RecoveryPages = str;
        mapData.emplace(str, tempData);
    }

    map<string, STDeviceInfo> mapData2;
    for(int i = 82; i < 95; ++i)
    {
        STDeviceInfo tempData;
        string str = to_string(i);
        tempData.deviceName = str;
        tempData.brandName = str;
        tempData.DownloadPages = str;
        tempData.RecoveryPages = str;
        mapData2.emplace(str, tempData);
    }
    cout << "mapData.print" << endl;
    for(map<string, STDeviceInfo>::iterator it = mapData.begin(); it != mapData.end(); ++it)
    {
        STDeviceInfo temp6 = it->second;
        cout << it->first << "=>" << temp6.brandName << "," << temp6.DownloadPages << "," << temp6.RecoveryPages << endl;
    }
    cout << "mapData2.print" << endl;
    for(map<string, STDeviceInfo>::iterator it = mapData2.begin(); it != mapData2.end(); ++it)
    {
        STDeviceInfo temp7 = it->second;
        cout << it->first << "=>" << temp7.brandName << "," << temp7.DownloadPages << "," << temp7.RecoveryPages << endl;
    }
    cout << "17.swap()交换两个map的元素" << endl;
    swap(mapData, mapData2);
    cout << "swap()====mapData.print" << endl;
    for(map<string, STDeviceInfo>::iterator it = mapData.begin(); it != mapData.end(); ++it)
    {
        STDeviceInfo temp6 = it->second;
        cout << it->first << "=>" << temp6.brandName << "," << temp6.DownloadPages << "," << temp6.RecoveryPages << endl;
    }
    cout << "swap()====mapData2.print" << endl;
    for(map<string, STDeviceInfo>::iterator it = mapData2.begin(); it != mapData2.end(); ++it)
    {
        STDeviceInfo temp7 = it->second;
        cout << it->first << "=>" << temp7.brandName << "," << temp7.DownloadPages << "," << temp7.RecoveryPages << endl;
    }
    return 0;
}





