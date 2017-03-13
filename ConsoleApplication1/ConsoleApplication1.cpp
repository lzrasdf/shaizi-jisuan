// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int _count;		//条目数量
	double _random(double, double);
	srand(unsigned(time(0)));
	for (;true;)
	{ 

		cout << "请输入数据条目数" << endl;
		cin >> _count;

		//新建总数据表
		int **AllTable;
		AllTable = new int*[_count];
		for (int i = 0; i < _count; i++)
		{
			AllTable[i] = new int[3];
		}
		
		//定义所有随机数据
		for (int i = 0; i < _count; i++)
		{
			/*
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
			*/
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
		}
		cout << "----------下方输出数据-------------" << endl;
		//输出数据
		for (int i = 0; i < _count; i++)
		{
			cout << AllTable[i][0] << '\t' << AllTable[i][1] << '\t' << AllTable[i][2] << endl;
		}
		cout << "----------------------------------" << endl;

		//判断方法
		for (; true;){
			int _do;
			cout << "输入1获取各个数字回归\n输入2为获取各个数字出现次数\n输入0清屏重来" << endl;
			cin >> _do;

			if (_do == 0)
			{
				break;
			}
			float _result[6] = { 0, 0, 0, 0, 0, 0 };
			switch (_do)
			{
				case 1:
					///////////////////////////////////////////
					cout << "获取各个数字回归" << endl;
					for (int i = 0; i < _count; i++)
					{
						if (AllTable[i][0] == AllTable[i][1] && AllTable[i][1] == AllTable[i][2]){
							//三个相同,相应数字加2.5
							_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 2.5;
							//cout << "三个相同,相应数字加2.5" << endl;
						}
						else{
							
							if (AllTable[i][0] == AllTable[i][1]){
								//2个相同,相应数字加1.5		(0,1)
								_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 1.5;
								_result[AllTable[i][2] - 1] = _result[AllTable[i][2] - 1] + 0.5;
								//cout << "2个相同,相应数字加1.5" << endl;
							}
							else{
								if (AllTable[i][1] == AllTable[i][2]){
									//2个相同,相应数字加1.5		(1,2)
									_result[AllTable[i][1] - 1] = _result[AllTable[i][1] - 1] + 1.5;
									_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 0.5;
									//cout << "2个相同,相应数字加1.5" << endl;
								}
								else{
									if (AllTable[i][0] == AllTable[i][2]){
										//2个相同,相应数字加1.5		(0,2)
										_result[AllTable[i][0] - 1] = _result[AllTable[i][0] - 1] + 1.5;
										_result[AllTable[i][1] - 1] = _result[AllTable[i][1] - 1] + 0.5;
										//cout << "2个相同,相应数字加1.5" << endl;
									}
									else{
										//各自互不相同
										for (int j = 0; j < 3; j++){
											_result[AllTable[i][j] - 1] = _result[AllTable[i][j] - 1] + 0.5;
										}
										//cout << "各自互不相同" << endl;
									}
								}
								
							}

							
						}

						for (int j = 0; j < 6; j++){
							bool _need = true;//默认要减少0.5
							for (int k = 0; k < 3; k++){
								if (AllTable[i][k] == j + 1){
									_need = false;
									break;
								}
							}
							if (_need == true){
								_result[j] = _result[j] - 0.5;
							}
						}
					}
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << _result[i] << endl;
					}
					break; // 可选的
				case 2:
					////////////////////////////////////////////
					cout << "获取各个数字出现次数" << endl;
					for (int i = 0; i < _count; i++)
					{
						for (int j = 0; j < 3; j++){
							_result[AllTable[i][j] - 1] = _result[AllTable[i][j] - 1] + 1;
						}
					}
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << _result[i] << endl;
					}
					break; // 可选的
				default:
					break;
			}
		}


		/*
		清空
		*/
		system("cls");
		continue;
	}

	return 0;
}

double _random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

int mathfunc(int **AllTable){
	return 0;
}