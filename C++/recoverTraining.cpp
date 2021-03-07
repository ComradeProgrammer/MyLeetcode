//我真是受够这种事情了。今天要刷题，我开始刷leetcode，看之前先学一遍STL
//下一次再刷，再学一遍STL
//所以在这里放个恢复训练指南啥的
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>
#include <sstream>
using namespace std;
class Fuck{
    public:
        Fuck(int a);
        int data;
        bool operator<(const Fuck& o2)const;
        
};
Fuck::Fuck(int a){
    this->data=a;
}
//自定义比较函数：重载运算符
bool Fuck::operator<(const Fuck& o2)const{
    return this->data <o2.data;
}
//vector
void vectorTraining(){
    //create(C)
    vector<int>arr(5);
    arr={0,1,2,3};

    //retirve(R)
    //size
    cout<<"size:"<<int(arr.size())<<endl;
    //支持操作符 []
    for(int i=0;i<int(arr.size());i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //迭代器 用begin()和end()
    vector<int>::iterator itr;
    for(itr=arr.begin();itr!=arr.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    //UPDATE (U) & DELETE(D)
    //push_back and pop_back
    arr.push_back(4);
    cout<<arr[4]<<endl;
    arr.pop_back();
    cout<<arr.size()<<endl;

    //迭代器是可以加减的
    //insert and erase
    arr.insert(arr.begin(),-5);//在某个元素前面插入
    arr.erase(arr.begin(),arr.begin()+1);//删除，左闭右开

    arr.clear();//全删了

    // trick: 2维数组 3*4
    vector<vector<int>>m(3,vector<int>(4));
    return;
}

void listTraining(){
    list<int>l={1,2,3};
    //back and front
    cout<<l.back();
    cout<<l.front()<<endl;
    //push_back and push_front
    l.push_back(4);
    l.push_front(0);
    list<int>::iterator itr;
    //pop_back and pop_from
    l.pop_back();
    l.pop_front(); 
    l.insert(++l.begin(),5);
    for(itr=l.begin();itr!=l.end();itr++){
        cout<<*itr<<" ";
    }
    l.erase(++l.begin());
    for(itr=l.begin();itr!=l.end();itr++){
        cout<<*itr<<" ";
    }

    cout<<endl;
}

void unorderedMapTraining(){
    unordered_map<int,int>m={{1,101},{2,102},{3,103}};//列表初始化
    //插入
    m[4]=104;
    //遍历
    for(auto i=m.begin();i!=m.end();i++){
        cout<<"{"<<i->first<<":"<<i->second<<"} ";
    }
    //查询
    if(m.find(5)!=m.end()){
        cout<<m[5];
    }
    cout<<endl;
    //删除
    m.erase(m.find(4));
    for(auto i=m.begin();i!=m.end();i++){
        cout<<"{"<<i->first<<":"<<i->second<<"} ";
    }
}
void priorityQueueTraining(){
    priority_queue<Fuck> q;
    q.push(Fuck(3));
    q.push(Fuck(5));
    q.push(Fuck(1));
    while(q.size()>0){
        cout<<q.top().data<<" ";
        q.pop();
    }

    //讲道理可以自定义比较函数的，但是太麻烦了。
    //如果只是想变小顶堆可以这样
    priority_queue<int,vector<int>,greater<int>> q2;
    q2.push(1);
    q2.push(6);
    q2.push(-4);
    while(q2.size()>0){
        cout<<q2.top()<<" ";
        q2.pop();
    }
    //这里的greater<int>是一个伪函数(c++里面就是重载()运算符)
    //我们也可以自己写一个
    struct cmp{
        bool operator()(const int& a,const int& b){
            return a>=b;
        };
    };

    priority_queue<int,vector<int>,cmp> q3;
    q3.push(1);
    q3.push(6);
    q3.push(-4);
    while(q3.size()>0){
        cout<<q3.top()<<" ";
        q3.pop();
    }

}
void sortTraining(){
    vector<int>arr{1,4,7,8,5,2,3,6,9,0};
    sort(arr.begin(),arr.end());
    for(auto i:arr){
        cout<<i<<" ";
    }
}
void stringTraining(){
    string tmp("hello world");
    cout<<tmp<<endl;
    //与C 数组的转换
    //c_str直接返回底层数组
    char* ptr=(char*)(tmp.c_str());//最好不这样做 
    *ptr='e';
    cout<<ptr<<endl;
    cout<<tmp<<endl;
    //这个data()不用强转，但是也是底层数组
    char* ptr2=tmp.data();
    *ptr2='d';
    cout<<ptr2<<endl;
    cout<<tmp<<endl;

    //查找子串
    string a("helloworld");
    string b("llo");
    if(a.find(b)!=string::npos){
        cout<<(a.find(b));
    }
    cout<<endl;

    //取子串 参数是 开始位置，长度
    cout<<a.substr(2,3)<<endl;
    //添加子串  插在指定位置那个字符之前
    a.insert(5,",");
    cout<<a<<endl;

    //数字转字符串
    cout<<to_string(0x10)<<endl;
    cout<<stoi(string("555"));
    //其他的几个叫 stol(long) stoll (long) stoul (unsigned long) stof(float) stof(double)

    //sstream
    stringstream ss;
    ss<<171;
    cout<<ss.str();

}
int main(){
    ///vectorTraining();
    //listTraining();
    //unorderedMapTraining();
    //priorityQueueTraining();
    //sortTraining();
    stringTraining();
    return 0;
}