#include <iostream>
#include <string>
using namespace std;
class ZipCode
{
public:
	ZipCode(void)
	{}
	ZipCode(int z)
	{
		zip=z;
	}
	ZipCode(string code1)
	{
		code=code1;
	}
	void output_zip_main(ostream& ou)
	{
		int t_zip = zip/10000;
		if((t_zip>=1)||(zip<10))
		{
			ou<<zip;
		}
		else
		{
			cout<<"error 3";
			exit(3);
		}
	}
	void output_code_main(ostream& ou)
	{
		ou<<code;
	}
	void output_code_zip(ostream& ou)
	{
		change_code_2_zip();
		ou<<zip;
	}
	string get_code();

private:
	int zip;
	string code;
	void change_code_2_zip();//内部换算
};
void ZipCode::change_code_2_zip()
{
	int c_l = code.length();
	if(((c_l-2)%5) !=0)
	{
		cout<<"error 1";
		exit(1);
	}
	if ((code[0] !='1')||(code[code.length()-1] != '1'))
	{
		cout<<"error 2";
		exit(2);
	}
	//解密
	int length1=5;//解密长度
	int password[] = { 7, 4, 2, 1, 0 };//解密代码
	int f_zip=0;
	for (int a = 0; a < length1; a++)//切断 分5份
	{
		int code_2_zip_no=0;
		for (int b = 0; b < length1;b++)//5个数字分段
		{
			char tt1 = code[a * 5 + b + 1];
			if (tt1 == '1')
			{
				code_2_zip_no += password[b];//0无意义
				//cout<<"test "<<code_2_zip_no<<"\n";
			}
			else if (tt1 != '0')
			{
				cout<<"error 3";
				exit(3);
			}
		}
	
		if (code_2_zip_no == 11)//改变格式
		{
			code_2_zip_no = 0;
		}
		f_zip = (f_zip * 10) + code_2_zip_no;
	}

	zip=f_zip;
}
string ZipCode::get_code()
{
	string postent[] ={"11000", "00011", "00101", "00110", "01001","01010", "01100", "10001", "10010", "10100" };//0-9用code代表

	string code;
	//zip to code
	int zip_[6];
	zip_[0]=zip;
	zip_[1]=zip_[0]/10000;
	zip_[0]=zip_[0]-zip_[1]*10000;

	zip_[2]=zip_[0]/1000;
	zip_[0]=zip_[0]-zip_[2]*1000;

	zip_[3]=zip_[0]/100;
	zip_[0]=zip_[0]-zip_[3]*100;

	zip_[4]=zip_[0]/10;
	zip_[0]=zip_[0]-zip_[4]*10;

	zip_[5]=zip_[0];
	for (int i=5;i>0;i--)
	{
		code=postent[zip_[i]]+code;
	}
	
	return "1"+code+"1";
}

int main()
{
	//test 1
	ZipCode zip1(99504);
	zip1.output_zip_main(cout);
	cout<< " bar code is ";
	cout<<zip1.get_code();
	cout<<"\n";
	//test2
	ZipCode zip2("101001010011001011000010101");//44805
	zip2.output_code_zip(cout);
	cout<< " bar code is ";
	zip2.output_code_main(cout);
	//error test
	int zip_code =1;
	//0 for code, 1 for zip
	if(zip_code)
	{
	ZipCode zip1(1234);
	zip1.output_zip_main(cout);
	cout<< " bar code is ";
	cout<<zip1.get_code();
	cout<<"\n";
	}
	else
	{
		ZipCode zip2("001001010011001011000010101");//error
		zip2.output_code_zip(cout);
		cout<< " bar code is ";
		zip2.output_code_main(cout);
	}


	return 0;
}