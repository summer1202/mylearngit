// exp5.cpp : 定义控制台应用程序的入口点。
//
//第五题：替换空格
/*请实现一个函数，把字符串中的每个空格均替换为%20，例如：输入“we are happy.” 输出：“we%20are%20happy.”
*************
解题思路：
将替换后的字符串长度算出来，之后留两个指针，一个指向替换前的字符串末端j，一个指向替换后的字符串末端k，之后一次从右向左复制字符，遇到空格填充%20，并将k向前移动两位，以此类推，
直到j和k相等为止。
该思路的时间复杂度为o(n),且所有的字符只需移动一次
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
void replaceblank(char string[], int length){
	int newlength = length;
	if (string == nullptr&&length <= 0){
		return;//提前返回，不执行之后的语句
	}
	else{
		for (int i = 0; i <= length; i++){
			if (string[i] == ' '){
				newlength = newlength + 2;
			}
		}
		if (newlength == length){
			return;//如果没有空格符，什么也不做
		}
	}
	//算出最终的字符串长度并开始替换
	int j = length;
	for (int k = newlength; k>j; k--){
		if (string[j] != ' '){
			string[k] = string[j];//依次向后移动
			j--;
		}
		else{
			string[k] = '0';
			string[k - 1] = '2';
			string[k - 2] = '%';
			k = k - 2;
			j--;

		}
		
	}
	//cout << string << endl;
	

}
int main(int argc, _TCHAR* argv[])
{
	char a[100];
	string b = " we are happy. ";
	strcpy(a, " we are happy. ");
	replaceblank(a, b.length());
	cout<<a<<endl;
	return 0;
}

