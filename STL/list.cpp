#include <iostream>
#include <list>


/*
using namespace std;

bool removeCondition(const int &n)
{
    return (n == 30);
}

int main()
{
    //创建空的list
    list<int> list1;
    list1.assign(5, 100);
    cout << "1.assign给列表赋值" << endl;
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;

    cout << "list1.back()===" << list1.back() << endl;
    list1.back() = 98;

    list1.front() = 12;
    cout << "2.back()返回最后一个元素的引用, 3.front()返回第一个元素的引用,可以通过引用改变元素的值" << endl;
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;

    cout << "4.begin()返回指向第一个元素的迭代器，可以通过迭代器修改元素的值" << endl;
    list<int>::iterator it = list1.begin();
    cout << "*it==org===" << *it << endl;
    *it = 22;
    cout << "*it==new===" << *it << endl;

    cout << "5.end()返回返回最后一个元素下一个位置的迭代器，用来判断列表是否结束" << endl;
    list<int>::iterator it2 = list1.end();
    int nCount = 0;
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        ++nCount;
        cout << "nCount===" << nCount << "*it========" << *it << endl;
    }
    cout << "nCount===" << nCount << "*it2========" << *it2 << endl;

    cout << "6.size()返回list元素的个数, 7.empty()判断list是否为空" << endl;
    bool isEmpty = list1.empty();
    if(isEmpty)
        cout << "list1.size()=" << list1.size() << "\tlist1 is empty：链表为空" << endl;
    else
        cout << "list1.size()=" << list1.size() << "\tlist1 is not empty：链表不为空" << endl;

    cout << "8.clear()删除所有元素" << endl;
    list1.clear();
    bool isEmpty2 = list1.empty();
    if(isEmpty2)
        cout << "list1.size()=" << list1.size() << "\tlist1 is empty：链表为空" << endl;
    else
        cout << "list1.size()=" << list1.size() << "\tlist1 is not empty：链表不为空" << endl;

    cout << "9.max_size()返回list能容纳的最大元素数量" << endl;
    cout << "list1.max_size()====" << list1.max_size() << endl;
    cout << "10.push_back()在list尾部添加一个元素，11.push_front()在list首部添加一个元素" << endl;
    list1.push_back(20);
    list1.push_back(70);
    list1.push_front(50);
    list1.push_front(80);
    list1.push_back(60);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << "list1.size()===" << list1.size() << endl;
    cout << "12.pop_back()在list尾部删除一个元素，13.pop_front()在list首部删除一个元素" << endl;
    list1.pop_back();
    list1.pop_front();
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << "list1.size()===" << list1.size() << endl;
    cout << "14.rbegin()逆向迭代器，返回最一个一元素的前一个位置，即end() -1的位置" << endl;
    cout << "15.rend()返回第一个元素的前一个位置，即begin() - 1的位置" << endl;
    for(list<int>::reverse_iterator it = list1.rbegin(); it != list1.rend(); ++it)
    {
        cout << *it << ",";
    }
    cout << "16.reverse()链表倒置" << endl;
    list1.reverse();
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "17.insert()插入元素到链表中" << endl;
    list<int>::iterator itBegin = list1.begin();
    list1.insert(itBegin, 20);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    list<int>::iterator itEnd = list1.end();
    list1.insert(itEnd, 5, 30);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "18.remove(x)删除链表中的数据，如果链表中有多个相同的数据，不起删除" << endl;
    list1.remove(20);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    //70,50,30,30,30,30,30
    cout << endl;
    list1.remove_if(removeCondition);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << "list1.size()===" << list1.size() << endl;
    cout << "19.resize(x)改变链表大小" << endl;
    list1.resize(5);
    cout << "list1.size()===" << list1.size() << endl;
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    list<int> list2;
    for(int i = 1; i < 6; ++i)
    {
        list2.push_back(i * 2);
    }
    for(list<int>::iterator it = list2.begin(); it != list2.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "20.merge()合并两个list, 将list2合并到list1的前面，合并后，list2清空" << endl;
    list1.merge(list2);

    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    for(list<int>::iterator it = list2.begin(); it != list2.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << "list1.size()===" << list1.size() << "list2.size()===" << list2.size() << endl;
    list<int> list3;
    for(int i = 1; i < 6; ++i)
    {
        list3.push_back(i * 3);
    }
    for(list<int>::iterator it = list3.begin(); it != list3.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "21.splice()将list3插入到list1,需要指定位置,完成后，list3清空" << endl;
    list<int>::iterator itend = list1.end();
    list1.splice(itend, list3);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    for(list<int>::iterator it = list3.begin(); it != list3.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "list1.size()===" << list1.size() << "list3.size()===" << list3.size() << endl;
    cout << "22.sort()将list1排序，默认是升序方式" << endl;
    list1.sort();
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "23.unique()删除list中相邻重的元素" << endl;
    list1.unique();
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "list1.size()===" << list1.size() << "list3.size()===" << list3.size() << endl;
    cout << "24.swap()交换两个list" << endl;
    list<int> list4;
    for(int i = 0; i < 6; ++i)
    {
        list4.push_back(i * 4);
    }
    for(list<int>::iterator it = list4.begin(); it != list4.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "list1.size()===" << list1.size() << "list4.size()===" << list4.size() << endl;
    list1.swap(list4);
    for(list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    for(list<int>::iterator it = list4.begin(); it != list4.end(); ++it)
    {
        cout << *it << ",";
    }
    cout << endl;
    cout << "list1.size()===" << list1.size() << "list4.size()===" << list4.size() << endl;

    return 0;
}
*/
