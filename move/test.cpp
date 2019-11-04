/*
 *遗留问题：如main函数中的注释，为什么这样的方式不引起move语义呢？
 *
 */

#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::endl;

class MyString{
	public:
		explicit MyString(size_t length): _length(length), _data(new char[length]){
			cout<<"Construtor called"<<endl;	
		}

		~MyString(){
			if(_data != NULL){
				delete []_data;
			}
			cout<<"Destrutor called"<<endl;	
		}

		MyString(const MyString &other): _length(other._length), _data(new char[other._length]){
			std::copy(other._data, other._data + _length, _data);
			cout<<"Copy construtor called"<<endl;	
		}

		MyString(MyString &&other): _length(0), _data(nullptr){
			cout<<"Move construtor called"<<endl;	
			_data = other._data;
			_length = other._length;
			other._data = nullptr;
			other._length = 0;
		}
		size_t _length;
		char *_data;
};

int main(){
	MyString a(10);
//	MyString && c = std::move(a);
	MyString b(std::move(a));

	cout<<a._length<<endl;

	MyString && d = MyString(10);
	MyString e(std::move(MyString(10)));

	return 0;
}