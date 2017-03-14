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

		//最大差异列表
		float Table_diff[6] = { 0, 0, 0, 0, 0, 0 };

		//购买状态列表(是/否)
		bool Table_isbuying[6] = { false, false, false, false, false, false, };
		//购买状态等级
		int Table_buyingLevel[6] = { 0, 0, 0, 0, 0, 0, };
		//各数字下注累计
		int Table_buyingNum[6] = { 0, 0, 0, 0, 0, 0 };
		//营收统计点
		int Num_get = 0;
		
		//定义所有随机数据
		for (int i = 0; i < _count; i++)
		{
			/*
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = int(_random(0, 6)) + 1;
			}
			*/

			int _cur[3];
			//定义当前条目
			for (int j = 0; j < 3; j++){
				_cur[j] = int(_random(0, 6)) + 1;
			}
			//条目加入
			for (int j = 0; j < 3; j++){
				AllTable[i][j] = _cur[j];
			}

			//计算当前各个数字回归？并且得出最大差异
			float _result[6] = { 0, 0, 0, 0, 0, 0 };
			for (int k = 0; k < i + 1; k++)
			{
				if (AllTable[k][0] == AllTable[k][1] && AllTable[k][1] == AllTable[k][2]){
					//三个相同,相应数字加2.5
					_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 2.5;
				}
				else{

					if (AllTable[k][0] == AllTable[k][1]){
						//2个相同,相应数字加1.5		(0,1)
						_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 1.5;
						_result[AllTable[k][2] - 1] = _result[AllTable[k][2] - 1] + 0.5;
					}
					else{
						if (AllTable[k][1] == AllTable[k][2]){
							//2个相同,相应数字加1.5		(1,2)
							_result[AllTable[k][1] - 1] = _result[AllTable[k][1] - 1] + 1.5;
							_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 0.5;
						}
						else{
							if (AllTable[k][0] == AllTable[k][2]){
								//2个相同,相应数字加1.5		(0,2)
								_result[AllTable[k][0] - 1] = _result[AllTable[k][0] - 1] + 1.5;
								_result[AllTable[k][1] - 1] = _result[AllTable[k][1] - 1] + 0.5;
							}
							else{
								//各自互不相同
								for (int j = 0; j < 3; j++){
									_result[AllTable[k][j] - 1] = _result[AllTable[k][j] - 1] + 0.5;
								}
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

				for (int j = 0; j < 6; j++){
					float _maxdif = fabs(_result[j]);
					if (_maxdif > fabs(Table_diff[j])){
						Table_diff[j] = _result[j];
							cout << _result[j] << "...点数为" << j+1 << endl;
					}
				}
			}
			//----------------------------------------------------
			for (int j = 0; j < 6; j++){
				if (Table_isbuying[j] == true){
					if (_result[j] > (Table_buyingLevel[j] - 1) * (-3) - 1.5){
						//获得一次赢利点
						Num_get = Num_get + 1;
						Table_buyingLevel[j] = Table_buyingLevel[j] - 1;
						if (Table_buyingLevel[j] = 0){
							//等级一的话 停止购买
							Table_isbuying[j] = false;
						}
					}
					else{
						//检查是否加深
						if (_result[j] < Table_buyingLevel[j] * (-3)){
							Table_buyingLevel[j] = Table_buyingLevel[j] + 1;
						}
					}
				}
				else{
					if (_result[j] < (-3)){
						Table_isbuying[j] = true;
						Table_buyingLevel[j] = floor(Table_isbuying[j] / 3);
					}
				}
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
			cout << "输入1获取各个数字回归\n输入2为获取各个数字出现次数\n输入3获取最大差异\n输入4获取盈利点数\n输入0清屏重来" << endl;
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
				case 3:
					////////////////////////////////////////////
					cout << "获取各个数字最大差异" << endl;
					for (int i = 0; i < 6; i++){
						cout << i + 1 << "*******" << Table_diff[i] << endl;
					}
					break; // 可选的
				case 4:
					////////////////////////////////////////////
					cout << "盈利点数为:" << Num_get << endl;
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