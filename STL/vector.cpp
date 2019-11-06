#include <iostream>
#include <vector>

using namespace std;

//https://blog.csdn.net/u010183728/article/details/81913729

/*
int main()
{
    vector<int> vec;//创建一个向量存储容器，类型为int
    cout << "1:push_back(i)在数组最后添加数据" << endl;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);//1:push_back(i)在数组最后添加数据
        cout << vec[i] << ",";
    }

    cout << endl;
    cout << "2:pop_back()删除最后一个元素" << endl;
    for(int i = 0; i < 5; ++i)
    {
        vec.pop_back();//2:pop_back()删除最后一个元素
    }
    cout << endl;
    cout << "3.at(i) 得到编号位置的数据" << endl;
    for(int i = 0; i < 5; ++i)
    {
        cout << vec.at(i) << ","; //3.at(i) 得到编号位置的数据
    }

    cout << endl;
    vector<int>::iterator beginIter = vec.begin();//4.begin 得到数组头的指针
    cout << "4.begin 得到数组头的指针" << endl;
    cout << "*begin=======" << *beginIter << endl;
    cout << "5.end 得到数组的最后一个单元+1的指针" << endl;
    //5.end 得到数组的最后一个单元+1的指针
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << ",";
    }
    //6．front 得到数组头的引用
    cout << "6．front 得到数组头的引用" << endl;
    cout << "vec.front()=======" << vec.front() << endl;
    //7.back 得到数组的最后一个单元的引用
    cout << "7.back 得到数组的最后一个单元的引用" << endl;
    cout << "vec.back()=======" << vec.back() << endl;
    //8.max_size 得到vector最大可以是多大
    cout << "8.max_size 得到vector最大可以是多大" << endl;
    cout << "vec.max_size()=======" << vec.max_size() << endl;
    //9.capacity 当前vector分配的大小
    cout << "9.capacity 当前vector分配的大小" << endl;
    cout << "vec.capacity()=======" << vec.capacity() << endl;
    //10.size 当前使用数据的个数
    cout << "10.size 当前使用数据的个数" << endl;
    cout << "vec.size()=======" << vec.size() << endl;
    //11.resize 改变当前使用数据的大小,即size()的大小，如果它比当前使用的大，则填充默认值
    vec.resize(6);//之前vec.capacity()为16
    cout << "11.resize 改变当前使用数据的大小,即size()的大小 vec.size()=" << vec.size() << "   vec.capacity()=" << vec.capacity() << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << ",";
    }
    cout << endl;
    vec.resize(7, 100);//改变当前使用数据的大小,如果它比当前使用的大，则100填充默认值
    cout << "resize 改变当前使用数据的大小,即size()的大小 vec.size()=";
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << ",";
    }
    cout << "\nvec.size()=" << vec.size() << "\tvec.capacity()=" << vec.capacity() << endl;
    //12.reserve 改变当前vecotr所分配空间的大小,之前为16
    vec.reserve(8);
    cout << "12.reserve改变当前vecotr所分配空间的大小vec.capacity()=" << vec.capacity() << endl;
    //13.erase 删除指针指向的数据项,
    vec.erase(vec.begin()+5);//删除第5个元素
    vec.erase(vec.begin(), vec.begin() + 2);//删除第1个元素到第三个元素
    cout << "13.erase 删除指针指向的数据项，不会对capacity产生影响" << endl;
    cout << "\nvec.size()=" << vec.size() << "\tvec.capacity()=" << vec.capacity() << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << ",";
    }
    cout << endl;
    //14.clear 清空当前的vector，size的大小为0, 但是capacity大小不改变，因此它的值可能为原值
    cout << "14.clear 清空当前的vector，size的大小为0, 但是capacity大小不改变"<< endl;
    vec.clear();
    cout << "\nvec.size()=" << vec.size() << "\tvec.capacity()=" << vec.capacity() << endl;
    //18.empty 判断vector是否为空
    if(vec.empty())
    {
        cout << "vec is empty=============" << endl;
    }
    else
    {
        cout << "vec is not empty=============" << endl;
    }
    vector<int>::iterator beginIt = vec.begin();
    cout << "*begintIt==" << *beginIt << endl;
    for(int i = 0; i < 16; ++i)
    {
        cout << *beginIt++ << ",";
    }
    cout << endl;
    //assign
    vec.assign(5, 20);//填充值，第一个参数是填充个数，第二个参数是值
    vector<int>::iterator beginIt2 = vec.begin();
    for(int i = 0; i < 16; ++i)
    {
        cout << *beginIt2++ << ",";
    }
    cout << "\nvec.size()=" << vec.size() << "\tvec.capacity()=" << vec.capacity() << endl;
    //15.insert向vector插入元素
    vector<int>::iterator beginIt3 = vec.begin();
    cout << "*beginIt3================" << *beginIt3 << endl;
    for(int i = 0; i < 8; ++i)
    {
        vec.insert(beginIt3, i * 3);
    }
    cout << "15.insert向vector插入元素" << endl;
    for(int i = 0; i < 16; ++i)
    {
        cout << *beginIt3++ << ",";
    }
    cout << "\nvec.size()=" << vec.size() << "\tvec.capacity()=" << vec.capacity() << endl;

    //16.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)
    cout << "16.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)" << endl;
    vector<int>::reverse_iterator rbeginIt = vec.rbegin();
    cout << "*rbeginIt==1=" << *rbeginIt << endl;
    //17.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)
    cout << "17.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)" << endl;
    vector<int>::reverse_iterator rendIt = vec.rend();
    for(; rbeginIt != vec.rend(); ++rbeginIt)
    {
        cout << *rbeginIt << ',';
    }
    cout << endl;


    //19.swap 与另一个vector交换数据
    vector<int> vec2 = {10, 20, 30};
    for(int i = 0; i < vec2.size(); ++i)
    {
        cout << vec2.at(i) << ",";
    }
    cout << endl;
    cout << "19.swap 与另一个vector交换数据" << endl;
    vec.swap(vec2);
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << ",";
    }
    cout << endl;
    for(int i = 0; i < vec2.size(); ++i)
    {
        cout << vec2.at(i) << ",";
    }
    cout << "\nHello World!" << endl;


    return 0;
}

*/
